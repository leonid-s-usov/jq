
#ifndef JQ_IO_H
#define JQ_IO_H

#include "jq.h"

typedef struct jq_io_stat {
  int open:1;
  int eof:1;
} jq_io_stat;

typedef jv (*jq_hclose_f)(jq_state *, jv cdata, jv input);
typedef jv (*jq_hreset_f)(jq_state *, jv cdata, jv input);
typedef jq_io_stat (*jq_hstat_f)(jq_state *, jv cdata, jv input);
typedef jv (*jq_hio_f)(jq_state *, jv cdata, jv input, jv arg);

struct jq_io_table {
  jq_hio_f io;
  jq_hstat_f stat;
  jq_hreset_f reset;
  jq_hclose_f close;
};

// should return an object of type cstruct
// the cstruct must have jq_io_table as the first item
typedef jv (*jq_hopen_f)(jq_state *, jv uri);

jv jq_io_handle_register_scheme(jq_state * jq, const char * scheme, jq_hopen_f open);

jv jq_io_handle_open(jq_state *jq, jv uri);
jv jq_io_handle_close(jq_state *jq, jv jhandle, jv input);
jv jq_io_handle_reset(jq_state *jq, jv jhandle, jv input);
jv jq_io_handle_io(jq_state *jq, jv jhandle, jv input, jv arg);
jv jq_io_handle_stat(jq_state *jq, jv jhandle, jv input);

#endif // JQ_IO_H
