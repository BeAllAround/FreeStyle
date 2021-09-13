#include <stdlib.h>
#include <stdio.h>

char *__reverse(const char *string, char *dest, int c, int end){
        if(end == -1){
                dest[c++] = 0;
                return dest;
        }
        dest[c++] = string[end--];
        return __reverse(string, dest, c, end);
}

char *reverseString(const char *str){
        return __reverse(str, (char*)malloc(1000), 0, strlen(str)-1);
}

char* reverseWords(const char* text) {
  if(strlen(text) == 0)
    return "";
  char *toR = (char*)malloc(10000);
  char *str = (char*)malloc(1000);
  int i, j, l = 0, f_l = 0;
  for(i = 0; i < strlen(text); i++){
    if(text[i] == ' '){
      str[l++] = 0;
      str = reverseString(str);
      l = strlen(str);
      str[l++] = ' ';
      str[l] = 0;
      for(j = 0; j < l; j++)
        toR[f_l++] = str[j];
      toR[f_l] = 0;
      str = malloc(1000);
      l = 0;
      continue;
    }else if(i == strlen(text)-1){
      str[l++] = text[i];
      str[l++] = 0; 
      str = reverseString(str);
      l = strlen(str);
      for(j = 0; j < l; j++)
        toR[f_l++] = str[j];
      toR[f_l] = 0;
      str = malloc(1000);
      l = 0;
      break;
    }
    str[l++] = text[i];
  }
  free(str);
  return toR;

}
