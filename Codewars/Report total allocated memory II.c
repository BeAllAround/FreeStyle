#include <stdlib.h>

unsigned long long get_ = 0;
unsigned long long array[1000];
void *array_memory[1000];
unsigned long long l = 0, lm = 0;

unsigned long long get_currently_allocated_size(void){
  return get_;
}

void *mem_alloc(size_t size){
  void* _malloc = malloc(size);
  if(_malloc != NULL){
    get_ += size;
    array[l++] = size;
    return array_memory[lm++] = _malloc;
  }
}

void mem_free(void*m){
  int index;
  if(m!=NULL){
    for(index = 0; index < lm; index++)
      if(array_memory[index] == m) // void* == void*
        break;
    get_ -= array[index];
    array[index] = 0;
    free(m);
  }
}
