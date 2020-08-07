
#ifndef JQ_IO_H
#define JQ_IO_H

#include "jq.h"

// the builtin scheme, can't be overridden 
#define JQ_IO_SCHEME_BUILTIN    "jq"

// standard methods
// required
#define JQ_IO_METHOD_DEFAULT    ""
#define JQ_IO_METHOD_EOF        "eof"
#define JQ_IO_METHOD_RESET      "reset"
#define JQ_IO_METHOD_CLOSE      "close"
// optional
#define JQ_IO_METHOD_DESCRIBE   "describe"


// The handle object keys
#define JQ_IO_HANDLE_KEY_CONTEXT    "$"
#define JQ_IO_HANDLE_KEY_METHODS    "@"
#define JQ_IO_HANDLE_KEY_URI        "uri"


// The IO interface to the handle. 
typedef jv (*jq_io_call_f)(jq_state* jq, jv input, jv context, jv method);

/* 
 * The interface to an IO plugin
 * This is a pointer to a method that will open a handle for a given URI
 * must return an object of the format
 * { 
 *   "$": cstruct<void*>,   // the context cstruct object
 *   "@": {                 // supported methods, including the required four
 * 
 *     // default io method with an empty name
 *     "": cstruct<jq_io_call_f>,
 * 
 *     // method returning true or false
 *     "eof": cstruct<jq_io_call_f>,
 * 
 *     // resets the handle
 *     "reset": cstruct<jq_io_call_f>,
 * 
 *     // closes the handle and releases the resources
 *     "close": cstruct<jq_io_call_f>,
 * 
 *     // optional free-form describe method; if absent then default description will be printed
 *     "describe": cstruct<jq_io_call_f>,
 * 
 *     "... more methods": cstruct<jq_io_call_f>,
 *   },
 *   
 *   // optional, the normalized uri; this field will be set automatically if not provided
 *   "uri": "URI"
 * }
 */
typedef jv (*jq_io_open_f)(jq_state *, jv uri);

jv jq_io_register_scheme(jq_state * jq, const char * scheme, jq_io_open_f jq_io_open);

jv jq_io_open_handle(jq_state *jq, jv uri);
jv jq_io_handle_call(jq_state *jq, jv input, jv handle, jv method);
jv jq_io_handle_validate(jv handle);

#endif // JQ_IO_H
