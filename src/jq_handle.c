

#include <limits.h>
#include <assert.h>
#include "execute.h"

struct raw_handle {
  void * data;
  struct jq_io_table * iot;
  jq_state * jq;
};

#define JQ_HANDLE_KEY_CHANDLE jv_string("$")
#define JQ_HANDLE_KEY_URI     jv_string("uri")

jv jq_init_io_schemes(struct jq_io_table * builtin) {
  return jv_object_set(
    jv_object(),
    jv_string(JQ_HANDLE_SCHEME_BUILTIN),
    jv_cstruct(builtin, NULL)
  );
}

jv jq_handle_register_scheme(jq_state * jq, const char * scheme, struct jq_io_table * io_table) {
  if (!strcmp(scheme, JQ_HANDLE_SCHEME_BUILTIN)) {
    return jv_invalid_with_msg(jv_string("Can't override scheme '" JQ_HANDLE_SCHEME_BUILTIN "'"));
  }

  jq->io_schemes = jv_object_set(
    jq->io_schemes,
    jv_string(scheme),
    jv_cstruct(io_table, NULL)
  );

  return jv_true();
}

static void jq_invalidate_raw_handle(struct raw_handle * h) {
  if (h->data) {
    assert(h->iot && h->jq);
    h->iot->close(h->jq, h->data, jv_invalid());
    h->data = 0;
  }
  jv_mem_free(h);
}

jv jq_handle_open(jq_state *jq, jv uri) {
  jv scheme = jv_invalid();
  jv chandle_or_error = jv_invalid();

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
      struct jq_io_table* iot = jv_cstruct_copy_get_value(provider);
      jv error = jv_invalid();
      void* handle_data = iot->open(jq, uri, &error);
      if (handle_data) {
        struct raw_handle * raw_handle = jv_mem_alloc(sizeof(struct raw_handle));
        raw_handle->data = handle_data;
        raw_handle->iot = iot;
        raw_handle->jq = jq;
        chandle_or_error = jv_cstruct(raw_handle, jq_invalidate_raw_handle);
      } else {
        if(!jv_is_valid(error) && jv_invalid_has_msg(error)) {
          chandle_or_error = error;
        } 
        else {
          jv str = jv_dump_string(error, 0);
          chandle_or_error = jv_invalid_with_msg(
            jv_string_fmt("Couldn't open URI: provider status - %s", jv_string_value(str))
          );
          jv_free(str);
        }
      }
    }
    else {
      chandle_or_error = jv_invalid_with_msg(
        jv_string_fmt("Couldn't open URI: unknown scheme '%s'", jv_string_value(scheme))
      );
    }
    jv_free(scheme);
  }
  else {
    jv message;
    if (jv_get_kind(uri) == JV_KIND_STRING) {
      message = jv_string_fmt("Couldn't determine scheme: URI string was not in the correct format - '%s'", jv_string_value(uri));
    } else {
      message = jv_string_fmt("Couldn't determine scheme from %s", jv_kind_name(jv_get_kind(uri)));
    }
    chandle_or_error = jv_invalid_with_msg(message);
  }

  if (jv_is_valid(chandle_or_error)) {
    return JV_OBJECT(
      JQ_HANDLE_KEY_CHANDLE, chandle_or_error,
      JQ_HANDLE_KEY_URI, uri
    );
  } 
  else {
    assert(jv_invalid_has_msg(chandle_or_error));
    jv_free(uri);
    return chandle_or_error;
  }
}

static struct raw_handle* jv_get_raw_handle(jv jhandle) {
  struct raw_handle* result = 0;
  if (jv_get_kind(jhandle) == JV_KIND_OBJECT) {
    jv chandle = jv_object_get(jhandle, JQ_HANDLE_KEY_CHANDLE);
    if (jv_get_kind(chandle) == JV_KIND_CSTRUCT) {
      result = jv_cstruct_copy_get_value(chandle);
    } 
    jv_free(chandle);
  }
  else {
    jv_free(jhandle);
  }
  return result;
}

static struct raw_handle* validate_handle(jq_state* jq, jv jhandle) {
  struct raw_handle* h = jv_get_raw_handle(jhandle);
  // TODO: additional validation of the iot obj
  if (h && (h->jq == jq) && h->iot) {
    return h;
  }
}

jv jq_handle_close(jq_state *jq, jv jhandle, jv input) {
  struct raw_handle* h = validate_handle(jq, jhandle);
  if (h) {
    jv result = h->iot->close(jq, h->data, input);
    if(jv_is_valid(result)) {
      h->data = 0;
    }
    return result;
  }
  return jv_invalid_with_msg(jv_string("Invalid handle"));
}

jv jq_handle_reset(jq_state *jq, jv jhandle, jv input) {
  struct raw_handle* h = validate_handle(jq, jhandle);
  if (h) {
    return h->iot->reset(jq, h->data, input);
  }
  return jv_invalid_with_msg(jv_string("Invalid handle"));
}

jv jq_handle_io(jq_state *jq, jv jhandle, jv input, jv arg) {
  struct raw_handle* h = validate_handle(jq, jhandle);
  if (h) {
    return h->iot->io(jq, h->data, input, arg);
  }
  return jv_invalid_with_msg(jv_string("Invalid handle"));
}

jv jq_handle_at_eof(jq_state *jq, jv jhandle, jv input) {
  struct raw_handle* h = validate_handle(jq, jhandle);
  if (h) {
    return h->iot->at_eof(jq, h->data, input);
  }
  return jv_invalid_with_msg(jv_string("Invalid handle"));
}
