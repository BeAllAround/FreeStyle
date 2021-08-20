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


#define array(DEF, TYPE) typedef struct{ \
				TYPE *arr; \
				int size; \
			}DEF

typedef struct{
	char *root;
	int length;
}_String;

typedef _String* String;

String concat(String, String);
void _push(String, String);
String Copy(String);
String at_index(String, int);

array(string_vec, String);
typedef string_vec* StringVec;
StringVec newStringVec(int size)
{
	string_vec s;
	s.arr = (String*)malloc(size);
	s.size = 0;
	return New(string_vec, s);
}

void add(StringVec self, String item)
{
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

int compareString(String str, String rst)
{
	return compareStr(str->root, rst->root);
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

char *char_to_charP(char c)
{
	char *m = (char*)malloc(2);
	m[0] = c;
	m[1] = 0;
	return m;
}


String subString(String src, int start, int end)
{
	void _push(String, String);
	String _new = newString("");
	int i, l = 0;

	if(start >= end || start >= size(src))
		return src;
	for(i = start; i < end; i++)
		_push(_new, newString(char_to_charP(src->root[i])));
	return _new;
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

String at_index(String self, int index)
{
	return newString(char_to_charP(self->root[index]));
}

String Copy(String src)
{
	String new = newString("");
	int i;
	for(i = 0; i < size(src); i++)
		_push(new, at_index(src, i));
	return new;

}

String concat(String self, String src)
{
	String copy = Copy(self);
	_push(copy, src);
	return copy;
}

void _push(String self, String src)
{
	char *swap = self->root;
	int i, l = 0;
	self->root = malloc(1000000000);
	for(i = 0; i < strlen(swap); i++)
		self->root[l++] = *(swap+i);
	for(i = 0; i < strlen(src->root); i++)
		self->root[l++] = *(src->root+i);
	*((self->root)+l) = 0;
	self->length = l;
}

int _BRUTE(String comb, String tmp, String toFind, int n, int end, int v)
{
	if(v)
		printf("%s\n", Str(tmp));
	if(compareString(tmp, toFind))
		return 1;
	if(n == end)
		return compareString(tmp, toFind);
	for(int i = 0; i < size(comb); i++)
		if(_BRUTE(comb, concat(tmp, at_index(comb, i)), toFind, n+1, end, v))
			return 1;
	return 0;
}

int BRUTE(String comb, String toFind, int v)
{
	int i = 0;
	for(;;)
		if(_BRUTE(comb, newString(""), toFind, 0, ++i, v))
			return 1;
}
/*
int main(void){
	String s2 = readFile("module.py");

	StringVec arr = newStringVec(2);
	add(arr, newString("include"));
	add(arr, newString("import"));

	String s1 = subString(newString("WELCOME WELCOME"), 0, 10);
	printf("%s\n", Str(s1));
	printf("%d\n", s1->length);
	printf("%d\n", arr->size);
	printf("{%s}\n", Str(concat(arr->arr[0], arr->arr[1])));

	printf("{%s}\n", Str(replaceAll(s2, arr->arr[0], arr->arr[1])));
	// BRUTE(newString("aba"), newString(""), newString("abaaa"), 0, 4);
	String n = newString("SAD");
	concat(n, newString("4"));
	printf("{%s}\n", Str(n));
	printf("%d", BRUTE(newString("abc12348939399i"), newString("babi23"), 1));

	return 1;
}
*/
