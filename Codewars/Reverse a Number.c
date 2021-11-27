#include <stdio.h>
#include <math.h>

long long reverse_num(long long n)
{
  char str[256], str2[256], *eptr;
  int l = 0, l2 = 0, b = 0, _while = 1;
  if(n < 0) // step by step from scratch!
    b = 1;
  else
    b = 0;
  sprintf(str, "%lld", llabs(n));
  while(str[l] != 0)
    l++;
  for(int i = l-1; i >= 0; i--){ // reverse!
    if(str[i] == '0' && _while)
      continue;
    str2[l2++] = str[i];
    _while ? _while = 0 : NULL;
  }
  str2[l2++] = 0;
  return b ? -strtoll(str2, &eptr, 10) : strtoll(str2, &eptr, 10);
}
