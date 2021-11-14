#include <stddef.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

size_t find_longest(const char *words) {
  size_t length = 0, max_length = 0;
  char *pchar = malloc(strlen(words)+2);
  int c1 = 0;
  for(int i = 0; i < strlen(words); i++)
    pchar[c1++] = words[i];
  pchar[c1++] = ' ';
  pchar[c1++] = 0;
  char c;
  while ((c = *pchar++)) {
    if (isspace(c)) {
      if (length > max_length) {
        max_length = length;
      }
      length = 0;
    } else {
      length++;
    }
  }
  return max_length;
}
