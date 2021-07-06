#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int compareStr(char* str, char* rst)
{
	int i;
	if(strlen(str) != strlen(rst))
		return 0;
	for(i = 0; i < strlen(str); i++){
		if(str[i] != rst[i])
			return 0;
	}
	return 1;
}

int _trim(char* _string, char* _match, int back, int forward)
{
	char* s = (char*)malloc(10000); // set the indefinite value
	int i, c = 0;

	if(back > strlen(_string) || (back+forward) > strlen(_string))
		return 0;

	for(i = back; i < back+forward; i++){
		s[c++] = _string[i];
	};
	s[c++] = 0;
	return compareStr(s, _match);
}

typedef struct{
	char* str;
}Date;

Date newDate(char*str)
{
	return(Date){str};
}

char* crop(char* str, int start, int end){
	char* m = (char*)malloc(10000); // somewhat of a value;
	int c = 0;
	int i;
	if(start >= end)
		return"";
	for(i=start; i < end; i++){
		m[c++] = str[i];
	}
	m[c++] = 0;
	return m;
}

char* parse(char* str, ...)
{ // you need the first argument to start with
	char* data = (char*)malloc(10000);
	int l = 0;
	int date = strlen("%date");
	int i;

	for(i = 0; i < strlen(str); i++){
		if(_trim(str, "%date", i, date)){
			i += date - 1; 
			continue;
		}
		data[l++] = str[i];
		// printf("%s\n", crop(str, i, 5));

	}
	data[l++] = 0;
	return data;
}


int main(){
	Date d = newDate("3/21/2021");
	printf("%s", parse("dddd%date%date%date %date d %date %date %date s %dates -\n", &d));

	return 0;
}
