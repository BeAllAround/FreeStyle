#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <errno.h>
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define _New(name, _type) _type* name = ((_type*)malloc(1));
#define _New_init(self, value) self[0] = value;
#define _New_P(self) self + 0;
#define New(_type, value) ({ _New(_var, _type); \
	       	_New_init(_var, value); _New_P(_var); });

#define __add__(source, _push) push(&source, _push);

#define array(DEF, TYPE) typedef struct{ \
				TYPE *arr; \
				int size; \
			}DEF

typedef struct{
	char *root;
	int length;
}_String;

typedef _String* String;

array(string_vec, String);
typedef string_vec* StringVec;
StringVec newStringVec(int size){
	string_vec s;
	s.arr = (String*)malloc(size);
	s.size = 0;
	return New(string_vec, s);
}

void add(StringVec self, String item){
	self->arr[self->size++] = item;
}

String newString(char *_root)
{
	int l = 0;
	_String s;
	s.root = (char*)malloc(strlen(_root));
	while(*_root != 0)
		s.root[l++] =  *_root++;
	s.root[l] = '\0';
	s.length = l;
	return New(_String, s);
}

char *Str(String value)
{
	return value->root;
}

int size(String value)
{
	return value->length;
}

String concat(String str_1, String str_2){
	char *data = (char*)malloc(str_1->length + str_2->length + 1);
	int i, l = 0;
	i = 0;
	for(i = 0; i < str_1->length; i++)
		data[l++] = *(Str(str_1) + i);
	i = 0;
	for(i = 0; i < str_2->length; i++)
		data[l++] = *(Str(str_2) + i);
	*(data + l++) = '\0';
	return newString(data);
}

void push(String *source, String _push){
	*source = concat(*source, _push);
}

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

	if(back > strlen(_string) || (back+forward) > strlen(_string) || !forward)
		return 0;

	for(i = back; i < back+forward; i++)
		s[c++] = _string[i];

	s[c++] = '\0';
	return compareStr(s, _match);
}

int strIndex(char* s, char* t)
{
	int i, t_l = strlen(t);
	for(i = 0; s[i] != 0; i++)
		if(_trim(s, t, i, t_l))
			return i;
	return -1;
}

int _strIndex(char *s, char *t, int start)
{
	int i, t_l = strlen(t);
	for(i = start; s[i] != 0; i++)
		if(_trim(s, t, i, t_l))
			return i;
	return -1;
}


String replaceAll(String _str, String to_replace, String _replace)
{
	char *data = (char*)malloc(1000);
	int index, i, j, l = 0, c = 0;
	for(i = 0; i < size(_str); i++){
		if(_trim(Str(_str), Str(to_replace), i, size(to_replace))){
			i += size(to_replace) - 1;
			for(j = 0; j < size(_replace); j++)
				data[l++] = Str(_replace)[j];
			continue;
		}
		data[l++] = Str(_str)[i];
	}
	data[l] = '\0';
	return newString(data);
}

char *char_to_charP(char c){
	char *m = (char*)malloc(2);
	m[0] = c;
	m[1] = 0;
	return m;
}

String subString(String src, int start, int end){
	char *_new = (char*)malloc(100000);
	int i, l = 0;
	if(start >= end || start >= size(src))
		return src;
	for(i = start; i < end; i++)
		_new[l++] = src->root[i];
	return newString(_new);
}

String readFile(char* name)
{
	FILE *f = fopen(name, "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

	char *string = (char*)malloc(fsize + 1);
	fread(string, 1, fsize, f);
	fclose(f);

	string[fsize] = '\0';
	return newString(string);
}


/*
int main(void){
	String s2 = readFile("module.py");

	StringVec arr = newStringVec(2);
	add(arr, newString("include"));
	add(arr, newString("import"));

	String s1 = newString("WELCOME WELCOME");
	__add__(s1, newString(" LA LA"));
	printf("%s\n", Str(s1));
	printf("%d\n", s1->length);
	printf("%d\n", arr->size);
	printf("%s\n", Str(concat(arr->arr[0], arr->arr[1])));

	printf("{%s}\n", Str(replaceAll(s2, arr->arr[0], arr->arr[1])));

	return 1;
}
*/
