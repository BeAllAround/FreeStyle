#include <stdlib.h>

int is_digit(char *s){
  char c;
  if(*s == '0' || !*s || atoi(s) > 255)
    return 0;
  while((c = *s++)!=0)
    if(c > '9' || c < '0')
      return 0;
  return 1;
}

int is_valid_ip(const char * addr) {
  int d = 0, l = 0;
  while(addr[l] != 0){
    if(addr[l] == '.')
      d++;
    l++;
  }
  if(d != 3)
    return 0;
  char c = 0, *m = malloc(10);
  char *m_c = m;
  while((c = *addr++) != 0){
    if(c == '.'){
      *m = 0;
      if(!is_digit(m_c))
        return 0;
      free(m_c);
      m = m_c = malloc(10);
    }else
      *m++ = c;
  }
  *m = 0;
  l = is_digit(m_c);
  free(m_c);
  if(!l)
    return 0;
  return 1;
};


/*
#include <arpa/inet.h>

int is_valid_ip(const char *addr) {
  struct sockaddr_in sockaddr;
  return inet_pton(AF_INET, addr, &(sockaddr.sin_addr)) ? 1 : 0;
}


int is_valid_ip(const char *addr)
{
 unsigned n[4], i, nc;
 
 // Must be 4 integers separated by dots:
 if( sscanf(addr, "%d.%d.%d.%d%n", &n[0], &n[1], &n[2], &n[3], &nc) != 4 )
   return 0;
   
 // Leftover characters at the end are not allowed:
 if( nc != strlen(addr) )
   return 0;
   
 // Leading zeros and space characters are not allowed:
 if( addr[0] == '0' || strstr(addr, ".0") || strchr(addr, ' ') )
   return 0;
 
 // Values > 255 are not allowed:
 for(i=0; i<4; i++)
   if( n[i] > 255 )
     return 0;
  
 return 1;
};


#include <string.h>
#include <stdio.h>

int is_valid_ip(const char * addr) {
  unsigned char a,b,c,d;
  char test[30];
  sscanf(addr, "%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
  snprintf(test, 30, "%hhu.%hhu.%hhu.%hhu", a, b, c, d);
  return strcmp(addr, test)==0;
};
*/
