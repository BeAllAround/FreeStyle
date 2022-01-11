#include <stdlib.h>

static size_t mem_bytes = 0;
unsigned long long get_currently_allocated_size(void) {
  return mem_bytes;
}

void *mem_alloc(size_t size) {
  size_t *ptr = malloc(sizeof(size_t) + size);
  if (ptr) {
    *ptr = size;
    mem_bytes += size;
    return &ptr[1];
  } else {
    return NULL;
  }
}

void mem_free(void *ptr) {
  if (ptr) {
    mem_bytes -= ((size_t*)ptr)[-1];
    free((size_t*)ptr - 1);
  }
}
