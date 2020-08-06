#ifndef JQ_IO_BUILTIN_H
#define JQ_IO_BUILTIN_H

#include "jq_io_private.h"
#include "jq_io_co.h"

#define JQ_HANDLE_SCHEME_BUILTIN "builtin"

jv jq_io_init_schemes();

#endif // JQ_IO_BUILTIN_H