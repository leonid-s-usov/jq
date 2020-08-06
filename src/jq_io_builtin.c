
#include "jq_io_builtin.h"
#include "execute.h"

// should return an object of type cstruct


static jv builtin_open(jq_state * jq, jv uri)
{
    return jv_invalid_with_msg(jv_string("not implemented"));
}

jv jq_io_init_schemes() {
  return jv_object_set(
    jv_object(),
    jv_string(JQ_HANDLE_SCHEME_BUILTIN),
    jv_cstruct(&builtin_open, NULL)
  );
}



