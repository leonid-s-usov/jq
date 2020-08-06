
#include "jq_io_co.h"
#include "jq_io_private.h"
#include "execute.h"

typedef struct context {
  struct jq_io_table iot;
  jq_state *child;
  jv input;
  jv err;
} context;

#define MAKE_ERROR_CLOSED() jv_invalid_with_msg(jv_string("Invalid operation on a closed coroutine"))

static jv close(jq_state *jq, jv cdata, jv input) {
  context* ctx = jv_cstruct_copy_get_ptr(cdata);
  jq_teardown(&(ctx->child));
  jv_free(cdata);
  return input;
}

static jv reset(jq_state *jq, jv cdata, jv input) {
  context* ctx = jv_cstruct_copy_get_ptr(cdata);
  if (ctx->child) {
    jq_start(ctx->child, jv_copy(input));
  } else {
    jv_free(input);
    input = MAKE_ERROR_CLOSED();
  }
  jv_free(cdata);
  return input;
}

static jq_io_stat stat(jq_state *jq, jv cdata, jv input) {
  context* ctx = jv_cstruct_copy_get_ptr(cdata);
  jq_io_stat result = {.open = 0, .eof = 0};
  if (ctx->child) {
    result.open = 1;
    result.eof = jq_finished(ctx->child);
  }
  jv_free(cdata);
  jv_free(input);
  return result;
}

static jv io(jq_state *jq, jv cdata, jv input, jv arg) {
  context* ctx = jv_cstruct_copy_get_ptr(cdata);
  jv_free(arg);

  jv result = jv_invalid();

  if (ctx->child) {
    jv_free(ctx->input);
    ctx->input = input;
    result = jq_next(ctx->child);
  } 
  else {
    jv_free(input);
    result = MAKE_ERROR_CLOSED();
  }

  jv_free(cdata);
  return result;
}

static void free_context(context * ctx) {
  jq_teardown(&(ctx->child));
  jv_free(ctx->input);
  jv_free(ctx->err);


  jv_mem_free(ctx);
}

static struct jq_io_table co_iot = {
  .io = io,
  .stat = stat,
  .reset = reset,
  .close = close
};

static jv coinput_cb(jq_state *child, context * ctx) {
  jv ret = ctx->input;
  ctx->input = jv_invalid();
  return ret;
}


static jv make_context(jq_state* child) {
  context * ctx = jv_mem_alloc(sizeof(context));
  ctx->iot = co_iot;
  ctx->child = child;
  ctx->input = jv_invalid();

  jq_set_input_cb(child, coinput_cb, ctx);

  return jv_cstruct(ctx, free_context);
}


jv jq_io_coexpr_handle_create(jq_state *parent, uint16_t* start_pc){
    jq_state *child;
  child = jv_mem_calloc(1, sizeof(*child));

  /* First, copy all fields */
  *child = *parent;

  /* Copy the stack (see notes in exec_stack.h) */
  stack_copy(&child->stk, &parent->stk);

  /* Linkt the parent */
  child->parent = parent;

  /* Stop the child freeing things that belong to the parent */
  child->restore_limit = child->stk.limit;
  child->start_pc = start_pc;

  child->halted = 0;
  child->libs = 0;

  /* Copy or null out various jv values not kept on the stack */
  child->value_at_path = jv_copy(parent->value_at_path);
  child->error_message = jv_invalid();
  child->exit_code = jv_invalid();
  child->error = jv_null();
  child->attrs = jv_copy(parent->attrs);
  child->path = jv_copy(parent->path);
  child->io_policy_data = jv_copy(parent->io_policy_data);
  child->start_input = jv_invalid();

  /* Share I/O handles with the parent */
  child->io_schemes = jv_copy(parent->io_schemes);

  child->input_cb = NULL;
  child->input_cb_data = NULL;

  child->debug_flags = parent->debug_flags;

  jv jctx = make_context(child);

  return jq_io_handle_make(parent, jv_string_fmt("builtin:coexpr:%x", child), jctx);
}



static void co_err_cb(jv * err, jv msg) {
  jv concat = jv_string_fmt("%s\n%s", jv_string_value(*err), jv_string_value(msg));

  jv_free(*err);
  jv_free(msg);

  *err = concat;
}

jv jq_io_coeval_handle_create(jq_state* parent, jv input, jv program) {
  jv options = jv_invalid();
  jv args = jv_null();

  if (jv_get_kind(program) == JV_KIND_ARRAY) {
    args = jv_array_get(jv_copy(program), 1);
    options = jv_array_get(jv_copy(program), 2);
    program = jv_array_get(program, 0);
  }

  if (jv_get_kind(args) != JV_KIND_OBJECT && jv_get_kind(args) != JV_KIND_NULL) {
    jv_free(program);
    jv_free(options);
    jv_free(input);
    jv_free(args);
    return jv_invalid_with_msg(jv_string("Eval program arguments must be an object or null"));
  }

  if (jv_get_kind(args) == JV_KIND_NULL) {
    jv_free(args);
    args = jv_object();
  }

  if (jv_is_valid(options) && jv_get_kind(options) != JV_KIND_OBJECT) {
    jv_free(program);
    jv_free(options);
    jv_free(input);
    jv_free(args);
    return jv_invalid_with_msg(jv_string("Eval program options must be an object"));
  }

  if (jv_get_kind(options) == JV_KIND_OBJECT &&
      jv_object_has(jv_copy(options), jv_string("ALLOW_IO"))) {
    jv allow_io = jv_object_get(jv_copy(parent->attrs), jv_string("ALLOW_IO"));
    if (jv_get_kind(allow_io) == JV_KIND_TRUE) {
      /* Parent allows I/O; child may allow I/O */
      jv_free(allow_io);
      options = jv_object_set(jv_copy(parent->attrs), jv_string("ALLOW_IO"),
                              jv_object_get(options, jv_string("ALLOW_IO")));
    } else {
      /* No I/O for child because no I/O for parent */
      jv_free(allow_io);
      jv_free(options);
      options = jv_copy(parent->attrs);
    }
  } else {
    /* Child will not allow I/O regardless of whether the parent does */
    jv_free(options);
    options = jv_object_set(jv_copy(parent->attrs), jv_string("ALLOW_IO"),
                            jv_false());
  }


  if (jv_get_kind(program) != JV_KIND_STRING) {
    jv_free(program);
    jv_free(options);
    jv_free(input);
    jv_free(args);
    return jv_invalid_with_msg(jv_string("Eval program must be a string"));
  }


  args = jv_object_set(args, 
    jv_string("ARGS"), JV_OBJECT(
      jv_string("positional"), jv_array(),
      jv_string("named"), jv_copy(args)
    )
  );

  jq_state *child = jq_init();
  if (jv_is_valid(options)) {
    jq_set_attrs(child, jv_copy(options));
  }
  jv_free(options);

  jv errors = jv_string("");
  jq_set_error_cb(child, co_err_cb, &errors);

  if (!jq_compile_args(child, jv_string_value(program), jv_copy(args))) {
    jv error = jv_string_fmt("Eval program failed to compile: %s", jv_string_value(errors));
    jv_free(program);
    jv_free(options);
    jv_free(input);
    jv_free(args);
    jv_free(errors);
    jq_teardown(&child);
    return jv_invalid_with_msg(error);
  }

  /* Now let the child send errors to parent again */
  jq_set_error_cb(child, parent->err_cb, parent->err_cb_data);
  jq_set_debug_cb(child, parent->debug_cb, parent->debug_cb_data);

  jq_set_debug_flags(child, parent->debug_flags);

  jv_free(program);
  jv_free(args);
  jv_free(errors);



  jq_start(child, input);

  jv jctx = make_context(child);

  return jq_io_handle_make(parent, jv_string_fmt("builtin:coeval:%x", child), jctx);
}