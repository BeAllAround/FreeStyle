#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define null NULL

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


struct Arr{ // 0 -> int; 1 -> string; 2 -> array
	int* num;
	char* string;
	int id; // make sure you identify the initializer(s) first

	struct Arr* next; // nextIndex slot
	struct Arr* arr; // Array slot
};

typedef struct Arr* Array;
typedef void* voidP;

// constructor
extern Array newArray(void);
extern Array newString(char*);
extern Array newInt(int*);

extern void append_array(Array, Array);
extern void appendArray(Array);
extern void appendInt(Array, int*);
extern void appendString(Array, char*);
extern void append(Array, Array); // universal append;

extern void newLine(void);
extern void print(Array);
extern void printAll(Array);
extern void printArray(Array);
extern int getLength(Array);
extern char* charToString(char);
extern int equals(Array, Array);
extern int includes(Array, Array);
extern int _validate(Array, Array);
extern int __validate(Array, Array);
extern int ___validate(Array, Array);

char* charToString(char c){
	char* string = (char*)malloc(2);
	string[0] = c;
	string[1] = 0;
	return string;
}

Array newArray(void){
	Array d = (Array)malloc(sizeof(struct Arr));
	d->id = 2;
	return d;
}

Array newString(char* str){
	Array d = (Array)malloc(sizeof(struct Arr));
	d->string = str;
	d->id = 1;
	return d;
}
Array newInt(int* num){
	Array d = (Array)malloc(sizeof(struct Arr));
	d->num = num;
	d->id = 0;
	return d;
}

void append(Array arr, Array item){
	if(item->id == 0)
		appendInt(arr, item->num);
	if(item->id == 1)
		appendString(arr, item->string);
	if(item->id == 2)
		append_array(arr, item); // BRP 
	return;
};

int _validate(Array node, Array _node){
	// two-way validation
	
	if(node->string == NULL && _node->string != NULL)
		return 0;
	if(node->string != NULL && _node->string == NULL)
		return 0;
	if(node->num == NULL && _node->num != NULL)
		return 0;
	if(node->num != NULL && _node->num == NULL)
		return 0;
	if(node->arr == NULL && _node->arr != NULL)
		return 0;
	if(node->arr != NULL && _node->arr == NULL)
		return 0;
	return 1;
}

int equals(Array arr, Array _arr){
	Array node = arr, _node = _arr;
	if(node == NULL && _node == NULL)
		return 1;
	if(node == NULL && _node != NULL)
		return 0;
	if(node != NULL && _node == NULL)
		return 0;
	while(node != NULL && _node != NULL){
		if(!_validate(node, _node))
			return 0;
		if(node->string && _node->string){
			if(!compareStr(node->string, _node->string))
				return 0;
		}

		if(node->num && _node->num){
			if(((int)*node->num) != ((int)*_node->num))
				return 0;
		}

		if(node->arr && _node->arr){
			if(!equals(node->arr, _node->arr)) // let's make my exit out of recursion!
				return 0;
		}

		node = node->next;
		_node = _node->next;
	}
	return 1;
}

void appendString(Array arr, char* string){
	Array last, node = arr;
	while(node != NULL){
		if(!node->next){
			last = node;
			break;
		}
		node = node->next;
	}
	// last->arr = (Array)malloc(sizeof(struct Arr));
	last->string = string;
	last->next = newArray();
}

void appendInt(Array arr, int* num){
	Array last, node = arr;
        while(node != NULL){
                if(!node->next){
                        last = node;
                }
                node = node->next;
        }
        last->num = num;
        last->next = newArray();
}

void appendArray(Array arr){
	Array last, node = arr;
	while(node != NULL){
		if(!node->next){
			last = node;
		}
		node = node->next;
	}
	last->arr = newArray();
        last->next = newArray();
}

void append_array(Array arr, Array _new){
	Array last, node = arr;
	while(node != NULL){
		if(!node->next){
			last = node;
		}
		node = node->next;
	}
	last->arr = _new;
	last->next = newArray();
}

int getLength(Array arr){
	Array node = arr;
	int c = 0;
	while(node != NULL){ // count up all the types
		if(node->string)
			c++;
		if(node->num)
			c++;
		if(node->arr)
			c++;
		node = node->next;
	}
	return c;
}

voidP atIndex(Array arr, int index){
	Array node = arr;
	int i, c = getLength(arr);

	if(index >= c){
		printf("INDEX ERROR!\n");
		return null;
	}

	for(i = 0; i < c; i++){
		if(i == index){
			if(node->arr)
				return node->arr;
			if(node->string)
				return node->string;
			if(node->num)
				return node->num;
		}
		node = node->next;
	}
	return null;
}

Array atIndexPoint(Array arr, int index){
	Array node = arr;
	int i, c = getLength(arr);

	if(index >= c){
		printf("INDEX ERROR!\n");
		return null;
	}
	for(i = 0; i < c; i++){
		if(i == index){
			if(node->arr)
				return node;
			if(node->string)
				return node;
			if(node->num)
				return node;
		}
		node = node->next;
	}
	return null;
}

void newLine(void){
	printf("\n");
}

void printAll(Array arr){
	Array node = arr;
	int i, c = getLength(arr);

	printf("[");
	for(i = 0; i < c; i++){
		if(node->string)
			printf("\"%s\"", node->string);
		if(node->num)
			printf("%d", *node->num);
		if(node->arr){
			printAll(node->arr);
		}
		if(i != c-1){
			printf(", ");
		}
		node = node->next;
	}
	printf("]");
}


void printArray(Array arr){ // redefine it with an additional line (on top of it)
	printAll(arr);
	newLine();
}

Array __removeArrays(Array arr, Array _new){
	Array node = arr;
	if((!node->string) && (!node->num) && (!node->arr))
		return _new;

	while(node != NULL){
		if(node->string)
			appendString(_new, node->string);
		if(node->num)
			appendInt(_new, node->num);
		if(node->arr)
			_new = __removeArrays(node->arr, _new);

		node = node->next;
	}
	return _new;
}

Array removeArrays(Array arr){
	return __removeArrays(arr, newArray());
}

void print(Array item){
	if(!item->string && !item->num && !item->arr){
		printf("[None]");
		newLine();
		return;
	}
	if(item->string){
		printf("%s", item->string);
		newLine();
		return;
	}
	if(item->num){
		printf("%d", *item->num);
		newLine();
		return;
	}
	if(item->arr)
		printArray(item->arr);
	return;
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

char* injectString(char* string, char* append){
	char* newBorn = (char*)malloc(strlen(string) + strlen(append) + 1); // HAHA
	int size = 0;
	int i;
	for(i = 0; i < strlen(string); i++){
		newBorn[size++] = string[i];
	}
	for(i = 0; i < strlen(append); i++){
		newBorn[size++] = append[i];
	}
	newBorn[size++] = 0;

	return newBorn;
}

int match(char* set, char* subset, int start){
	int i;
        for(i = start; i < strlen(set); i++){
                if(_trim(set, subset, i, strlen(subset)))
			return i;
        }
        return -1;
};

Array split(char* string, char* gutter){
	Array arr = newArray();
	char* stringSwap;

	if(match(string, gutter, 0) == -1){
		append(arr, newString(string));
		return arr;
	}

	stringSwap = injectString(string, gutter);
	char* empty = (char*)malloc(10000);
	int emptyLength = 0;
	int i, _gutter = strlen(gutter);

	if(gutter == ""){
		for(i = 0; i < strlen(stringSwap); i++){
			append(arr, newString(charToString(stringSwap[i])));
		}
		return arr;
	}

	for(i = 0; i < strlen(stringSwap); i++){
		if(_trim(stringSwap, gutter, i, _gutter)){
			i += _gutter - 1;
			append(arr, newString(empty));

			// clear up
			empty = (char*)malloc(10000);
			emptyLength = 0;
			continue;
		}
		empty[emptyLength++] = stringSwap[i];
	}
	return arr;
}

int includes(Array arr, Array item){
	int i;
	for(i = 0; i < getLength(arr); i++){
		if(equals(atIndexPoint(arr, i), item))
			return i;
	}
	return -1;
}

int removeObject(Array* arr, Array search){ // need to use a pointer here as [Array] is a type now
	int i;
	Array _arr = *arr, copy = newArray();
	Array item, node; // variables for rent XD

	if(includes(_arr, search) != -1){
		for(i = 0; i < getLength(_arr); i++){
			item = atIndexPoint(_arr, i);
			if(equals(item, search)){
				node = item->next;
				break;
			}else{
				if(item->string)
					appendString(copy, item->string);
				if(item->num)
					appendInt(copy, item->num);
				if(item->arr)
					append_array(copy, item->arr);
			}
		}

		while(node != NULL){
			if(node->arr)
				append_array(copy, node->arr);
			if(node->string)
				appendString(copy, node->string);
			if(node->num)
				appendInt(copy, node->num);
			node = node->next;
		}
		*arr = copy;
		return 1;
	}
	return 0;
}

int main(void){
	int value = 40, value1= 30;
	Array arr = newArray();
	Array arr1 = newArray();
	Array arr2 = newArray();

	appendString(arr, "#UP");
	appendString(arr, "#UP2");
	appendInt(arr, &value);
	appendArray(arr);
	appendString((Array)atIndex(arr, 3), "WOW!");
	appendArray((Array)atIndex(arr, 3));
	appendString((Array)atIndex(arr, 3), "###WOW!");
	appendArray((Array)atIndex(arr, 3));

	appendInt((Array)atIndex((Array)atIndex(arr, 3), 1), &value1);

	printArray(arr); // ["#UP", "#UP2", 40, ["WOW!", [30], "###WOW!", []]]
	printArray(arr = removeArrays(arr)); // ["#UP", "#UP2", 40, "WOW!", 30, "###WOW!"]

	char* S1 = (char*)atIndex(arr, 5);
	int S2 = *(int*)atIndex(arr, 2);

	printf("%s\n", S1); // "###WOW!"
	printf("%d\n", S2); // 40

	append(arr1, newArray());
	appendArray(arr2);
	appendArray(arr1);
	appendArray(arr2);
	append(atIndex(arr2, 0), newArray());
	append((Array)atIndex(arr1, 0), newArray());

	printf("EQUALS: %d\n", equals(arr, arr)); // 1
	printf("EQUALS: %d\n", equals(arr, arr1)); // 0
	printArray(arr1);
	printArray(arr2);
	printf("EQUALS: %d\n", equals(arr1, arr2)); // 1
	appendArray((Array)atIndex(arr1, 0));
	printArray(arr1);
	printArray(arr2);
	printf("EQUALS: %d\n", equals(arr1, arr2)); // 0
	printf("EQUALS: %d\n", equals(arr1, NULL)); // 0
	printf("EQUALS: %d\n", equals(NULL, NULL)); // 1

	Array new_1 = newArray();
	Array new_2 = newArray();

	appendString(new_1, "SAP");
	appendString(new_2, "PEST");
	printf("EQUALS: %d\n", equals(new_1, new_2)); // 0

	printf("----------------------------------------\n");
	appendString(arr1, "WHAT?");
	appendString(arr1, "WHATNOT");
	appendInt((Array)atIndex(arr1, 1), &S2);
	appendInt(arr1, &S2);
	printArray(arr1);
	int i;
	for(i = 0; i < getLength(arr1); i++){
		print(atIndexPoint(arr1, i));
	}
	/*
		 * [[[], []], [40], "WHAT?", "WHATNOT", 40]
		 * [[], []]
		 * [40]
       	  	 * WHAT?
    	         * WHATNOT
        	 * 40
	 */

	Array a1 = newArray();
	print(a1); // [None]

	// ENHANCED LIBRARY IMPLEMENTATION -> NOW AVAILABLE in C!!!
	printArray(split(" WHAT's next  for me ", " ")); // ["", "WHAT's", "next", "", "for", "me", ""]

	printArray(split(" WHAT's next  for me ", ""));
	// [" ", "W", "H", "A", "T", "'", "s", " ", "n", "e", "x", "t", " ", " ", "f", "o", "r", " ", "m", "e", " "]
	
	printArray(split(" WHAT's next  for me ", "   ")); // [" WHAT's next  for me "]
	Array _s = (split(" WHAT's next  for me ", " ")); // ["", "WHAT's", "next", "", "for", "me", ""]

	
	printf("----------------------------------------\n");
	Array R = newArray();
	append(R, newInt(&S2));
	printArray(R);

	Array __string = newArray();
	__string->string = """";
	while(removeObject(&_s, __string));

	append(_s, newString("."));
	append(_s, newArray());

	append((Array)atIndex(_s, 5), newInt(&S2));
	removeObject(&_s, newString("next"));

	printArray(_s); // ["WHAT's", "for", "me", ".", [40]]

	return 0;
}
