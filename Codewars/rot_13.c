#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int find(char* string, int length, char c){
  int i;
  for(i = 0; i < length; i++)
    if(string[i] == c)
      return i;
  return -1;
}

char check(char c){
  char* listUpper = malloc(1000);
  char* listLower = malloc(1000);
  int i, index, length = 0, length2 = 0;

  for(i = 65; i < 91; i++)
    listUpper[length++] = i;
  for(i = 97; i < 123; i++)
    listLower[length2++] = i;
  listUpper[length++] = 0;
  listLower[length2++] = 0;
  
  if((index = find(listUpper, length, c)) != -1){
    if(index+13 >= length)
      return listUpper[index-13];
    if(index-13 < 0)
      return listUpper[index+13];
    if(index-13 == 0)
      return listUpper[0];
  }

  if((index = find(listLower, length2, c))!=-1){
         if(index+13 >= length2)
                 return listLower[index-13];
         if(index-13 < 0)
                 return listLower[index+13];
         if(index-13 == 0)
                  return listLower[0];
  }
  return c;
}

char* rot13(const char *src)
{
  char* value = malloc(1000);
  int i, length = 0;
  for(i = 0; i < strlen(src); i++)
    value[length++] = check(src[i]);
  value[length++] = 0;
  return value;
}
int main(void){
	printf("%s\n", rot13("bla bla bla"));
}
