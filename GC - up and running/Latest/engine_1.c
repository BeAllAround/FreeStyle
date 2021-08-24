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

/*
#define _New(name, _type) _type* name = ((_type*)malloc(2));
#define _New_init(self, value) self[0] = value;
#define _New_P(self) self + 0;
#define New(_type, value) ({ _New(_var, _type); \
	       	_New_init(_var, value); _New_P(_var); });
*/


#define array(DEF, TYPE) typedef struct{ \
				TYPE *arr; \
				int size; \
			}DEF

// -fsanitize=address

struct _String{
	char *root;
	int length;
};

typedef struct _String* String;
String pool[10000];
static int pool_l = 0;
void release(){
	int i;
	for(i = 0; i < pool_l; i++){
		free(pool[i]->root);
		free(pool[i]);
	}
	pool_l = 0;
}

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
	// return New(string_vec, s);
}

void add(StringVec self, String item)
{
	self->arr[self->size++] = item;
}

String newString(char *_root)
{
	const int total_size = strlen(_root);
	int l = 0;
	String s = (String)malloc(sizeof(struct _String));
	char* __root = (char*)malloc(total_size + 1);
	if(_root == NULL){
		s->root = (char*)malloc(1);
		s->root[0] = 0;
		s->length = 0;
	}else{
		memcpy(__root, _root, total_size + 1);
		s->root = __root;
		s->length = total_size;
	}
	pool[pool_l++] = s;
	return s;
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
	String s;
	FILE *f = fopen(name, "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

	char *string = (char*)malloc(fsize + 1);
	fread(string, 1, fsize, f);
	fclose(f);

	string[fsize] = '\0';

	// swap - flip
	s = newString(string);
	free(string);
	return s;
}

String at_index(String self, int index)
{
	return newString(char_to_charP(self->root[index]));
}

String Copy(String src)
{
	/*
	String new = newString("");
	int i;
	for(i = 0; i < size(src); i++)
		_push(new, at_index(src, i));
	return new;
	*/

}

char* concat(char *n, char *self, char *src)
{
	const int total_size = strlen(self) + strlen(src);
	char* yay = (char*)malloc(total_size + 1);
	memcpy(yay + 0, self, strlen(self) + 1);
	memcpy(yay + strlen(yay), src, strlen(src) + 1);
	memcpy(n + 0, (char*)yay, total_size + 1); // overwrite whatever is left in a string pointer
	free(yay);
	return n;
}

/*
 * // usage
 * char *n = "SAD", *n1 = (char*)malloc(size);
 * for(int i = 0; i < 300; i++)
 * 	n = concat(n1, n, "44");
 * printf("{%s}\n", n); // use n
 * free(n);
*/


void _push(String self, String src)
{
	char *swap = self->root;
	int i, l = 0;
	self->root = (char*)malloc(size(self) + size(src) + 1); 
	for(i = 0; i < strlen(swap); i++)
		self->root[l++] = *(swap+i);
	for(i = 0; i < strlen(src->root); i++)
		self->root[l++] = *(src->root+i);
	*((self->root)+l) = 0;
	self->length = l;
}

typedef int(*funcPtr)(char*, char*, char*, char*, char*, char*, int, int, int);
int _f(char*, char*, char*, char*, char*, char*, int, int, int);
int useConcat(funcPtr, int, char*, char*, char*, char*, int, int, int);

int _BRUTE(char *comb, char *tmp, char *toFind, int n, int end, int v)
{ // concat in action
	if(v)
		printf("%s\n", tmp);
	if(compareStr(tmp, toFind))
		return 1;
	if(n == end)
		return 0;
	for(int i = 0; i < strlen(comb); i++){
		if(useConcat(_f, strlen(toFind) + 1, comb, tmp, char_to_charP(comb[i]), toFind, n, end, v))
			return 1;
	}
	return 0;
}

int BRUTE(char *comb, char *toFind, int v)
{
	int i = 0;
	for(;;)
		if(_BRUTE(comb, "", toFind, 0, ++i, v))
			return 1;
}

// another example of usage - engine_up.c
int useConcat(funcPtr ptr, int size, char *comb, char *tmp, char* _char, char *toFind, int n, int end, int v){
	int b;
	char *_n, *m = (char*)malloc(size);
	b = (int)ptr(m, _n, comb, tmp, _char, toFind, n, end, v);
	free(m);
	free(_char);
	return b;
}

int _f(char *m, char *_n, char *comb, char *tmp, char* _char, char *toFind, int n, int end, int v){
	if(_BRUTE(comb, _n = concat(m, tmp, _char), toFind, n+1, end, v))
		return 1;
	return 0;
}

int main(void){
	String s2 = readFile("module.py");
	s2 = readFile("module.py");
	printf("{%s}\n", s2->root);
	release();
	/*

	StringVec arr = newStringVec(2);
	add(arr, newString("include"));
	add(arr, newString("import"));

	String s1 = subString(newString("WELCOME WELCOME"), 0, 10);
	printf("%s\n", Str(s1));
	printf("%d\n", s1->length);
	printf("%d\n", arr->size);
	printf("{%s}\n", Str(concat(arr->arr[0], arr->arr[1])));

	// printf("{%s}\n", Str(replaceAll(s2, arr->arr[0], arr->arr[1])));
	// BRUTE(newString("aba"), newString(""), newString("abaaa"), 0, 4);
	*/

	// usage
	

	printf("%d\n", BRUTE("abc12348939399i", "babii4", 1));

	return 1;
}
