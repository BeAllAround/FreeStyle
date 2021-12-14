#include <ctype.h> 

int isUpper(char a){
  return toupper(a) == a;
}

int isLower(char a){
  return tolower(a) == a;
}

int same_case (char a, char b)
{
  if(!isalpha(a) || !isalpha(b))
    return -1;
  if((isLower(a) && isLower(b)) || (isUpper(a) && isUpper(b)))
    return 1;
  return 0;
}
