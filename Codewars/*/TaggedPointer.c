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

/*
  // other solutions
  #include <stdlib.h>

  unsigned long long uTotal; //sorry i was too lazy to not cheat.
  unsigned long long get_currently_allocated_size(void) { return uTotal; }
  void *mem_alloc(size_t size) { return uTotal += size , (void*)(size^0xAA55AA55AA55AA55); }
  void mem_free(void* addr) { uTotal -= ((size_t)addr)^0xAA55AA55AA55AA55; }
  
  /////////////
  #include <stdlib.h>

  static struct node {
      struct node *next;
      const void *pointer;
      size_t size;
  } *memroot = NULL;

  void add_node(const void *p, size_t sz) {
      struct node *n = malloc(sizeof *n);
      n->pointer = p;
      n->size = sz;
      n->next = memroot;
      memroot = n;
  }

  void del_node(const void *p) {
      struct node *current = memroot, *last = NULL;

      while (current) {
          if (current->pointer == p) {
              if (last)
                  last->next = current->next;
              else
                  memroot = NULL;

              free(current);

              break;
          }

          last = current;
          current = current->next;
      }
  }

  size_t get_currently_allocated_size(void) {
      size_t total = 0;
      struct node *n = memroot;

      while (n) {
          total += n->size;
          n = n->next;
      }

      return total;
  }

  void *mem_alloc(size_t size) {
      void *p = malloc(size);
      add_node(p, size);
      return p;
  }

  void mem_free(void *p) {
      del_node(p);
      free(p);
  }
*/
