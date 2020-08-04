#ifndef JQ_HANDLE_H
#define JQ_HANDLE_H

#include "jq_plugin.h"
#include "jv_internal.h"

#define JQ_HANDLE_SCHEME_BUILTIN "builtin"

jv jq_init_io_schemes(struct jq_io_table* builtin);

#endif // JQ_HANDLE_H