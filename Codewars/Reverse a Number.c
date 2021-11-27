#include <stdio.h>
#include <math.h>

long long reverse_num(long long n)
{
  char str[256], str2[256], *eptr;
  int l = 0, l2 = 0, b = 0;
  if(n < 0) // step by step from scratch!
    b = 1;
  else
    b = 0;
  sprintf(str, "%lld", llabs(n));
  while(str[l] != 0)
    l++;
  if(b)
    str2[l2++] = '-';
  int _while = 1;
  for(int i = l-1; i >= 0; i--){ // reverse!
    if(str[i] == '0' && _while)
      continue;
    if(str[i] != '-'){
      str2[l2++] = str[i];
      _while = 0;
    }
  }
  str2[l2++] = 0;
  return strtoll(str2, &eptr, 10);
}
