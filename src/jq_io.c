

#include <limits.h>
#include <assert.h>
#include "execute.h"
#include "jq_io.h"

#define H_COPY_GET(h, key)  jv_object_get(jv_copy(h), jv_string( JQ_IO_HANDLE_KEY_ ## key ))

static const char * required_methods[] = { 
  JQ_IO_METHOD_DEFAULT,
  JQ_IO_METHOD_EOF,       
  JQ_IO_METHOD_RESET,
  JQ_IO_METHOD_CLOSE,
};

#define SIZE_OF(arr) (int)(sizeof(arr) / sizeof(*arr))

jv jq_io_register_scheme(jq_state * jq, const char * scheme, jq_io_open_f open) {
  if (!strcmp(scheme, JQ_IO_SCHEME_BUILTIN)) {
    return jv_invalid_with_msg(jv_string("Can't override scheme '" JQ_IO_SCHEME_BUILTIN "'"));
  }

  jq->io_schemes = jv_object_set(
    jq->io_schemes,
    jv_string(scheme),
    jv_cstruct(open, NULL)
  );

  return jv_true();
}

static jv jq_io_handle_validate_internal(jv handle, jv default_uri) {

  jv result = jv_invalid();
  jv ctx = jv_invalid();
  jv mtds = jv_invalid();
  jv mtd = jv_invalid();
  jv uri = jv_invalid();

  if (jv_get_kind(handle) != JV_KIND_OBJECT) {
    result = jv_invalid_with_msg(jv_string_fmt("Bad handle - <%s>", jv_kind_name(jv_get_kind(handle))));
    goto done;
  }

  ctx = H_COPY_GET(handle, CONTEXT);
  if (jv_get_kind(ctx) != JV_KIND_CSTRUCT) {
    result = jv_invalid_with_msg(jv_string_fmt("Bad handle - context <%s>", jv_kind_name(jv_get_kind(ctx))));
    goto done;
  }


  mtds = H_COPY_GET(handle, METHODS);
  if (jv_get_kind(mtds) != JV_KIND_OBJECT) {
    result = jv_invalid_with_msg(jv_string_fmt("Bad handle - methods <%s>", jv_kind_name(jv_get_kind(mtds))));
    goto done;
  }

  mtd = jv_invalid();

  for (int i = 0; i < SIZE_OF(required_methods); i ++) {
    const char * name = required_methods[i];
    jv_free(mtd);
    mtd = jv_object_get(jv_copy(mtds), jv_string(name));
    if (jv_get_kind(mtd) != JV_KIND_CSTRUCT) {
      result = jv_invalid_with_msg(jv_string_fmt("Bad handle method '%s' - <%s>", name, jv_kind_name(jv_get_kind(mtd))));
      goto done;
    }
  }

  uri = H_COPY_GET(handle, URI);

  if (!jv_is_valid(uri)) {
    if (jv_is_valid(default_uri)) {
      result = jv_object_set(
        jv_copy(handle), 
        jv_string(JQ_IO_HANDLE_KEY_URI), jv_copy(default_uri)
      );
    }
    else {
      result = jv_invalid_with_msg(jv_string("Bad handle - uri"));
    }
  }
  else {
    result = jv_copy(handle);
  }

  done:

  jv_free(mtd);
  jv_free(mtds);
  jv_free(uri);
  jv_free(ctx);
  jv_free(handle);
  jv_free(default_uri);

  return result;
}

jv jq_io_handle_validate(jv handle) {
  return jq_io_handle_validate_internal(handle, jv_invalid());
}

jv jq_io_open_handle(jq_state *jq, jv uri) {
  jv scheme = jv_invalid();
  jv handle_or_error = jv_invalid();

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
      jq_io_open_f open = jv_cstruct_copy_get_ptr(provider);
      handle_or_error = jq_io_handle_validate_internal(
        open(jq, jv_copy(uri)),
        jv_copy(uri) 
      );
      if (!jv_is_valid(handle_or_error)) {
        jv uri_dump = jv_dump_string(jv_copy(uri), 0);
        jv error = jv_invalid_get_msg(handle_or_error);
        handle_or_error = jv_invalid_with_msg(
          jv_string_fmt("Couldn't open URI '%s': %s", jv_string_value(uri_dump), jv_string_value(error))
        );
        jv_free(uri_dump);
        jv_free(error);
      }
    }
    else {
      handle_or_error = jv_invalid_with_msg(
        jv_string_fmt("Couldn't open URI: invalid scheme '%s'", jv_string_value(scheme))
      );
    }
    jv_free(provider);
  }
  else {
    jv message;
    if (jv_get_kind(uri) == JV_KIND_STRING) {
      message = jv_string_fmt("Couldn't determine scheme: URI string was not in the correct format - '%s'", jv_string_value(uri));
    } else {
      message = jv_string_fmt("Couldn't determine scheme from %s", jv_kind_name(jv_get_kind(uri)));
    }
    handle_or_error = jv_invalid_with_msg(message);
  }

  jv_free(scheme);
  jv_free(uri);

  return handle_or_error;
}


jv jq_io_handle_call(jq_state *jq, jv input, jv method_name, jv handle) {

  jv result = jq_io_handle_validate(handle);

  if (jv_is_valid(result)) {
    jv ctx = H_COPY_GET(result, CONTEXT);
    jv mtds = H_COPY_GET(result, METHODS);
    jv mtd = jv_object_get(mtds, jv_copy(method_name));

    jv_free(result);
    

    if (jv_get_kind(mtd) == JV_KIND_CSTRUCT) {
      jq_io_call_f io = jv_cstruct_copy_get_ptr(mtd);
      result = io(jq, input, ctx, method_name);
    } 
    else {
      result = jv_invalid_with_msg(jv_string_fmt("Unknown method '%s'", jv_string_value(method_name)));

      jv_free(input);
      jv_free(method_name);
      jv_free(ctx);
    }

    jv_free(mtd);
  }

  return result;
}
