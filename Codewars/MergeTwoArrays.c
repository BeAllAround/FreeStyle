#include <stddef.h>

void merge_arrays (size_t len_a, const int a[len_a], size_t len_b, const int b[len_b], int merged[len_a + len_b])
{
  int c = 0, i, _b;
  if(len_a > len_b)
    _b = 1;
  else
    _b = 0;
  if(_b){
    for(i = 0; i < len_b; i++){
      merged[c++] = a[i];
      merged[c++] = b[i];
    }
    for(i = len_b; i < len_a; i++)
      merged[c++] = a[i];
    return;
  }
  for(i = 0; i < len_a; i++){
    merged[c++] = a[i];
    merged[c++] = b[i];
  }
  for(i = len_a; i < len_b; i++)
    merged[c++] = b[i];
  return;
}
