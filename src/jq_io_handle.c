

#include <limits.h>
#include <assert.h>
#include "execute.h"
#include "jq_io_builtin.h"

#define JQ_HANDLE_KEY_CTX     jv_string("$")
#define JQ_HANDLE_KEY_URI     jv_string("uri")

jv jq_io_handle_register_scheme(jq_state * jq, const char * scheme, jq_hopen_f open) {
  if (!strcmp(scheme, JQ_HANDLE_SCHEME_BUILTIN)) {
    return jv_invalid_with_msg(jv_string("Can't override scheme '" JQ_HANDLE_SCHEME_BUILTIN "'"));
  }

  jq->io_schemes = jv_object_set(
    jq->io_schemes,
    jv_string(scheme),
    jv_cstruct(open, NULL)
  );

  return jv_true();
}

jv jq_io_handle_make(jq_state* jq, jv uri, jv ctx) {
  return JV_OBJECT(
    JQ_HANDLE_KEY_CTX, ctx,
    JQ_HANDLE_KEY_URI, uri
  );
}

jv jq_io_handle_open(jq_state *jq, jv uri) {
  jv scheme = jv_invalid();
  jv ctx_or_error = jv_invalid();

  if (jv_get_kind(uri) == JV_KIND_STRING) {

    const char * uri_str = jv_string_value(uri);
    const char * colon = strstr(uri_str, ":");

    if (colon) {
      scheme = jv_string_sized(uri_str, colon - uri_str);
    }
  }
  else if (jv_get_kind(uri) == JV_KIND_OBJECT) {
    scheme = jv_object_get(jv_copy(uri), jv_string("scheme"));
  }

  if (jv_is_valid(scheme)) {
    jv provider = jv_object_get(jv_copy(jq->io_schemes), jv_copy(scheme));
    if (jv_is_valid(provider) && jv_get_kind(provider) == JV_KIND_CSTRUCT) {
      jq_hopen_f open = jv_cstruct_copy_get_ptr(provider);
      jv cdata = open(jq, jv_copy(uri));

      if (jv_get_kind(cdata) == JV_KIND_CSTRUCT) {
        ctx_or_error = JV_OBJECT(
          JQ_HANDLE_KEY_CTX, cdata
        );
      } else {
        if(!jv_is_valid(cdata) && jv_invalid_has_msg(jv_copy(cdata))) {
          ctx_or_error = cdata;
        } 
        else {
          jv str = jv_dump_string(cdata, 0);
          ctx_or_error = jv_invalid_with_msg(
            jv_string_fmt("Couldn't open URI: provider status - %s", jv_string_value(str))
          );
          jv_free(str);
        }
      }
    }
    else {
      ctx_or_error = jv_invalid_with_msg(
        jv_string_fmt("Couldn't open URI: invalid scheme '%s'", jv_string_value(scheme))
      );
    }
    jv_free(provider);
    jv_free(scheme);
  }
  else {
    jv message;
    if (jv_get_kind(uri) == JV_KIND_STRING) {
      message = jv_string_fmt("Couldn't determine scheme: URI string was not in the correct format - '%s'", jv_string_value(uri));
    } else {
      message = jv_string_fmt("Couldn't determine scheme from %s", jv_kind_name(jv_get_kind(uri)));
    }
    ctx_or_error = jv_invalid_with_msg(message);
  }

  if (jv_is_valid(ctx_or_error)) {
    return jq_io_handle_make(jq, uri, ctx_or_error);
  } 
  else {
    assert(jv_invalid_has_msg(jv_copy(ctx_or_error)));
    jv_free(uri);
    return ctx_or_error;
  }
}

static jv get_handle_ctx(jq_state* jq, jv jhandle) {
  jv ctx = jv_invalid();

  if (jv_get_kind(jhandle) == JV_KIND_OBJECT) {
    ctx = jv_object_get(jhandle, JQ_HANDLE_KEY_CTX);
  }
  else {
    jv_free(jhandle);
  }

  if (jv_get_kind(ctx) == JV_KIND_CSTRUCT && jv_cstruct_copy_get_ptr(ctx)) {
    return ctx;
  }
  else {
    jv_free(ctx);
    return jv_invalid_with_msg(jv_string("Invalid handle"));
  }
}

#define GET_CTX_IOT(ctx)    ((struct jq_io_table*)jv_cstruct_copy_get_ptr(ctx))
#define CALL_CTX_IO(jq, ctx, method, ...)       ( jv_is_valid(ctx) ? GET_CTX_IOT(ctx)->method(jq, ctx, __VA_ARGS__) : ctx )

jv jq_io_handle_close(jq_state *jq, jv jhandle, jv input) {
  jv ctx = get_handle_ctx(jq, jhandle);
  return CALL_CTX_IO(jq, ctx, close, input);
}

jv jq_io_handle_reset(jq_state *jq, jv jhandle, jv input) {
  jv ctx = get_handle_ctx(jq, jhandle);
  return CALL_CTX_IO(jq, ctx, reset, input);
}

jv jq_io_handle_io(jq_state *jq, jv jhandle, jv input, jv arg) {
  jv ctx = get_handle_ctx(jq, jhandle);
  return CALL_CTX_IO(jq, ctx, io, input, arg);
}

jv jq_io_handle_stat(jq_state *jq, jv jhandle, jv input) {
  jv ctx = get_handle_ctx(jq, jhandle);
  if (jv_is_valid(ctx)) {
    jq_io_stat stat = GET_CTX_IOT(ctx)->stat(jq, ctx, input);
    return JV_OBJECT(
      jv_string("open"), jv_bool(stat.open),
      jv_string("eof"), jv_bool(stat.eof)
    );
  } else {
    return ctx;
  }
}
