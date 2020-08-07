#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>

#ifdef WIN32
#include <windows.h>
#include <ntstatus.h>
#include <bcrypt.h>
#else
#include <unistd.h>
#include <fcntl.h>
#endif

#include "execute.h"

#include "jv_alloc.h"
#include "jq_parser.h"
#include "locfile.h"
#include "parser.h"
#include "builtin.h"
#include "util.h"
#include "linker.h"

#include "jq_io.h"
#include "jq_io_builtin.h"
#include "jq_io_co.h"


static inline enum bt_priority bt_desc_prio(uint32_t desc_val) {
  union bt_descriptor desc = {.value=desc_val};
  return desc.fields.prio;
}

static inline uint32_t bt_desc_tag(uint32_t desc_val) {
  union bt_descriptor desc = {.value=desc_val};
  return desc.fields.tag;
}

static inline uint32_t bt_desc_make(enum bt_priority prio, uint32_t tag) {
  union bt_descriptor desc = {.fields={tag, prio}};
  return desc.value;
}

#define BT_DESC(tag)                bt_desc_make(BT_PRIO_SIGNAL, tag)
#define BT_DESC_SOFT(soft_tag)      bt_desc_make(BT_PRIO_SIGNAL, BT_SOFT_TAG(soft_tag))

#define BT_DESC_NEXT_VALUE          BT_DESC(BACKTRACK_0)
#define BT_DESC_ERROR               BT_DESC(RAISE)

#define BT_DESC_FRAME_PC(level, offset)   bt_desc_make(BT_PRIO_SIGNAL, BT_TAG_FRAME_PC(level, offset))
#define BT_DESC_PROTECT                   bt_desc_make(BT_PRIO_PROTECT, 0)
#define BT_DESC_TERMINATE                 bt_desc_make(BT_PRIO_TERMINATE, 0)
#define BT_DESC_ALWAYS                    bt_desc_make(BT_PRIO_ALWAYS, 0)

static int frame_size(struct bytecode* bc) {
  return sizeof(struct frame) + sizeof(union frame_entry) * (bc->nclosures + bc->nlocals);
}

static struct frame* frame_current(struct jq_state* jq) {
  struct frame* fp = stack_block(&jq->stk, jq->curr_frame);

  stack_ptr next = *stack_block_next(&jq->stk, jq->curr_frame);
  if (next) {
    struct frame* fpnext = stack_block(&jq->stk, next);
    struct bytecode* bc = fpnext->bc;
    assert(fp->retaddr >= bc->code && fp->retaddr < bc->code + bc->codelen);
  } else {
    assert(fp->retaddr == 0);
  }
  return fp;
}

static stack_ptr frame_get_level(struct jq_state* jq, int level) {
  stack_ptr fr = jq->curr_frame;
  for (int i=0; i<level; i++) {
    struct frame* fp = stack_block(&jq->stk, fr);
    fr = fp->env;
  }
  return fr;
}

static jv* frame_local_var(struct jq_state* jq, int var, int level) {
  struct frame* fr = stack_block(&jq->stk, frame_get_level(jq, level));
  assert(var >= 0);
  assert(var < fr->bc->nlocals);
  return &fr->entries[fr->bc->nclosures + var].localvar;
}

static struct closure make_closure(struct jq_state* jq, uint16_t* pc) {
  uint16_t level = *pc++;
  uint16_t idx = *pc++;
  stack_ptr fridx = frame_get_level(jq, level);
  struct frame* fr = stack_block(&jq->stk, fridx);
  if (idx & ARG_NEWCLOSURE) {
    // A new closure closing the frame identified by level, and with
    // the bytecode body of the idx'th subfunction of that frame
    int subfn_idx = idx & ~ARG_NEWCLOSURE;
    assert(subfn_idx < fr->bc->nsubfunctions);
    struct closure cl = {fr->bc->subfunctions[subfn_idx],
                         fridx};
    return cl;
  } else {
    // A reference to a closure from the frame identified by level; copy
    // it as-is
    int closure = idx;
    assert(closure >= 0);
    assert(closure < fr->bc->nclosures);
    return fr->entries[closure].closure;
  }
}

static struct frame* frame_push(struct jq_state* jq, struct closure callee,
                                uint16_t* argdef, int nargs) {
  stack_ptr new_frame_idx = stack_push_block(&jq->stk, jq->curr_frame, frame_size(callee.bc));
  struct frame* new_frame = stack_block(&jq->stk, new_frame_idx);
  new_frame->bc = callee.bc;
  new_frame->env = callee.env;
  assert(nargs == new_frame->bc->nclosures);
  union frame_entry* entries = new_frame->entries;
  for (int i=0; i<nargs; i++) {
    entries->closure = make_closure(jq, argdef + i * 2);
    entries++;
  }
  for (int i=0; i<callee.bc->nlocals; i++) {
    entries->localvar = jv_invalid();
    entries++;
  }
  jq->curr_frame = new_frame_idx;
  return new_frame;
}

static void frame_pop(struct jq_state* jq) {
  assert(jq->curr_frame);
  struct frame* fp = frame_current(jq);
  if (stack_pop_will_free(&jq->stk, jq->curr_frame)) {
    int nlocals = fp->bc->nlocals;
    for (int i=0; i<nlocals; i++) {
      jv_free(*frame_local_var(jq, i, 0));
    }
  }
  jq->curr_frame = stack_pop_block(&jq->stk, jq->curr_frame, frame_size(fp->bc));
}

void stack_push(jq_state *jq, jv val) {
  assert(jv_is_valid(val));
  jq->stk_top = stack_push_block(&jq->stk, jq->stk_top, sizeof(jv));
  jv* sval = stack_block(&jq->stk, jq->stk_top);
  *sval = val;
}

jv stack_pop(jq_state *jq) {
  jv* sval = stack_block(&jq->stk, jq->stk_top);
  jv val = *sval;
  if (!stack_pop_will_free(&jq->stk, jq->stk_top)) {
    val = jv_copy(val);
  }
  jq->stk_top = stack_pop_block(&jq->stk, jq->stk_top, sizeof(jv));
  assert(jv_is_valid(val));
  return val;
}

// Like stack_pop(), but assert !stack_pop_will_free() and replace with
// jv_null() on the stack.
jv stack_popn(jq_state *jq) {
  jv* sval = stack_block(&jq->stk, jq->stk_top);
  jv val = *sval;
  if (!stack_pop_will_free(&jq->stk, jq->stk_top)) {
    *sval = jv_null();
  }
  jq->stk_top = stack_pop_block(&jq->stk, jq->stk_top, sizeof(jv));
  assert(jv_is_valid(val));
  return val;
}


struct forkpoint {
  stack_ptr saved_data_stack;
  stack_ptr saved_curr_frame;
  int path_len, subexp_nest;
  jv value_at_path;
  uint16_t* return_address;
  uint32_t bt_desc;
};

struct stack_pos {
  stack_ptr saved_data_stack, saved_curr_frame;
};

struct stack_pos stack_get_pos(jq_state* jq) {
  struct stack_pos sp = {jq->stk_top, jq->curr_frame};
  return sp;
}

void stack_save(jq_state *jq, uint32_t bt_desc, uint16_t* retaddr, struct stack_pos sp){
  jq->fork_top = stack_push_block(&jq->stk, jq->fork_top, sizeof(struct forkpoint));
  struct forkpoint* fork = stack_block(&jq->stk, jq->fork_top);
  fork->saved_data_stack = jq->stk_top;
  fork->saved_curr_frame = jq->curr_frame;
  fork->path_len =
    jv_get_kind(jq->path) == JV_KIND_ARRAY ? jv_array_length(jv_copy(jq->path)) : 0;
  fork->value_at_path = jv_copy(jq->value_at_path);
  fork->subexp_nest = jq->subexp_nest;
  fork->return_address = retaddr;
  fork->bt_desc = bt_desc;
  jq->stk_top = sp.saved_data_stack;
  jq->curr_frame = sp.saved_curr_frame;
}

static int path_intact(jq_state *jq, jv curr) {
  if (jq->subexp_nest == 0 && jv_get_kind(jq->path) == JV_KIND_ARRAY) {
    return jv_identical(curr, jv_copy(jq->value_at_path));
  } else {
    jv_free(curr);
    return 1;
  }
}

static void path_append(jq_state* jq, jv component, jv value_at_path) {
  if (jq->subexp_nest == 0 && jv_get_kind(jq->path) == JV_KIND_ARRAY) {
    int n1 = jv_array_length(jv_copy(jq->path));
    jq->path = jv_array_append(jq->path, component);
    int n2 = jv_array_length(jv_copy(jq->path));
    assert(n2 == n1 + 1);
    jv_free(jq->value_at_path);
    jq->value_at_path = value_at_path;
  } else {
    jv_free(component);
    jv_free(value_at_path);
  }
}

static void copy_callbacks(jq_state *src, jq_state *dst) {
  dst->err_cb = src->err_cb;
  dst->err_cb_data = src->err_cb_data;
  dst->input_cb = src->input_cb;
  dst->input_cb_data = src->input_cb_data;
  dst->debug_cb = src->debug_cb;
  dst->debug_cb_data = src->debug_cb_data;
}

/* For f_getpath() */
jv _jq_path_append(jq_state *jq, jv v, jv p, jv value_at_path) {
  if (jq->subexp_nest != 0 ||
      jv_get_kind(jq->path) != JV_KIND_ARRAY ||
      !jv_is_valid(value_at_path)) {
    jv_free(v);
    jv_free(p);
    return value_at_path;
  }
  if (!jv_identical(v, jv_copy(jq->value_at_path))) {
    jv_free(p);
    return value_at_path;
  }
  if (jv_get_kind(p) == JV_KIND_ARRAY)
    jq->path = jv_array_concat(jq->path, p);
  else
    jq->path = jv_array_append(jq->path, p);
  jv_free(jq->value_at_path);
  return jv_copy(jq->value_at_path = value_at_path);
}

static void jq_reset_bt(jq_state *jq, uint32_t bt_desc) {
  jq->bt.desc = bt_desc;
  jv_free(jq->bt.payload);
  jq->bt.payload = jv_invalid();
  jq->bt.ttl = 0;
}

uint16_t* stack_restore(jq_state *jq){

  assert(bt_desc_prio(jq->bt.desc) > BT_PRIO_NONE && "stack_restore called when not backtracking");

  // figure out the target pc, if applicable
  int frame_level = BT_TAG_GET_PC_FRAME(bt_desc_tag(jq->bt.desc));
  uint16_t* target_pc = 0;

  if (frame_level >= 0) {
    // this is a PC
    struct frame* fr = stack_block(&jq->stk, frame_get_level(jq, frame_level));
    target_pc = fr->bc->code + BT_TAG_GET_PC_OFFSET(bt_desc_tag(jq->bt.desc));
  }

  // search for a matching forkpoint
  while (jq->stk.limit < jq->restore_limit) {
    while (jq->stk.limit < jq->restore_limit && !stack_pop_will_free(&jq->stk, jq->fork_top)) {
      if (stack_pop_will_free(&jq->stk, jq->stk_top)) {
        jv_free(stack_pop(jq));
      } else if (stack_pop_will_free(&jq->stk, jq->curr_frame)) {
        frame_pop(jq);
      } else {
        assert(0);
      }
    }

    if (jq->fork_top == 0 || jq->stk.limit >= jq->restore_limit) {
      return 0;
    }

    struct forkpoint* fork = stack_block(&jq->stk, jq->fork_top);
    uint16_t* retaddr = fork->return_address;
    jq->stk_top = fork->saved_data_stack;
    jq->curr_frame = fork->saved_curr_frame;
    int path_len = fork->path_len;
    if (jv_get_kind(jq->path) == JV_KIND_ARRAY) {
      assert(path_len >= 0);
      jq->path = jv_array_slice(jq->path, 0, path_len);
    } else {
      fork->path_len = 0;
    }
    jv_free(jq->value_at_path);
    jq->value_at_path = fork->value_at_path;
    jq->subexp_nest = fork->subexp_nest;
    jq->fork_top = stack_pop_block(&jq->stk, jq->fork_top, sizeof(struct forkpoint));

    // now determine if this forkpoint is mathing the request

    if (bt_desc_prio(jq->bt.desc) == bt_desc_prio(fork->bt_desc)) {
      // this is the matching priority
      // check for a matching tag for SIGNAL priority

      // resolve the advertised forkpoint pc
      frame_level = BT_TAG_GET_PC_FRAME(bt_desc_tag(fork->bt_desc));
      uint16_t* match_pc = 0;
      if (frame_level >= 0) {
        struct frame* fr = stack_block(&jq->stk, frame_get_level(jq, frame_level));
        match_pc = fr->bc->code + BT_TAG_GET_PC_OFFSET(bt_desc_tag(fork->bt_desc));
      }

      int full_match = (jq->bt.desc == fork->bt_desc) 
                       || (bt_desc_prio(jq->bt.desc) > BT_PRIO_SIGNAL)
                       || ((frame_level >= 0) && (target_pc == match_pc));

      if (full_match) {
        // this is a matching forkpoint, respect the TTL
        if (jq->bt.ttl > 0) {
          jq->bt.ttl--;
        } else {
          return retaddr;
        }
      }
    }
    else if(bt_desc_prio(jq->bt.desc) < bt_desc_prio(fork->bt_desc)){
      // the forkpoint priority is higher than the backtracking request
      // stop here disregarding the TTL
      return retaddr;
    }
  }
  return 0;
}

static void jq_reset(jq_state *jq) {
  jq_reset_bt(jq, bt_desc_make(BT_PRIO_TERMINATE, 0));

  while (stack_restore(jq)) {}

  assert(jq->parent || jq->stk_top == 0);
  assert(jq->parent || jq->fork_top == 0);
  assert(jq->parent || jq->curr_frame == 0);
  if (!jq->parent)
    stack_reset(&jq->stk, 0);
  jq_reset_bt(jq, 0);
  jq->halted = 0;
  jq->finished = 0;
  jv_free(jq->exit_code);
  jv_free(jq->error_message);
  jq->exit_code = jv_invalid();
  jq->error_message = jv_invalid();

  if (jv_get_kind(jq->path) != JV_KIND_INVALID)
    jv_free(jq->path);

  jq->path = jv_null();
  jv_free(jq->value_at_path);
  jq->value_at_path = jv_null();
  jq->subexp_nest = 0;
  jv_free(jq->start_input);
  jq->start_input = jv_invalid();
}

void jq_report_error(jq_state *jq, jv value) {
  assert(jq->err_cb);
  // callback must jv_free() its jv argument
  jq->err_cb(jq->err_cb_data, value);
}

static void set_error(jq_state *jq, jv value) {
  jq_reset_bt(jq, BT_DESC_ERROR);
  jq->bt.payload = value;
}

#define ON_BACKTRACK(op) ((op)+NUM_OPCODES)

static void co_err_cb(void *, jv);

jv jq_next(jq_state *jq) {
  jv cfunc_input[MAX_CFUNCTION_ARGS];

  jv_nomem_handler(jq->nomem_handler, jq->nomem_handler_data);

  if (jq->halted) {
    if (jq->debug_flags & JQ_DEBUG_TRACE)
      printf("\t<halted>\n");
    return jv_invalid();
  }

  if (jq->finished) {
    if (jq->debug_flags & JQ_DEBUG_TRACE)
      printf("\t<finished>\n");
    return jv_invalid();
  }

  jq_reset_bt(jq, BT_DESC_NEXT_VALUE);

  uint16_t* pc = stack_restore(jq);
  assert(pc);

  assert(jq->parent == 0 || jq->restore_limit >= jq->stk.limit);
  while (1) {
    if (jq->halted) {
      if (jq->debug_flags & JQ_DEBUG_TRACE)
        printf("\t<halted>\n");
      return jv_invalid();
    }
    uint16_t opcode = *pc;

    if (jq->debug_flags & JQ_DEBUG_TRACE) {
      dump_operation(frame_current(jq)->bc, pc);
      const struct opcode_description* opdesc = opcode_describe(opcode);
      stack_ptr param = 0;
      if (!jq->bt.desc) {
        int stack_in = opdesc->stack_in;
        if (stack_in == -1) stack_in = pc[1];
        param = jq->stk_top;


        printf("\t");

        if(stack_in) {
          printf("(( ");
        }
        for (int i=0; i<stack_in; i++) {
          if (i != 0) {
            printf(" | ");
            param = *stack_block_next(&jq->stk, param);
          }
          if (!param) break;
          jv_dump(jv_copy(*(jv*)stack_block(&jq->stk, param)), (jq->debug_flags & JQ_DEBUG_REFCNT) ? JV_PRINT_REFCOUNT : 0);
          //printf("<%d>", jv_get_refcnt(param->val));
          //printf(" -- ");
          //jv_dump(jv_copy(jq->path), 0);
        }
        if(stack_in) {
          printf(" )) ");
        } else {
          printf(" ");
        }

        if (jq->debug_flags & JQ_DEBUG_TRACE_DETAIL && param < jq->restore_limit) {
          int first = 1;
          if(stack_in == 0) {
            // we haven't printed the top of the stack yet, print now
            jv_dump(jv_copy(*(jv*)stack_block(&jq->stk, param)), (jq->debug_flags & JQ_DEBUG_REFCNT) ? JV_PRINT_REFCOUNT : 0);
          }
          while ((param = *stack_block_next(&jq->stk, param))) {
            if (!first || !stack_in) {
              printf(" || ");
            } else {
              first = 0;
            }
            jv_dump(jv_copy(*(jv*)stack_block(&jq->stk, param)), (jq->debug_flags & JQ_DEBUG_REFCNT) ? JV_PRINT_REFCOUNT : 0);
          }
        }
      } else {
        const char* prio_name[] = {
          "BT_PRIO_NONE",
          "BT_PRIO_SIGNAL",
          "BT_PRIO_PROTECT",
          "BT_PRIO_TERMINATE"
        };

        assert(bt_desc_prio(jq->bt.desc) < (sizeof(prio_name) / sizeof(*prio_name)) && "Unknown backtrack priority");
        printf("\t[^] %s", prio_name[bt_desc_prio(jq->bt.desc)]);
        if (bt_desc_prio(jq->bt.desc) == BT_PRIO_SIGNAL) {
          uint32_t tag = bt_desc_tag(jq->bt.desc);
          if (BT_TAG_IS_OPCODE(tag)) {
            printf(", op: %s", opcode_describe(tag)->name);
          }
          else if (BT_TAG_IS_HARD(tag)) {
            printf(", tag: %d", tag);
          } 
          else if (BT_TAG_IS_SOFT(tag)) {
            printf(", soft tag: %d", BT_TAG_GET_SOFT(tag));
          } 
          else {
            // this is a frame offset
            printf(", frame: %d, pc: %04d", (int)((bt_desc_tag(jq->bt.desc) - BT_TAG_PC_START) >> 16), (int)(bt_desc_tag(jq->bt.desc)&0xffff));
          }
        }  
        if (jv_is_valid(jq->bt.payload)) {
          printf(", payload: ");
          jv_dump(jv_copy(jq->bt.payload), JV_PRINT_REFCOUNT);
        }      
      }

      if (jq->parent)
        printf("\t (CHILD %p of %p)", jq, jq->parent);

      printf("\n");
    }

    if (jq->bt.desc != 0) {
      opcode = ON_BACKTRACK(opcode);
    }
    pc++;

    switch (opcode) {
    default: assert(0 && "invalid instruction");
    case LOADK: {
      jv v = jv_array_get(jv_copy(frame_current(jq)->bc->constants), *pc++);
      assert(jv_is_valid(v));
      jv_free(stack_pop(jq));
      stack_push(jq, v);
      break;
    }

    case DUP: {
      jv v = stack_pop(jq);
      stack_push(jq, jv_copy(v));
      stack_push(jq, v);
      break;
    }

    case DUPN: {
      jv v = stack_popn(jq);
      stack_push(jq, jv_copy(v));
      stack_push(jq, v);
      break;
    }

    case DUP2: {
      jv keep = stack_pop(jq);
      jv v = stack_pop(jq);
      stack_push(jq, jv_copy(v));
      stack_push(jq, keep);
      stack_push(jq, v);
      break;
    }

    case SUBEXP_BEGIN: {
      jv v = stack_pop(jq);
      stack_push(jq, jv_copy(v));
      stack_push(jq, v);
      jq->subexp_nest++;
      break;
    }

    case SUBEXP_END: {
      assert(jq->subexp_nest > 0);
      jq->subexp_nest--;
      jv a = stack_pop(jq);
      jv b = stack_pop(jq);
      stack_push(jq, a);
      stack_push(jq, b);
      break;
    }

    case PUSHK_UNDER: {
      jv v = jv_array_get(jv_copy(frame_current(jq)->bc->constants), *pc++);
      assert(jv_is_valid(v));
      jv v2 = stack_pop(jq);
      stack_push(jq, v);
      stack_push(jq, v2);
      break;
    }

    case POP: {
      jv_free(stack_pop(jq));
      break;
    }

    case APPEND: {
      jv v = stack_pop(jq);
      uint16_t level = *pc++;
      uint16_t vidx = *pc++;
      jv* var = frame_local_var(jq, vidx, level);
      assert(jv_get_kind(*var) == JV_KIND_ARRAY);
      *var = jv_array_append(*var, v);
      break;
    }

    case INSERT: {
      jv stktop = stack_pop(jq);
      jv v = stack_pop(jq);
      jv k = stack_pop(jq);
      jv objv = stack_pop(jq);
      assert(jv_get_kind(objv) == JV_KIND_OBJECT);
      if (jv_get_kind(k) == JV_KIND_STRING) {
        stack_push(jq, jv_object_set(objv, k, v));
        stack_push(jq, stktop);
      } else {
        char errbuf[15];
        set_error(jq, jv_string_fmt("Cannot use %s (%s) as object key",
                                    jv_kind_name(jv_get_kind(k)),
                                    jv_dump_string_trunc(jv_copy(k), errbuf, sizeof(errbuf))));
        jv_free(stktop);
        jv_free(v);
        jv_free(k);
        jv_free(objv);
        goto do_backtrack;
      }
      break;
    }

    case ON_BACKTRACK(RANGE):
    case RANGE: {
      uint16_t level = *pc++;
      uint16_t v = *pc++;
      jv* var = frame_local_var(jq, v, level);
      jv max = stack_pop(jq);

      if (jv_get_kind(*var) != JV_KIND_NUMBER ||
          jv_get_kind(max) != JV_KIND_NUMBER) {
        set_error(jq, jv_string_fmt("Range bounds must be numeric"));
        jv_free(max);
        goto do_backtrack;
      } else if (jv_number_value(*var) >= jv_number_value(max)) {
        /* finished iterating */
        jv_free(max);
        jq_reset_bt(jq, BT_DESC_NEXT_VALUE);
        goto do_backtrack;
      } else {
        jv curr = *var;
        *var = jv_number(jv_number_value(*var) + 1);

        struct stack_pos spos = stack_get_pos(jq);
        stack_push(jq, max);
        stack_save(jq, BT_DESC_NEXT_VALUE,  pc - 3, spos);

        stack_push(jq, curr);
      }
      break;
    }

      // FIXME: loadv/storev may do too much copying/freeing
    case LOADV:
      // Does a load but replaces the variable with null
    case LOADVN: {
      uint16_t level = *pc++;
      uint16_t v = *pc++;
      jv* var = frame_local_var(jq, v, level);
      if (jq->debug_flags & JQ_DEBUG_TRACE) {
        printf("V%d = ", v);
        jv_dump(jv_copy(*var), 0);
        if (jq->debug_flags & JQ_DEBUG_REFCNT) {
          printf("<%d>\n", jv_get_refcnt(*var));
        } else {
          printf("\n");
        }
      }
      jv_free(stack_pop(jq));
      stack_push(jq, jv_copy(*var));
      if (opcode == LOADVN) {
        jv_free(*var);
        *var = jv_null();
      }
      break;
    }

    case STOREV: {
      uint16_t level = *pc++;  
      uint16_t v = *pc++;

      jv* var = frame_local_var(jq, v, level);
      jv_free(*var);

      jv val = stack_pop(jq);
      if (jq->debug_flags & JQ_DEBUG_TRACE) {
        printf("V%d = ", v);
        jv_dump(jv_copy(val), 0);
        if (jq->debug_flags & JQ_DEBUG_REFCNT) {
          printf("<%d>\n", jv_get_refcnt(val));
        } else {
          printf("\n");
        }
      }
      *var = val;
      break;
    }

    case STORE_PC: {
      uint16_t* my_pc = pc-1;
      uint16_t pc_offset = my_pc - frame_current(jq)->bc->code;

      jv val = stack_pop(jq);
      uint16_t level = *pc++;
      uint16_t v = *pc++;

      assert(level == 0 && "STORE_PC must define a fresh variable");

      stack_save(jq, BT_DESC_FRAME_PC(0, pc_offset),  my_pc, stack_get_pos(jq));
      stack_push(jq, val);

      jv* var = frame_local_var(jq, v, level);
      jv_free(*var);
      *var = jv_number(pc_offset);

      if (jq->debug_flags & JQ_DEBUG_TRACE) {
        printf("V(pc)%d = ", v);
        jv_dump(jv_copy(*var), 0);
        printf("\n");
      }
      break;
    }

    case ON_BACKTRACK(STORE_PC): 
      // this is my signal
      // lower the priority of backtracking to data and continue backtracking
      jq->bt.desc = BT_DESC_NEXT_VALUE;
      goto do_backtrack;

    case BACKTRACK_PC: {
      jv_free(stack_pop(jq));

      uint16_t level = *pc++;
      uint16_t v = *pc++;
      jv* var = frame_local_var(jq, v, level);

      int offset = (int)jv_number_value(jv_copy(*var));

      if (jq->debug_flags & JQ_DEBUG_TRACE) {
        printf("V(pc)%d = ", v);
        jv_dump(jv_copy(*var), 0);
        printf("\n");
      }

      jq_reset_bt(jq, BT_DESC_FRAME_PC(level, offset));

      goto do_backtrack;
    }

    case STORE_GLOBAL: {
      // Get the constant
      jv val = jv_array_get(jv_copy(frame_current(jq)->bc->constants), *pc++);
      assert(jv_is_valid(val));

      // Store the var
      uint16_t level = *pc++;
      uint16_t v = *pc++;
      jv* var = frame_local_var(jq, v, level);
      jv_free(*var);
      if (jq->debug_flags & JQ_DEBUG_TRACE) {
        printf("V%d = ", v);
        jv_dump(jv_copy(val), 0);
        if (jq->debug_flags & JQ_DEBUG_REFCNT) {
          printf("<%d>\n", jv_get_refcnt(val));
        } else {
          printf("\n");
        }
      }
      *var = val;
      break;
    }

    case PATH_BEGIN: {
      jv v = stack_pop(jq);
      stack_push(jq, jq->path);

      stack_save(jq, BT_DESC_NEXT_VALUE,  pc - 1, stack_get_pos(jq));

      stack_push(jq, jv_number(jq->subexp_nest));
      stack_push(jq, jq->value_at_path);
      stack_push(jq, jv_copy(v));

      jq->path = jv_array();
      jq->value_at_path = v; // next INDEX operation must index into v
      jq->subexp_nest = 0;
      break;
    }

    case PATH_END: {
      jv v = stack_pop(jq);
      // detect invalid path expression like path(.a | reverse)
      if (!path_intact(jq, jv_copy(v))) {
        char errbuf[30];
        jv msg = jv_string_fmt(
            "Invalid path expression with result %s",
            jv_dump_string_trunc(v, errbuf, sizeof(errbuf)));
        set_error(jq, msg);
        goto do_backtrack;
      }
      jv_free(v); // discard value, only keep path

      jv old_value_at_path = stack_pop(jq);
      int old_subexp_nest = (int)jv_number_value(stack_pop(jq));

      jv path = jq->path;
      jq->path = stack_pop(jq);

      struct stack_pos spos = stack_get_pos(jq);
      stack_push(jq, jv_copy(path));
      stack_save(jq, BT_DESC_NEXT_VALUE,  pc - 1, spos);

      stack_push(jq, path);
      jq->subexp_nest = old_subexp_nest;
      jv_free(jq->value_at_path);
      jq->value_at_path = old_value_at_path;
      break;
    }

    case ON_BACKTRACK(PATH_BEGIN):
    case ON_BACKTRACK(PATH_END): {
      jv_free(jq->path);
      jq->path = stack_pop(jq);
      goto do_backtrack;
    }

    case INDEX:
    case INDEX_OPT: {
      jv t = stack_pop(jq);
      jv k = stack_pop(jq);
      // detect invalid path expression like path(reverse | .a)
      if (!path_intact(jq, jv_copy(t))) {
        char keybuf[15];
        char objbuf[30];
        jv msg = jv_string_fmt(
            "Invalid path expression near attempt to access element %s of %s",
            jv_dump_string_trunc(k, keybuf, sizeof(keybuf)),
            jv_dump_string_trunc(t, objbuf, sizeof(objbuf)));
        set_error(jq, msg);
        goto do_backtrack;
      }
      jv v = jv_get(t, jv_copy(k));
      if (jv_is_valid(v)) {
        path_append(jq, k, jv_copy(v));
        stack_push(jq, v);
      } else {
        jv_free(k);
        if (opcode == INDEX)
          set_error(jq, jv_invalid_get_msg(v));
        else {
          jv_free(v);
          jq_reset_bt(jq, BT_DESC_NEXT_VALUE);
        }
        goto do_backtrack;
      }
      break;
    }


    case JUMP: {
      uint16_t offset = *pc++;
      pc += offset;
      break;
    }

    case JUMP_F: {
      uint16_t offset = *pc++;
      jv t = stack_pop(jq);
      jv_kind kind = jv_get_kind(t);
      if (kind == JV_KIND_FALSE || kind == JV_KIND_NULL) {
        pc += offset;
      }
      stack_push(jq, t); // FIXME do this better
      break;
    }

    case EACH:
      /* fallthru */
    case EACH_OPT: {
      jv container = stack_pop(jq);
      // detect invalid path expression like path(reverse | .[])
      if (!path_intact(jq, jv_copy(container))) {
        char errbuf[30];
        jv msg = jv_string_fmt(
            "Invalid path expression near attempt to iterate through %s",
            jv_dump_string_trunc(container, errbuf, sizeof(errbuf)));
        set_error(jq, msg);
        goto do_backtrack;
      }
      stack_push(jq, container);
      stack_push(jq, jv_number(-1));
    }
    /* fallthru */
    case ON_BACKTRACK(EACH):
    case ON_BACKTRACK(EACH_OPT): {
      int idx = jv_number_value(stack_pop(jq));
      jv container = stack_pop(jq);

      int keep_going, is_last = 0;
      jv key, value;
      if (jv_get_kind(container) == JV_KIND_ARRAY) {
        if (opcode == EACH || opcode == EACH_OPT) idx = 0;
        else idx = idx + 1;
        int len = jv_array_length(jv_copy(container));
        keep_going = idx < len;
        is_last = idx == len - 1;
        if (keep_going) {
          key = jv_number(idx);
          value = jv_array_get(jv_copy(container), idx);
        }
      } else if (jv_get_kind(container) == JV_KIND_OBJECT) {
        if (opcode == EACH || opcode == EACH_OPT) idx = jv_object_iter(container);
        else idx = jv_object_iter_next(container, idx);
        keep_going = jv_object_iter_valid(container, idx);
        if (keep_going) {
          key = jv_object_iter_key(container, idx);
          value = jv_object_iter_value(container, idx);
        }
      } else {
        assert(opcode == EACH || opcode == EACH_OPT);
        if (opcode == EACH) {
          char errbuf[15];
          set_error(jq,
                    jv_invalid_with_msg(jv_string_fmt("Cannot iterate over %s (%s)",
                                                      jv_kind_name(jv_get_kind(container)),
                                                      jv_dump_string_trunc(jv_copy(container), errbuf, sizeof(errbuf)))));
        }
        keep_going = 0;
      }

      if (!keep_going) {
        if (keep_going)
          jv_free(value);
        jv_free(container);
        jq_reset_bt(jq, BT_DESC_NEXT_VALUE);
        goto do_backtrack;
      } else if (is_last) {
        // we don't need to make a backtrack point
        jv_free(container);
        path_append(jq, key, jv_copy(value));
        stack_push(jq, value);
      } else {
        struct stack_pos spos = stack_get_pos(jq);
        stack_push(jq, container);
        stack_push(jq, jv_number(idx));
        stack_save(jq, BT_DESC_NEXT_VALUE,  pc - 1, spos);
        path_append(jq, key, jv_copy(value));
        stack_push(jq, value);
      }
      break;
    }
    case BACKTRACK_N: {

      jq_reset_bt(jq, BT_DESC_NEXT_VALUE);

      jv n = jv_array_get(jv_copy(frame_current(jq)->bc->constants), *pc++);

      if(jv_get_kind(n) == JV_KIND_NUMBER) {
        jq->bt.ttl = (uint32_t)jv_number_value(jv_copy(n));
      } 
      else if (jv_get_kind(n) != JV_KIND_NULL) { // null is equivalent to 0
        jq_reset_bt(jq, BT_DESC_ERROR);
        jq->bt.payload = jv_string("argument to break should be a number");
      }

      jv_free(n);

      goto do_backtrack;
    }

    case BACKTRACK_0:
      jq_reset_bt(jq, BT_DESC_NEXT_VALUE);

    do_backtrack:
      assert(jq->bt.desc > 0 && "Invalid backtracking descriptor");
      pc = stack_restore(jq);
      if (!pc) {
        // shouldn't be getting here
        // since START should intercept all backtracks 
        assert( 0 && "START should intercept all backtracks" );
      }
      // avoid reaching the bottom of the loop
      // because the backtracking is reset there;
      continue;

    case RAISE:
      set_error(jq, stack_pop(jq));
      goto do_backtrack;

    case TRY_BEGIN: {
      uint16_t* my_pc = pc-1;
      uint16_t offset = *pc++;
      uint16_t* handler_pc = pc+offset;
      uint16_t handler_offset = handler_pc - frame_current(jq)->bc->code;

      // save a forkpoint with a tag equal to the handler pc
      // this forkpoint will fire when TRY_END signals us
      stack_save(jq, BT_DESC_FRAME_PC(0, handler_offset),  my_pc, stack_get_pos(jq));

      // save another forkpoint with the ERROR tag
      // this will fire when the protected code raises an error
      stack_save(jq, BT_DESC_ERROR,  my_pc, stack_get_pos(jq));

      // neither of the forkpoints above will fire on data backtrack
      break;
    }

    case TRY_END:
      // install an error forkpoint so that we can signal about it 
      // to the TRY_BEGIN handler for a re-rise
      stack_save(jq, BT_DESC_ERROR,  pc - 1, stack_get_pos(jq));

      // jump past the handler to the rest of the code
      uint16_t offset = *pc++;
      pc += offset;
      break;

    case ON_BACKTRACK(TRY_BEGIN): {
      uint16_t offset = *pc++;
      uint16_t* handler_pc = pc+offset;
      uint16_t handler_offset = handler_pc - frame_current(jq)->bc->code;

      if (jq->bt.desc != BT_DESC_ERROR) {
        // we were signalled by TRY_END about and exception
        // which happend after the protected block
        // we should change the tag to ERROR and proceed
        assert((jq->bt.desc == BT_DESC_FRAME_PC(0, handler_offset)) && "Unexpected backtrack");
        jq->bt.desc = BT_DESC_ERROR;
        goto do_backtrack;
      }
      /*
       * Else we caught an error from the protected block, so we jump to
       * the handler.
       *
       * See commentary in gen_try().
       */

      jv_free(stack_pop(jq)); // free the input
      stack_push(jq, jv_copy(jq->bt.payload));  // push the error
      jq_reset_bt(jq, 0);
      pc += offset;
      break;
    }
    case ON_BACKTRACK(TRY_END): {
      assert(jq->bt.desc == BT_DESC_ERROR && "Unexpected backtrack");
      pc++;  // unused offset

      // Signal the error to the matching TRY_BEGIN
      // TRY_BEGIN will be awaiting a tag equal to the PC of the first
      // instruction of the handler. This is the next instruction
      jq->bt.desc = BT_DESC_FRAME_PC(0, pc - frame_current(jq)->bc->code);

      goto do_backtrack;
    }

    case FORK: {
      stack_save(jq, BT_DESC_NEXT_VALUE,  pc - 1, stack_get_pos(jq));
      pc++; // skip offset this time
      break;
    }

    case ON_BACKTRACK(DESTRUCTURE_BEGIN):
      assert(jq->bt.desc == BT_DESC_ERROR && "Unexpected backtrack (DESTRUCTURE_BEGIN)");
      // fallthrough
    case DESTRUCTURE_BEGIN: {
      // see gen_destructure() in compile.c

      uint16_t *my_pc = pc-1;
      uint16_t level = *pc++;
      uint16_t var = *pc++;

      // on a backtrack alt_ix will hold the index of the next matcher
      jv* alt_ix_var = frame_local_var(jq, var, level);
      int alt_ix = 0;

      if (opcode == ON_BACKTRACK(DESTRUCTURE_BEGIN)) {
        assert(jv_is_valid(*alt_ix_var));
        alt_ix = jv_number_value(*alt_ix_var);
      }      
        
      *alt_ix_var = jv_number(alt_ix + 1);
      
      // nullify all locals up until the alt_ix_var index
      for (int v = 0; v < var; v++) {
        jv* local = frame_local_var(jq, v, level);
        jv_free(*local);
        *local = jv_null();
      }

      // figure out if we are about to run the final matcher alternative
      // this will be the case if our jump entry is immediately before the first matcher

      const int len_of_jump = 2; // the length of the jump instruction
      uint16_t first_matcher_offset = (*(pc+1)) + len_of_jump /*the first jump entry*/;
      uint16_t jump_offset = (len_of_jump * alt_ix);
      int is_final_matcher = (jump_offset + len_of_jump) == first_matcher_offset;

      if (!is_final_matcher) {
        stack_save(jq, BT_DESC_ERROR,  my_pc, stack_get_pos(jq));
      }

      // discard error, if any
      jq_reset_bt(jq, 0);

      // move to the next matcher via the jump table
      // TODO: this can be optimized, but now it's fun to debug
      pc += jump_offset;

      break;
    }

    case ON_BACKTRACK(FORK): {
      uint16_t offset = *pc++;
      pc += offset;
      break;
    }

    case CALL_BUILTIN: {
      int nargs = *pc++;
      jv top = stack_pop(jq);
      jv* in = cfunc_input;
      in[0] = top;
      for (int i = 1; i < nargs; i++) {
        in[i] = stack_pop(jq);
      }
      struct cfunction* function = &frame_current(jq)->bc->globals->cfunctions[*pc++];
      typedef jv (*func_1)(jq_state*,jv);
      typedef jv (*func_2)(jq_state*,jv,jv);
      typedef jv (*func_3)(jq_state*,jv,jv,jv);
      typedef jv (*func_4)(jq_state*,jv,jv,jv,jv);
      typedef jv (*func_5)(jq_state*,jv,jv,jv,jv,jv);
      switch (function->nargs) {
      case 1: top = ((func_1)function->fptr)(jq, in[0]); break;
      case 2: top = ((func_2)function->fptr)(jq, in[0], in[1]); break;
      case 3: top = ((func_3)function->fptr)(jq, in[0], in[1], in[2]); break;
      case 4: top = ((func_4)function->fptr)(jq, in[0], in[1], in[2], in[3]); break;
      case 5: top = ((func_5)function->fptr)(jq, in[0], in[1], in[2], in[3], in[4]); break;
      // FIXME: a) up to 7 arguments (input + 6), b) should assert
      // because the compiler should not generate this error.
      default: return jv_invalid_with_msg(jv_string("Function takes too many arguments"));
      }

      if (jv_is_valid(top)) {
        stack_push(jq, top);
      } else if (jv_invalid_has_msg(jv_copy(top))) {
        set_error(jq, jv_invalid_get_msg(top));
        goto do_backtrack;
      } else {
        // C-coded function returns invalid w/o msg? -> backtrack, as if
        // it had returned `empty`
        jq_reset_bt(jq, BT_DESC_NEXT_VALUE);
        goto do_backtrack;
      }
      break;
    }

    case TAIL_CALL_JQ:
    case CALL_JQ: {
      /*
       * Bytecode layout here:
       *
       *  CALL_JQ
       *  <nclosures>                       (i.e., number of call arguments)
       *  <callee closure>                  (what we're calling)
       *  <nclosures' worth of closures>    (frame reference + code pointer)
       *
       *  <next instruction (to return to)>
       *
       * Each closure consists of two uint16_t values: a "level"
       * identifying the frame to be closed over, and an index.
       *
       * The level is a relative number of call frames reachable from
       * the currently one; 0 -> current frame, 1 -> previous frame, and
       * so on.
       *
       * The index is either an index of the closed frame's subfunctions
       * or of the closed frame's parameter closures.  If the latter,
       * that closure will be passed, else the closed frame's pointer
       * and the subfunction's code will form the closure to be passed.
       *
       * See make_closure() for more information.
       */
      jv input = stack_pop(jq);
      uint16_t nclosures = *pc++;
      uint16_t* retaddr = pc + 2 + nclosures*2;
      stack_ptr retdata = jq->stk_top;
      struct frame* new_frame;
      struct closure cl = make_closure(jq, pc);
      if (opcode == TAIL_CALL_JQ) {
        retaddr = frame_current(jq)->retaddr;
        retdata = frame_current(jq)->retdata;
        frame_pop(jq);
      }
      new_frame = frame_push(jq, cl, pc + 2, nclosures);
      new_frame->retdata = retdata;
      new_frame->retaddr = retaddr;
      pc = new_frame->bc->code;
      stack_push(jq, input);
      break;
    }

    case PROTECT: {
      stack_push(jq, jv_null());
      stack_save(jq, BT_DESC_PROTECT,  pc - 1, stack_get_pos(jq));
      uint16_t offset = *pc++;
      // jump over the handler
      pc += offset;
      break;
    }
    case ON_BACKTRACK(PROTECT): {
      // something happened down the stream
      // we need to save this state and run the handler
      jv desc = stack_pop(jq);

      if(jv_get_kind(desc) == JV_KIND_NULL) {
        // this is the first backtrack;
        // we should save the backtrack state and run the handler

        jv raising = jq->bt.desc == BT_DESC_ERROR ? jv_true() : jv_false();
        jv error = jv_copy(jq->bt.payload);

        if(jv_is_valid(jq->bt.payload)) {
          stack_push(jq, jv_copy(jq->bt.payload));
          stack_push(jq, jv_true()); // has payload
        } else {
          stack_push(jq, jv_false()); // no payload
        }
        stack_push(jq, jv_number(jq->bt.ttl));
        stack_push(jq, jv_number(jq->bt.desc));

        jq_reset_bt(jq, 0);
        stack_save(jq, BT_DESC_PROTECT,  pc - 1, stack_get_pos(jq));

        // prepare the input for the protect handler

        jv input = jv_object();
        if(jv_get_kind(raising) == JV_KIND_TRUE) {
          jv_object_set(input, jv_string("error"), error);
        } else {
          jv_free(error);
        }
        jv_object_set(input, jv_string("raising"), raising);

        stack_push(jq, input);

        // proceed to the handler now
        break;
      }
      else {
        // this is the second backtrack
        // restore the original bt signal and move on
        assert(jv_get_kind(desc) == JV_KIND_NUMBER);

        jq_reset_bt(jq, (uint32_t)jv_number_value(desc));
        jq->bt.ttl = (uint32_t)jv_number_value(stack_pop(jq));
        jv has_payload = stack_pop(jq); 
        if (jv_get_kind(has_payload) == JV_KIND_TRUE) {
          jq->bt.payload = stack_pop(jq);
        }
        jv_free(has_payload);
        goto do_backtrack;
      }

      
      break;
    }

    case CALL_HANDLE: {

    }

    case COEXPR: {
      /* Create a child co-routine with the following code
       * The child side will start happily at the next instruction
       *
       *
       * coinit() makes a copy of the parent jq_state, but arranges for the
       * child never to stack_restore() past this point.  See jq_reset().
       *
       * This all works because we never store pointers into the stack on the
       * stack without first encoding them to be relative to the stack, and
       * because the child cannot backtrack past this point, the parent will
       * teardown the child if the parent backtracks past this point, and there
       * is no concurrent access to the stack.
       */
      jv input = stack_pop(jq);

      uint16_t body_len = *pc++;
      assert(*pc == START && "COEXPR must be followed by START");
      jv handle = jq_io_coexpr_handle_create(jq, pc, input);

      // jump over the cobody
      pc += body_len;

      stack_push(jq, handle);

      break;
    }

    case ON_BACKTRACK(START): {

      if(jq->bt.desc == BT_DESC_NEXT_VALUE ) {
        if (jv_is_valid(jq->start_input)) {
          // Let's START!
          stack_save(jq, BT_DESC_ALWAYS,  pc - 1, stack_get_pos(jq));
          stack_push(jq, jq->start_input);
          jq->start_input = jv_invalid();
        }
        else {
          // We're done 
          jq->finished = 1;
          return jv_invalid();
        }
      }
      else {
        // things aren't too good

        jq->finished = 1;

        if(jq->bt.desc == BT_DESC_ERROR) {
          // we are raising and backtracked up to here
          // this is an unhandled user error, halt and return it
          jv error = jv_invalid_with_msg(jv_copy(jq->bt.payload));
          return error;
        } 
        else {
          return jv_invalid_with_msg(
            jv_string_fmt(
              "jq VM unhandled backtrack with priority %d, tag %d", 
              bt_desc_prio(jq->bt.desc),
              bt_desc_tag(jq->bt.desc)
            )
          );
        }
      }
      break;
    }
      
    case OUTPUT: {
      jv value = stack_pop(jq);
      return value;
    }

    case INPUT: {
      jv_free(stack_pop(jq));
      jv input = jv_invalid();
      if (jq->input_cb != NULL) {
        // call the input callback 
        input = jq->input_cb(jq, jq->input_cb_data);
      }

      if (!jv_is_valid(input)) {
        // we are still invalid, should decide what to do
        int has_msg = jv_invalid_has_msg(jv_copy(input));
        if (has_msg) {
          set_error(jq, jv_invalid_get_msg(input));
        }
        else {
          jq_reset_bt(jq, BT_DESC_NEXT_VALUE);
        }

        goto do_backtrack;
      }
      stack_push(jq, input);
      break;
    }

    case COEVAL: {
      /*
       * Eval.  Setup a new jq_state to run the given program.  Treat it like a co-routine.
       */
      jv program = stack_pop(jq);
      assert(0 && "not implemented");
    }

    case RET_JQ: {
      jv value = stack_pop(jq);
      assert(jq->stk_top == frame_current(jq)->retdata);
      uint16_t* retaddr = frame_current(jq)->retaddr;

      assert(retaddr);
      
      pc = retaddr;
      frame_pop(jq);

      stack_push(jq, value);
      break;
    }
    }
  
    jq_reset_bt(jq, 0);
  }
}

jv jq_format_error(jv msg) {
  if (jv_get_kind(msg) == JV_KIND_NULL ||
      (jv_get_kind(msg) == JV_KIND_INVALID && !jv_invalid_has_msg(jv_copy(msg)))) {
    jv_free(msg);
    fprintf(stderr, "jq: error: out of memory\n");
    return jv_null();
  }

  if (jv_get_kind(msg) == JV_KIND_STRING)
    return msg;                         // expected to already be formatted

  if (jv_get_kind(msg) == JV_KIND_INVALID)
    msg = jv_invalid_get_msg(msg);

  if (jv_get_kind(msg) == JV_KIND_NULL)
    return jq_format_error(msg);        // ENOMEM

  // Invalid with msg; prefix with "jq: error: "

  if (jv_get_kind(msg) != JV_KIND_INVALID) {
    if (jv_get_kind(msg) == JV_KIND_STRING)
      return jv_string_fmt("jq: error: %s", jv_string_value(msg));

    msg = jv_dump_string(msg, JV_PRINT_INVALID);
    if (jv_get_kind(msg) == JV_KIND_STRING)
      return jv_string_fmt("jq: error: %s", jv_string_value(msg));
    return jq_format_error(jv_null());  // ENOMEM
  }

  // An invalid inside an invalid!
  return jq_format_error(jv_invalid_get_msg(msg));
}

static void init_vtable(struct jq_plugin_vtable *);

// XXX Refactor into a utility function that returns a jv and one that
// uses it and then prints that jv's string as the complete error
// message.
static void default_err_cb(void *data, jv msg) {
  msg = jq_format_error(msg);
  fprintf((FILE *)data, "%s\n", jv_string_value(msg));
  jv_free(msg);
}

static struct jq_plugin_vtable vtable;

jq_state *jq_init(void) {
  jq_state *jq;
  jq = jv_mem_alloc_unguarded(sizeof(*jq));
  if (jq == NULL)
    return NULL;

  init_vtable(&vtable);
  jq->vtable = &vtable;
  jq->bc = 0;
  jq->libs = 0;
  jq->next_label = 0;

  stack_init(&jq->stk);
  jq->parent = 0;
  jq->start_pc = 0;
  jq->restore_limit = 0;
  jq->stk_top = 0;
  jq->fork_top = 0;
  jq->curr_frame = 0;
  jq->error = jv_null();

  jq->halted = 0;
  jq->finished = 0;
  jq->exit_code = jv_invalid();
  jq->error_message = jv_invalid();

  jq->bt.desc = 0;
  jq->bt.ttl = 0;
  jq->bt.payload = jv_invalid();

  jq->err_cb = default_err_cb;
  jq->err_cb_data = stderr;

  jq->input_cb = 0;
  jq->input_cb_data = 0;

  jq->start_input = jv_invalid();

  jq->attrs = jv_object();
  jq->path = jv_null();
  jq->value_at_path = jv_null();

  jq->nomem_handler = NULL;
  jq->nomem_handler_data = NULL;
  jq->io_schemes = jq_io_init_schemes();

  jq->io_policy = NULL;
  jq->io_policy_data = jv_null();

  jq->debug_flags = 0;

  return jq;
}

void jq_set_error_cb(jq_state *jq, jq_msg_cb cb, void *data) {
  if (cb == NULL) {
    jq->err_cb = default_err_cb;
    jq->err_cb_data = stderr;
  } else {
    jq->err_cb = cb;
    jq->err_cb_data = data;
  }
}

void jq_get_error_cb(jq_state *jq, jq_msg_cb *cb, void **data) {
  *cb = jq->err_cb;
  *data = jq->err_cb_data;
}

void jq_set_nomem_handler(jq_state *jq, void (*nomem_handler)(void *), void *data) {
  jv_nomem_handler(nomem_handler, data);
  jq->nomem_handler = nomem_handler;
  jq->nomem_handler_data = data;
}

void jq_start(jq_state *jq, jv input, int flags) {
  jv_nomem_handler(jq->nomem_handler, jq->nomem_handler_data);

  jq_reset(jq);

  if (!jq->parent) {
    struct closure top = {jq->bc, -1};
    struct frame* top_frame = frame_push(jq, top, 0, 0);
    top_frame->retdata = 0;
    top_frame->retaddr = 0;
  }

  jq->debug_flags = flags;

  jq->start_input = input;
  stack_save(jq, BT_DESC_NEXT_VALUE,  jq->parent ? jq->start_pc : jq->bc->code, stack_get_pos(jq));

  jq->halted = 0;
  jq->finished = 0;
}

void jq_teardown(jq_state **jqp) {
  jq_state *jq = *jqp;
  if (jq == NULL)
    return;
  *jqp = NULL;

  jq_reset(jq);
  if (jq->parent)
    stack_reset(&jq->stk, jq->restore_limit);

  if (!jq->parent) {
    bytecode_free(jq->bc);
    libraries_free(jq->libs);
    if (jq->io_policy)
      jq_teardown(&jq->io_policy);
  }
  jv_free(jq->attrs);
  jv_free(jq->io_policy_data);
  jv_free(jq->io_schemes);

  jv_mem_free(jq);
}

static int ret_follows(uint16_t *pc) {
  if (*pc == RET_JQ)
    return 1;
  if (*pc++ != JUMP)
    return 0;
  return ret_follows(pc + *pc + 1); // FIXME, might be ironic
}

/*
 * Look for tail calls that can be optimized: tail calls with no
 * references left to the current frame.
 *
 * We're staring at this bytecode layout:
 *
 *   CALL_JQ
 *   <nclosures>
 *   <callee closure>       (2 units)
 *   <nclosures closures>   (2 units each)
 *   <next instruction>
 *
 * A closure is:
 *
 *   <level>    (a relative frame count chased via the current frame's env)
 *   <index>    (an index of a subfunction or closure in that frame)
 *
 * We're looking for:
 *
 * a) the next instruction is a RET_JQ or a chain of unconditional JUMPs
 * that ends in a RET_JQ, and
 *
 * b) none of the closures -callee included- have level == 0.
 */
static uint16_t tail_call_analyze(uint16_t *pc) {
  assert(*pc == CALL_JQ);
  pc++;
  // + 1 for the callee closure
  for (uint16_t nclosures = *pc++ + 1; nclosures > 0; pc++, nclosures--) {
    if (*pc++ == 0)
      return CALL_JQ;
  }
  if (ret_follows(pc))
    return TAIL_CALL_JQ;
  return CALL_JQ;
}

static struct bytecode *optimize_code(struct bytecode *bc) {
  uint16_t *pc = bc->code;
  // FIXME: Don't mutate bc->code...
  while (pc < bc->code + bc->codelen) {
    switch (*pc) {
    case CALL_JQ:
      *pc = tail_call_analyze(pc);
      break;

    // Other bytecode optimizations here.  A peephole optimizer would
    // fit right in.
    default: break;
    }
    pc += bytecode_operation_length(pc);
  }
  return bc;
}

static struct bytecode *optimize(struct bytecode *bc) {
  for (int i=0; i<bc->nsubfunctions; i++) {
    bc->subfunctions[i] = optimize(bc->subfunctions[i]);
  }
  return optimize_code(bc);
}

static jv
args2obj(jv args)
{
  if (jv_get_kind(args) == JV_KIND_OBJECT)
    return args;
  assert(jv_get_kind(args) == JV_KIND_ARRAY);
  jv r = jv_object();
  jv kk = jv_string("name");
  jv vk = jv_string("value");
  jv_array_foreach(args, i, v)
    r = jv_object_set(r, jv_object_get(jv_copy(v), kk), jv_object_get(v, vk));
  jv_free(args);
  jv_free(kk);
  jv_free(vk);
  return r;
}

int jq_compile_args(jq_state *jq, const char* str, jv args) {
  jv_nomem_handler(jq->nomem_handler, jq->nomem_handler_data);
  assert(jv_get_kind(args) == JV_KIND_ARRAY || jv_get_kind(args) == JV_KIND_OBJECT);
  struct locfile* locations;
  locations = locfile_init(jq, "<top-level>", str, strlen(str));
  block program;
  jq_reset(jq);
  if (jq->bc) {
    bytecode_free(jq->bc);
    jq->bc = 0;
    jq->start_pc = 0;
  }
  if (jq->libs) {
    libraries_free(jq->libs);
    jq->libs = 0;
  }
  int nerrors = load_program(jq, locations, &program, &jq->libs);
  if (nerrors == 0) {
    nerrors = builtins_bind(jq, &program);
    if (nerrors == 0) {
      nerrors = block_compile(program, &jq->bc, locations, args = args2obj(args));
    }
  } else
    jv_free(args);
  if (nerrors)
    jq_report_error(jq, jv_string_fmt("jq: %d compile %s", nerrors, nerrors > 1 ? "errors" : "error"));
  if (jq->bc) {
    jq->bc = optimize(jq->bc);
    jq->start_pc = jq->bc->code;
  }
  locfile_free(locations);
  return jq->bc != NULL;
}

int jq_compile(jq_state *jq, const char* str) {
  return jq_compile_args(jq, str, jv_object());
}

jv jq_get_jq_origin(jq_state *jq) {
  return jq_get_attr(jq, jv_string("JQ_ORIGIN"));
}

jv jq_get_prog_origin(jq_state *jq) {
  return jq_get_attr(jq, jv_string("PROGRAM_ORIGIN"));
}

jv jq_get_lib_dirs(jq_state *jq) {
  return jq_get_attr(jq, jv_string("JQ_LIBRARY_PATH"));
}

void jq_set_attrs(jq_state *jq, jv attrs) {
  assert(jv_get_kind(attrs) == JV_KIND_OBJECT);
  jv_free(jq->attrs);
  jq->attrs = attrs;
}

/*
 * Set an I/O policy -- a jq program.
 *
 * If, when given `null` as input, the policy jq program produces an object or
 * an array, or `true` or `null` or `false`, then that will be the policy data
 * and the program used at run time will be the `default_io_policy_check`
 * builtin using the constant data produced by running the original program
 * with `null` as input.
 *
 * Otherwise the given jq program will be the policy checker.
 *
 * At run-time the policy will be checked by calling the policy program (on a
 * separate jq_state!) with a request descriptor and the policy data as input.
 */
jv jq_set_io_policy(jq_state *jq, jv policy) {
  if (jq->io_policy)
    jq_teardown(&jq->io_policy);

  switch (jv_get_kind(policy)) {
  case JV_KIND_STRING:
    break;
  case JV_KIND_INVALID:
    jv_free(policy);
    return jv_invalid_with_msg(jv_string_fmt("Invalid I/O policy given"));
  case JV_KIND_NULL:
  case JV_KIND_TRUE:
  case JV_KIND_FALSE:
    jv_free(jq->io_policy_data);
    jq->io_policy_data = policy;
    return jv_true();
  default:
    jv_free(jq->io_policy_data);
    jq->io_policy_data = policy;
    policy = jv_string("default_io_policy_check");
    break;
  }

  jq_state *io_policy = jq_init();
  if (!io_policy)
    return jv_invalid_with_msg(jv_string("Out of memory"));

  int r = jq_compile_args(io_policy, jv_string_value(policy), jv_array());
  if (!r) {
    jq_teardown(&io_policy);
    jv ret = jv_invalid_with_msg(jv_string_fmt("Failed to compile I/O policy program: %s\n",
                                               jv_string_value(policy)));
    jv_free(policy);
    return ret;
  }

  /* Check if the program produces policy data, or evaluates policy */
  jq_start(io_policy, jv_null(), jq->debug_flags);
  copy_callbacks(jq, io_policy);
  jv v = jq_next(io_policy);
  jv ret;
  switch (jv_get_kind(v)) {
  case JV_KIND_OBJECT:
  case JV_KIND_ARRAY:
    /* Produces data to evaluate with the default policy checker */
    jv_free(jq->io_policy_data);
    jq->io_policy_data = v;
    v = jv_null();
    jq_teardown(&io_policy);
    io_policy = jq_init();
    if (!io_policy) {
      jv_free(policy);
      return jv_invalid_with_msg(jv_string("Out of memory")); // XXX leak
    }
    r = jq_compile_args(io_policy, "default_io_policy_check", jv_array());
    if (!r) {
      jq_teardown(&io_policy);
      jv ret = jv_invalid_with_msg(jv_string("Failed to compile default I/O policy program\n"));
      jv_free(policy);
      return ret;
    }
    jq->io_policy = io_policy;
    return jv_true();
  case JV_KIND_NULL:
  case JV_KIND_TRUE:
  case JV_KIND_FALSE:
    /* Produces simple data */
    jv_free(jq->io_policy_data);
    jq->io_policy_data = v;
    jq_teardown(&io_policy);
    return jv_true();
  case JV_KIND_INVALID:
    /* The program is a policy evaluator */
    jq->io_policy = io_policy;
    jv_free(policy);
    jv_free(v);
    return jv_true();
  case JV_KIND_STRING:
    /* Usage error */
    ret = jv_invalid_with_msg(jv_string_fmt("Strange policy value: %s", jv_string_value(policy)));
    jv_free(policy);
    return ret;
  default:
    /* Usage error */
    ret = jv_invalid_with_msg(jv_string_fmt("Strange policy value"));
    jv_free(policy);
    return ret;
  }
}

void jq_set_attr(jq_state *jq, jv attr, jv val) {
  jq->attrs = jv_object_set(jq->attrs, attr, val);
}

jv jq_get_attr(jq_state *jq, jv attr) {
  return jv_object_get(jv_copy(jq->attrs), attr);
}

void jq_dump_disassembly(jq_state *jq, int indent) {
  dump_disassembly(indent, jq->bc);
}

void jq_set_input_cb(jq_state *jq, jq_input_cb cb, void *data) {
  jq->input_cb = cb;
  jq->input_cb_data = data;
}

void jq_get_input_cb(jq_state *jq, jq_input_cb *cb, void **data) {
  *cb = jq->input_cb;
  *data = jq->input_cb_data;
}

void jq_set_debug_cb(jq_state *jq, jq_msg_cb cb, void *data) {
  jq->debug_cb = cb;
  jq->debug_cb_data = data;
}

void jq_get_debug_cb(jq_state *jq, jq_msg_cb *cb, void **data) {
  *cb = jq->debug_cb;
  *data = jq->debug_cb_data;
}

void
jq_halt(jq_state *jq, jv exit_code, jv error_message)
{
  assert(!jq->halted);
  jq->halted = 1;
  jq->exit_code = exit_code;
  jq->error_message = error_message;
}

int
jq_halted(jq_state *jq)
{
  return jq->halted;
}

int
jq_finished(jq_state *jq)
{
  return jq->halted || jq->finished;
}

jv jq_get_exit_code(jq_state *jq)
{
  return jv_copy(jq->exit_code);
}

jv jq_get_error_message(jq_state *jq)
{
  return jv_copy(jq->error_message);
}

jv jq_io_policy_check(jq_state *jq, jv req) {
  if (!jq->io_policy) {
    jv_free(req);
    return jv_copy(jq->io_policy_data);
  }
  jq_start(jq->io_policy,
           JV_OBJECT(jv_string("io_policy"), jv_copy(jq->io_policy_data),
                     jv_string("io_request"), req), jq->debug_flags);
  copy_callbacks(jq, jq->io_policy);
  jv res = jq_next(jq->io_policy);
  switch (jv_get_kind(res)) {
  case JV_KIND_TRUE:
  case JV_KIND_FALSE:
    return res;
  case JV_KIND_INVALID:
    if (jv_invalid_has_msg(jv_copy(res)))
      return res;
    jv_free(res);
    return jv_false();
  default:
    jv_free(res);
    return jv_false();
  }
}

static void init_vtable(struct jq_plugin_vtable *vtable) {
  vtable->jv_string_append_buf = jv_string_append_buf;
  vtable->jv_object_iter_next = jv_object_iter_next;
  vtable->jq_get_lib_dirs = jq_get_lib_dirs;
  vtable->jv_mem_free = jv_mem_free;
  vtable->jq_get_error_cb = jq_get_error_cb;
  vtable->jv_string_vfmt = jv_string_vfmt;
  vtable->jv_number_value = jv_number_value;
  vtable->jv_mem_alloc_unguarded = jv_mem_alloc_unguarded;
  vtable->jv_true = jv_true;
  vtable->jv_object_set = jv_object_set;
  vtable->jv_mem_calloc = jv_mem_calloc;
  vtable->jv_parser_next = jv_parser_next;
  vtable->jv_dump_string = jv_dump_string;
  vtable->jv_invalid_get_msg = jv_invalid_get_msg;
  vtable->jq_util_input_set_parser = jq_util_input_set_parser;
  vtable->jv_copy = jv_copy;
  vtable->jv_get = jv_get;
  vtable->jv_mem_calloc_unguarded = jv_mem_calloc_unguarded;
  vtable->jv_string_value = jv_string_value;
  vtable->jv_identical = jv_identical;
  vtable->jq_get_prog_origin = jq_get_prog_origin;
  vtable->jv_invalid_with_msg = jv_invalid_with_msg;
  vtable->jv_equal = jv_equal;
  vtable->jq_dump_disassembly = jq_dump_disassembly;
  vtable->jv_object_iter = jv_object_iter;
  vtable->jv_dump = jv_dump;
  vtable->jv_array_sized = jv_array_sized;
  vtable->jv_string_append_str = jv_string_append_str;
  vtable->jq_get_exit_code = jq_get_exit_code;
  vtable->jv_getpath = jv_getpath;
  vtable->jq_get_attr = jq_get_attr;
  vtable->jq_halted = jq_halted;
  vtable->jq_finished = jq_finished;
  vtable->jv_array_length = jv_array_length;
  vtable->jv_array_concat = jv_array_concat;
  vtable->jv_string_implode = jv_string_implode;
  vtable->jv_string_explode = jv_string_explode;
  vtable->jq_start = jq_start;
  vtable->jq_teardown = jq_teardown;
  vtable->jv_parser_remaining = jv_parser_remaining;
  vtable->jq_util_input_get_position = jq_util_input_get_position;
  vtable->jv_group = jv_group;
  vtable->jv_false = jv_false;
  vtable->jv_string_fmt = jv_string_fmt;
  vtable->jq_set_input_cb = jq_set_input_cb;
  vtable->jq_util_input_init = jq_util_input_init;
  vtable->jv_null = jv_null;
  vtable->jv_setpath = jv_setpath;
  vtable->jv_string_split = jv_string_split;
  vtable->jv_set = jv_set;
  vtable->jv_mem_strdup_unguarded = jv_mem_strdup_unguarded;
  vtable->jq_get_jq_origin = jq_get_jq_origin;
  vtable->jq_halt = jq_halt;
  vtable->jv_show = jv_show;
  vtable->jq_init = jq_init;
  vtable->jv_kind_name = jv_kind_name;
  vtable->jv_string_append_codepoint = jv_string_append_codepoint;
  vtable->jq_get_error_message = jq_get_error_message;
  vtable->jv_array_get = jv_array_get;
  vtable->jv_object_merge = jv_object_merge;
  vtable->jq_compile_args = jq_compile_args;
  vtable->jq_util_input_next_input = jq_util_input_next_input;
  vtable->jv_dump_string_trunc = jv_dump_string_trunc;
  vtable->jq_next = jq_next;
  vtable->jv_parse_sized = jv_parse_sized;
  vtable->jv_cmp = jv_cmp;
  vtable->jv_number = jv_number;
  vtable->jv_dumpf = jv_dumpf;
  vtable->jv_object_get = jv_object_get;
  vtable->jv_parse = jv_parse;
  vtable->jq_set_attr = jq_set_attr;
  vtable->jq_util_input_get_current_line = jq_util_input_get_current_line;
  vtable->jv_parser_new = jv_parser_new;
  vtable->jv_object_iter_value = jv_object_iter_value;
  vtable->jv_invalid_has_msg = jv_invalid_has_msg;
  vtable->jv_string_length_bytes = jv_string_length_bytes;
  vtable->jv_object_iter_key = jv_object_iter_key;
  vtable->jq_report_error = jq_report_error;
  vtable->jv_is_integer = jv_is_integer;
  vtable->jv_string = jv_string;
  vtable->jv_contains = jv_contains;
  vtable->jv_mem_alloc = jv_mem_alloc;
  vtable->jv_string_hash = jv_string_hash;
  vtable->jv_string_slice = jv_string_slice;
  vtable->jv_load_file = jv_load_file;
  vtable->jq_compile = jq_compile;
  vtable->jv_get_kind = jv_get_kind;
  vtable->jv_object_merge_recursive = jv_object_merge_recursive;
  vtable->jv_bool = jv_bool;
  vtable->jq_util_input_get_current_filename = jq_util_input_get_current_filename;
  vtable->jv_object_iter_valid = jv_object_iter_valid;
  vtable->jv_has = jv_has;
  vtable->jv_array_set = jv_array_set;
  vtable->jv_object_delete = jv_object_delete;
  vtable->jq_set_debug_cb = jq_set_debug_cb;
  vtable->jv_string_empty = jv_string_empty;
  vtable->jq_realpath = jq_realpath;
  vtable->jq_set_error_cb = jq_set_error_cb;
  vtable->jq_util_input_next_input_cb = jq_util_input_next_input_cb;
  vtable->jv_get_refcnt = jv_get_refcnt;
  vtable->jq_set_colors = jq_set_colors;
  vtable->jv_array_slice = jv_array_slice;
  vtable->jv_mem_realloc = jv_mem_realloc;
  vtable->jv_array = jv_array;
  vtable->jv_parser_set_buf = jv_parser_set_buf;
  vtable->jv_keys_unsorted = jv_keys_unsorted;
  vtable->jv_delpaths = jv_delpaths;
  vtable->jv_sort = jv_sort;
  vtable->jv_parser_free = jv_parser_free;
  vtable->jv_array_indexes = jv_array_indexes;
  vtable->jv_string_concat = jv_string_concat;
  vtable->jv_object_has = jv_object_has;
  vtable->jv_invalid = jv_invalid;
  vtable->jq_util_input_free = jq_util_input_free;
  vtable->jv_object_length = jv_object_length;
  vtable->jq_get_input_cb = jq_get_input_cb;
  vtable->jv_string_sized = jv_string_sized;
  vtable->jv_string_length_codepoints = jv_string_length_codepoints;
  vtable->jq_format_error = jq_format_error;
  vtable->jv_array_append = jv_array_append;
  vtable->jv_string_indexes = jv_string_indexes;
  vtable->jv_free = jv_free;
  vtable->jq_get_debug_cb = jq_get_debug_cb;
  vtable->jq_util_input_errors = jq_util_input_errors;
  vtable->jv_mem_strdup = jv_mem_strdup;
  vtable->jq_util_input_add_input = jq_util_input_add_input;
  vtable->jv_object = jv_object;
  vtable->jv_keys = jv_keys;
  vtable->jq_set_attrs = jq_set_attrs;
  vtable->jq_io_handle_call = jq_io_handle_call;
  vtable->jq_io_open_handle = jq_io_open_handle;
  vtable->jq_io_handle_validate = jq_io_handle_validate;
  vtable->jq_io_register_scheme = jq_io_register_scheme;
}
