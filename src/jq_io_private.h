#ifndef JQ_IO_PRIVATE_H
#define JQ_IO_PRIVATE_H

#include "jq_io.h"

jv jq_io_handle_make(jq_state* jq, jv uri, jv ctx);
jv jq_io_call_handle(jv handle, jv method, jv input, jv arg);

#endif // JQ_IO_PRIVATE_H
