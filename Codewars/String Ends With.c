#include <stdbool.h>
#include <string.h>

bool solution(const char *string, const char *ending)
{
  int i = strlen(string)-1, j = strlen(ending)-1;
  if(j > i)
    return false;
  for(;j >= 0; i--, j--)
    if(string[i] != ending[j])
      return false;
  return true;
}
