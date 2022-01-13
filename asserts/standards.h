#include <stdio.h>
#include <stdlib.h>

#define shift(m, l) ++m, --l

/*
  // USAGE - for example:
  int main()
  {
      int *m = malloc(100);
      size_t l = 0;
      m[l++] = 10;
      m[l++] = 11;
      m[l++] = 12;

      // shift(m, l);
      // shift(m, l);

      for(int i = 0; i < 3; i++){
          printf("%d\n", m[0]);
          shift(m, l);
      }
      return 0;
  }
*/
