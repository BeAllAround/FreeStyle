#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

char * _slice(char *s){
  int size = strlen(s), i; // cache so that you don't have to call it twice
  char *stream, *m;
  stream = m = malloc(size == 0 ? 0 : size);
  for(i = 1; i < size; i++)
    *stream++ = s[i];
  *stream = 0;
  return m;
}

int _v(char **str){
  char c, *s;
  while((c = *(*(str))++) != 0){
    if(c == '('){
      // s = _slice(*str);
      // int b = _v(&s);
      // free(s);
      if(_v(str) != -1)
        return -2;
    }else if(c == ')')
      return -1;
  }
  return 0;
}

bool validParentheses(char *str_in) {
  return _v(&str_in) == 0;
}

/*
int _v(char *str, int *c){
  char _c;
  ++*c;
  while((_c = str[*c]) != 0){
    if(_c == '('){
      if(_v(str, &*c) != -1)
        return -2;
    }else if(_c == ')')
      return -1;
    ++*c;
  }
  return 0;
}

bool validParentheses(char *str_in) {
  int c = -1;
  return _v(str_in, &c) == 0;
}
*/
