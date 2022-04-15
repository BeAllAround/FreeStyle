#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int findIndex(char *s, char c, int size){
  for(int i = 0; i < size; i++)
    if(s[i] == c)
      return i;
  return -1;
}

bool permute_a_palindrome(const char *str_in) {
  char *s = malloc(100), item;
  int *l = malloc(100);
  int c = 0, v = 0, inx;
  while((item = *str_in++))
    if((inx = findIndex(s, item, c)) == -1)
      s[c] = item, l[c] = 1, c++;
    else
      l[inx]++;
  for(int i = 0; i < c; i++)
    if(l[i] % 2 != 0)
      v++;
  free(s), free(l);
  return v == 1 || v == 0;
}

/*
#include <stdbool.h>

bool permute_a_palindrome(const char *str_in) {
  long s = 0;
  for (; *str_in; str_in++) {
    s ^= 1L << (*str_in - 'A');
  }
  return (s & (s - 1)) == 0;
}

#include <stdbool.h>

#define NALPHA  26

bool permute_a_palindrome(const char *s)
{
    char tab[NALPHA] = { 0 };
    int i, c;
    while (c = *s++)
        ++tab['z' - c];
    for (i = c = 0; i < NALPHA; ++i)
        if ((c += tab[i] & 1) && c > 1)
            return false;
    return true;
}


#include <stdbool.h>

bool permute_a_palindrome(const char *str_in) 
{
  int i;
  int mask = 0;
  for (i = 0; str_in[i]; ++i)
  {
    mask ^= 1 << (str_in[i] & 0x1f);
  }
  return __builtin_popcount(mask) == (i&1);
}


#include <stdbool.h>
#include <stdlib.h>

bool permute_a_palindrome(const char *str) {
  size_t odds = 0, i;
  int counts[26] = { 0 };
  while (*str) counts[*str++ - 97]++;
  for (i = 0; i < 26; i++) odds += counts[i] & 1;
  return odds < 2;
}
*/
