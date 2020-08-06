#ifndef JQ_IO_CO_H
#define JQ_IO_CO_H

#include "execute.h"

jv jq_io_coexpr_handle_create(jq_state *parent, uint16_t* start_pc);
jv jq_io_coeval_handle_create(jq_state *parent, jv input, jv program);

#endif // JQ_IO_CO_H
