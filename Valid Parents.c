#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
