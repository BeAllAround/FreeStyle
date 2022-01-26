char *strrev (char *str)
{
  char *s1 = str, *s2 = malloc(strlen(str)+1);
  memcpy(s2, str, strlen(str)+1);
  while(*++s2 != 0);
  while(*str != 0){
    *str++ = *--s2;
  }
  *str = 0;
  while(*s1++ != 0)
    str--;
  free(s2);
  return str;
}

char *strrev (char *str)
{
  char *s1 = str, *s2 = str, *s3 = malloc(strlen(str) + sizeof(char*));
  int l = 0;
  while(*++s2 != 0);
  while(*str++ != 0)
    s3[l++] = *--s2;
  s3[l] = 0;
  return s3;
}
/*
  char s[5] = {'A', 'A', 'A', 'B', '\0'};
  char *sss;
  printf("{%s}\n", sss = strrev("CAB")); // sss = strrev(s);
  free(sss);
*/

/*// Codewars
  #include <string.h>

  char *strrev(char *string)
  {
    for (char tmp, *p = string, *q = p + strlen(p) - 1; p < q; p++, q--)
    {
      tmp = *p, *p = *q, *q = tmp;
    }

    return string;
  }
*/
