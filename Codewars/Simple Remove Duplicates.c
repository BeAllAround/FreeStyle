#include <stdlib.h>

int findIndex(const int*arr, size_t s_arr, const int item){
  size_t i;
  for(i = 0; i < s_arr; i++)
    if(arr[i] == item)
      return i;
  return -1;
}

int* solve(const int* arrin, size_t szin, size_t *szout) {
  int* arrout = malloc(1000), *arr_o = malloc(1000);
  size_t i, l = 0, c = 0;
  for(i = szin-1; i > 0; i--)
    if(findIndex(arrout, l, arrin[i])==-1)
      arrout[l++] = arrin[i];
  if(findIndex(arrout, l, arrin[i])==-1)
      arrout[l++] = arrin[i];
  for(i = l-1; i > 0; i--)
    arr_o[c++] = arrout[i];
  arr_o[c++] = arrout[i];
  *szout = c;
  free(arrout);
  return arr_o;
}

/*
  // Codewars
  #include <stdlib.h>
  #include <stddef.h>

  int *solve(const int* a, size_t n, size_t *m) {
    int *r = (int *)calloc(n, sizeof(int)), i = 0;
    for (int j = 0; j < n; j++) {
      int k = j + 1;
      for (; k < n; k++) if (a[k] == a[j]) break;
      if (k == n) r[i++] = a[j];
    }
    return (int *)realloc(r, (*m = i) * sizeof(int));
  }
  
  
  #include <stdlib.h>
  #include <string.h>

  int strocc(const int* array, size_t size, int c)
  {
      int counter = 0;

      for (size_t i = 0; i < size; i++)
          if (array[i] == c)
              counter++;

     return counter;
  }

  int* solve(const int* arrin, size_t szin, size_t *szout)
  {
      int* arrout;

      *szout = 0;
      arrout = calloc(szin, sizeof(int));
      if (!arrout)
          return NULL;

      for (size_t i = 0; i < szin; i++) {
          if (strocc(&arrin[i], szin - i, arrin[i]) == 1) {
              arrout[*szout] = arrin[i];
              (*szout)++;
          }
      }

      int* temp = realloc(arrout, (*szout) * sizeof(int));
      if (!temp) {
          free(arrout);
          return NULL;
      }
      arrout = temp;

      return arrout;
  }
*/
