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

#define XRANGE(index, start, end) for(int index=start;index<end;++index)
#define true 1
#define false 0
#define MAXBUFFER 1000000

#define AUTHOR " AM "

/*
	gcc/g++ [file1].c -o [file1] -w -std=c11;
*/


static void DESCRIPTION(void){
	printf("\n---------------------------------------\n");
	printf("AUTHOR: %s(19)"\
		"", AUTHOR);
	printf("\n---------------------------------------\n");
};

typedef struct S{
	char*root;
	int length;
}STRING;
STRING String(char*root){ // STRING from CStr. //
	int l = 0;
	while(root[l]!=0)++l;
	return(STRING){root, l};
};
STRING StringConst(const char*root){
	char*rootH =(char*)(strlen(root));
	strcpy(rootH, root);
	return(STRING){rootH, strlen(rootH)};
};
STRING StringChar(const char r){
	char*out = (char*)malloc(1);
	out[0] = r;
	return(STRING){out, 1};
};
/*
STRING*newString(char*root){
	STRING**s = (STRING**)malloc(1);
	STRING string = String(root);
	s[0] = &string;
	return(const STRING*)s[0];
};
*/
STRING concat(STRING receiver, STRING S){
	int Rl = receiver.length, Sl = S.length;
	char*inject =(char*)malloc(Rl+Sl+1);
	long long push = 0;
	int i=0;
	while(i<Rl){
		inject[push++] = receiver.root[i];
		i++;
	};
	i = 0;
	while(i<Sl){
		inject[push++] = S.root[i]; 
		i++;
	};
	inject[push++] = 0;
	return(const STRING)String((char*)inject);
	
};

void push(STRING*receiver, char s){
	char*buffer = (char*)malloc(receiver->length+1);
	long long push = 0;
	int i =0;
	while(i<receiver->length){
		buffer[push++] = receiver->root[i];++i;
	};
	buffer[push++] = s;
	// buffer[push++] = 0;
	receiver->root=(char*)buffer;
	receiver->length = push;
	return;
};
void append(STRING*receiver, STRING s){
	int i = 0;
	for(i=0; i<s.length; i++){
		push(receiver, s.root[i]);
	};
	return;
};

int search(const STRING*outer, const STRING inner, int from){
	int match = 0;
	int i = 0;
	int i1 = 0;
	for(i=from; i<outer->length; i++){
		for(i1=0; i1<inner.length;++i1){
			if(outer->root[i+i1]==inner.root[i1])++match;
			if(match==inner.length)return(const int)i; //
		};
		match = 0; // reset. //
	};
	return-1;
};

STRING get(STRING*s, int index){
	if(index>=s->length)return(const STRING)String("");
	char*m = (char*)malloc(2);
	m[0] = s->root[index];
	m[1] = 0;
	return(const STRING)String(m); //
};
int StringCompare(STRING str1, STRING str2){
	return!(strcmp(str1.root, str2.root));
};
STRING subString(STRING str, int from, int to){
	int i = 0;
	char*m = (char*)malloc(to-from);
	long long push = 0;
	if(from<0 && to>=str.length)return String(""); // dummy //
	for(i=from; i<to;++i){
		m[push++] = (const char)(*(str.root+i));
	};
	return(const STRING)String(m);
};
STRING replaceString(STRING str, STRING toReplace, STRING Replace){
	STRING deepConcat(STRING, const char*, ...); // declare. //
	int index;
	index = search(&str, toReplace, 0); //
	if(index!=-1){
		str = deepConcat(subString(str, 0, index), "ss", Replace, subString(str, index+toReplace.length, str.length));
		return(const STRING)str;
	};
	return(const STRING)String("");
};
const char*CStr(STRING object){
	return(const char*)object.root;
};

STRING replaceAll(STRING str, STRING toReplace, STRING Replace){
	STRING deepConcat(STRING, const char*, ...);
	int index;
	index = search(&str, toReplace, 0);
	if(index==-1)return String(str.root); // dummy. //
	while(index!=-1){
		str = deepConcat(subString(str, 0, index), "ss", Replace, subString(str, index+toReplace.length, str.length));	
		index = search(&str, toReplace, (index+Replace.length));
	};
	return(const STRING)str;
};



STRING deepConcat(STRING s, const char*format, ...){
	int i = 0;
	int size = strlen(format);
	va_list argptr;
	va_start(argptr, size);
	for(i=0; i<size;++i){
		if(format[i]=='s'){
			(s = concat(s, (const STRING)va_arg(argptr, STRING)));
		};
	};
	va_end(argptr); // free(delete) //
	if(!size)return(const STRING)String("");
	return(const STRING)s;
};

typedef struct A{
	STRING*arr;
	int length;	
}STRINGArr;

void add(STRINGArr*arr, STRING item){
	arr->arr[arr->length] = item;
	arr->length += 1;
	return;
}

STRINGArr StringArr(const int size){
	return (STRINGArr){(STRING*)malloc(size), 0};
}

STRINGArr CArrayToStringArray(int length, char**arr){
	STRINGArr s = (STRINGArr){(STRING*)malloc(MAXBUFFER), 0};
	int push = 0;
	for(int i=0; i<length; i++){
		s.arr[push++] = String(arr[i]);
		s.length = push;
	};
	return s;
}

int countString(const STRING s, const STRING toCount){
	int index, countS=0;
	index = search(&s, toCount, 0);
	while(index!=-1){
		countS++;
		index = search(&s, toCount, index+toCount.length);
	};
	return(const int)countS; //
};

STRING join(STRINGArr arr, STRING gutter){
	STRING s = String("");
	for(int i=0; i<arr.length; i++){
		if(i==0){
			s = concat(s, concat(String(""), arr.arr[i]));
		}else s = concat(s, concat(gutter, arr.arr[i]));	
		
	}
	return s;
}

STRINGArr reduce(STRINGArr arr, int start, int end){
	STRINGArr New = StringArr(MAXBUFFER);
	int push = 0;	
	for(int i=start; i<end; i++){
		New.arr[push++] = arr.arr[i];
	}	
	New.length = push;
	return New;
}

int startsWith(STRING str, STRING pre)
{
    return strncmp(CStr(pre), CStr(str), pre.length) == 0;
}

int StringToInt(const STRING s){
	return atoi(s.root); //
};

// inline void readyFunctions(void){
extern void DESCRIPTION(void);
extern STRING String(char*);
extern STRING concat(STRING, STRING);
extern void push(STRING*, char); 
extern void append(STRING*, STRING);
extern int search(const STRING*, STRING, int); 
extern STRING get(STRING*, int);
extern int StringCompare(STRING, STRING); 
extern const char*CStr(STRING); 
extern STRING deepConcat(STRING, const char*, ...); 
extern int startsWith(STRING, STRING);
extern STRING subString(STRING, int, int); 
extern STRING replaceString(STRING, STRING, STRING);
extern STRING replaceAll(STRING, STRING, STRING); 
extern int countString(const STRING, const STRING); 
extern int StringToInt(const STRING);
extern STRINGArr StringArr(const int size); 
extern STRINGArr CArrayToStringArray(int, char**);
extern STRING join(STRINGArr, STRING); 
extern void add(STRINGArr*, STRING);
/*	XRANGE(index, start, end);	*/
// };
