#include <string.h>
#include <ctype.h>

char *alternateCase (char *string)
{
  char *str = malloc(strlen(string)), c;
  int l = 0;
  while((c = *string) != 0){
    if(isupper(c))
      str[l++] = tolower(c);
    else if(islower(c))
      str[l++] = toupper(c);
    else
      str[l++] = c;
    string++;
  }
  str[l] = 0;
  return str;
}
