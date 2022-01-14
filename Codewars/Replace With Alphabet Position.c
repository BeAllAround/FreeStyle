#include <stdlib.h>
#include <string.h>

char *alphabet_position(const char *text) {
  char c;
  char *s = malloc(1000), *_s = malloc(2);
  long l = 0;
  while(c = tolower(*text)){
    if(c - 96 > 0 && c - 96 < 27){
      sprintf(_s, "%d", c-96);
      while(*_s){
        s[l++] = *_s;
        ++_s;
      }
      s[l++] = ' ';
    }
    text++;
  }
  s[l-1] = 0;
  return s;
}
