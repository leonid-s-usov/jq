#include "jv.h"

typedef struct jv_refcnt {
    int count;
} jv_refcnt;

struct jvp_cstruct_header;

typedef void (*cstruct_free_f)(void *cstruct);

typedef struct jvp_cstruct_header {
  struct jv_refcnt refcnt;
  cstruct_free_f free;
  void *cstruct;
} jvp_cstruct_header;

jv jv_cstruct(void* cstruct, cstruct_free_f free);
void * jv_cstruct_copy_get_value(jv j)

