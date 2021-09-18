#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int compareStr(char* str, char* rst)
{
	int i;
	if(strlen(str) != strlen(rst))
		return 0;
	for(i = 0; i < strlen(str); i++)
		if(str[i] != rst[i])
			return 0;
	return 1;
}

int _trim(char *_string, char *_match, int back, int forward)
{
	char *s = (char*)malloc(back + forward + 1); // set the indefinite value
	int i, c = 0;

	if(back > strlen(_string) || (back+forward) > strlen(_string) || !forward){
		free(s);
		return 0;
	}

	for(i = back; i < back+forward; i++)
		s[c++] = _string[i];

	s[c] = 0;
	c = compareStr(s, _match);
	free(s);
	return c;
}

int strIndex(char *s, char *t)
{
	int i, t_l = strlen(t);
	for(i = 0; s[i] != 0; i++)
		if(_trim(s, t, i, t_l))
			return i;
	return -1;
}

typedef struct{
	char* str;
}Date;

Date newDate(char *str)
{
	return(Date){str};
}

char* crop(char *str, int start, int end)
{
	char* m = (char*)malloc(10000); // somewhat of a value;
	int c = 0;
	int i;
	if(start >= end)
		return"";
	for(i = start; i < end; i++)
		m[c++] = str[i];
	m[c] = 0;
	return m;
}

char* parse(char* str, ...)
{ // you need the first argument to start with
	char* data = (char*)malloc(10000);
	int l = 0, c = 0;
	int date = strlen("%date");
	int i, j;
	char*_date;

	// set up various arguments package
	va_list argptr;
	va_start(argptr, strlen(str));

	for(i = 0; i < strlen(str); i++){
		if(_trim(str, "%date", i, date)){
			i += date - 1; 
			_date = (((Date*)va_arg(argptr, void*))->str);
			for(j = 0; j < strlen(_date); j++)
				data[l++] = _date[j];
			continue;
		}
		data[l++] = str[i];

	}
	va_end(argptr);
	data[l] = 0;
	return data;
}


int main(){
	Date d = newDate("3/21/2021");
	Date d1 = newDate("3/22/2021");
	char *str;
	printf("%s", str = parse("TODAY: %date\nTOMORROW: %date\n", &d, &d1));

	printf("%d\n", strIndex("super", "superr"));
	free(str);

	return 0;
}
