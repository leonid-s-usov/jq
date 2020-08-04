
#ifndef EXECUTE_H
#define EXECUTE_H

#include <stdint.h>

#include "jv.h"
#include "jq_handle.h"

#include "exec_stack.h"
#include "bytecode.h"

struct jq_plugin_vtable vtable;

enum bt_priority {
  BT_PRIO_NONE = 0,

  // This is a signal matched by a tag
  // the tag may encode an instruction
  // or a pc offset
  // special case of tag 0 is reserved
  // for a simple data backtracking.
  BT_PRIO_SIGNAL,

  // unwind protect handlers
  BT_PRIO_PROTECT,

  // ===============
  // this should be the max priority
  BT_PRIO_ALWAYS,
  // ===============

  // terminate is a kind of mode 
  // which is set when unwinding before termination
  BT_PRIO_TERMINATE = BT_PRIO_ALWAYS,
};

#define BT_PRIO_BITS 2

#if (BT_PRIO_ALWAYS >= (1<<BT_PRIO_BITS)) 
  #error "bt_priority should fit in " #BT_PRIO_BITS " bits"
#endif

#define BT_TAG_BITS (32 - BT_PRIO_BITS)
#define BT_MAX_TAG ((1 << BT_TAG_BITS) - 1)

// Backtracking tag space is broken into the following 16 bit regions:
// 0x00000 - 0x0ffff  -  opcode space + hard tags
// 0x10000 - 0x1ffff  -  soft tags
// 0x20000 - ....   pc tag, where the lower 16 bits are the offset and the higher bits is level + 2

#define BT_TAG_HARD_START NUM_OPCODES
#define BT_TAG_SOFT_START 0x10000
#define BT_TAG_PC_START   0x20000

#define BT_TAG_IS_OPCODE(tag)     ((tag)<NUM_OPCODES)
#define BT_TAG_IS_HARD(tag)       ((tag)>=BT_TAG_HARD_START && (tag)<BT_TAG_SOFT_START)
#define BT_TAG_IS_SOFT(tag)       ((tag)>=BT_TAG_SOFT_START && (tag)<BT_TAG_PC_START)
#define BT_TAG_IS_FRAME_PC(tag)   ((tag)>=BT_TAG_PC_START)

enum bt_hard_tag {
  // should be the first member here
  __hard_tag_start = (BT_TAG_HARD_START-1),

  // should be the last member here
  __hard_tag_end,
};

#if ( __hard_tag_end >= BT_TAG_SOFT_START)
#   error "Too many hard tags"
#endif

#define BT_TAG_SOFT(tag)                (BT_TAG_SOFT_START + (tag))
#define BT_TAG_FRAME_PC(level,offset)   (BT_TAG_PC_START + ((level)<<16) + (offset))

// returns -1 if the tag is not soft, of the soft tag itself.
// NB: 0 is a valid soft tag
#define BT_TAG_GET_SOFT(tag)        (MAX(-1, (int)((tag) - BT_TAG_SOFT_START)))
#define BT_TAG_GET_PC_FRAME(tag)    (MAX(-1, (int)((tag) - BT_TAG_PC_START) >> 16))
#define BT_TAG_GET_PC_OFFSET(tag)   ((tag) & 0xFFFF)

union bt_descriptor {
  uint32_t value;
  struct {
    uint32_t tag: BT_TAG_BITS;
    enum bt_priority prio: BT_PRIO_BITS;
  } fields;
};

struct bt_state {
  uint32_t desc;
  uint32_t ttl;
  jv payload;
};

struct jq_state {
  struct jq_plugin_vtable *vtable; /* Must be first! */
  void (*nomem_handler)(void *);
  void *nomem_handler_data;
  struct bytecode* bc;
  struct lib_loading_state *libs;

  jq_msg_cb err_cb;
  void *err_cb_data;
  jv error;
  
  struct bt_state bt;

  struct stack stk;
  stack_ptr curr_frame;
  stack_ptr stk_top;
  stack_ptr fork_top;

  jv path;
  jv value_at_path;
  int subexp_nest;
  int debug_flags;
  int initial_execution;
  unsigned next_label;

  unsigned int halted;
  unsigned int finished;
  jv exit_code;
  jv error_message;

  jv vmid;
  jv rnd;
  jv attrs;
  jq_input_cb input_cb;
  void *input_cb_data;
  jq_msg_cb debug_cb;
  void *debug_cb_data;

  /*
   * backward compatible start input
   * instead of storing it on the stack
   */
  jv start_input;
  jq_input_mode input_mode;

  /*
   * I/O schemes.
   *
   */
  jv io_schemes;

  /*
   * Co-routines
   *
   *  - parent points to the parent jq_state
   *  - restore_limit is the point past which the stack is shared with
   *    the parent, thus the child is not to unwind further than this
   *    point and the parent must teardown the child before unwinding
   *    past point
   *  - start_limit is the point to unwind to in order to reset a child
   *    co-routine so it can be restarted
   */
  struct jq_state* parent;
  stack_ptr restore_limit;
  uint16_t* start_pc;

  /*
   * I/O policy
   */
  struct jq_state* io_policy;
  jv io_policy_data;
};

struct closure {
  struct bytecode* bc;  // jq bytecode
  stack_ptr env;        // jq stack address of closed frame
};

// locals for any function called: either a closure or a local variable
union frame_entry {
  struct closure closure;
  jv localvar;
};

// jq function call frame
struct frame {
  struct bytecode* bc;      // jq bytecode for callee
  stack_ptr env;            // jq stack address of frame to return to
  stack_ptr retdata;        // jq stack address to unwind to on RET_JQ
  uint16_t* retaddr;        // jq bytecode return address
  union frame_entry entries[]; // nclosures + nlocals
};

#endif // EXECUTE_H