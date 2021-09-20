#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define null NULL
#define RETURN return
#define CASE if
#define BREAK break
#define TRUE 1
#define FALSE 0
#define WHILE while

#define isArray(o) o->id == 2
#define isString(o) o->id == 1
#define isNum(o) o->id == 3
#define isEmpty(o) !getLength(o)


// compatible with gcc and clang
//

int compareStr(char* str, char* rst)
{
	int i;
	CASE(strlen(str) != strlen(rst))
		return 0;
	for(i = 0; i < strlen(str); i++){
		CASE(str[i] != rst[i])
			return 0;
	}
	return 1;
}


struct Arr{ // 0 -> int; 1 -> string; 2 -> array (WARNING: STILL UNSAFE!)
	int* num;
	char* string;
	int id; // make sure you identify the initializer(s) first

	struct Arr* next; // nextIndex slot
	struct Arr* arr; // Array slot
};

typedef struct Arr* Array;
typedef void* voidP;
typedef Array(*__CALL)(Array, Array, int);

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
extern int __equals(Array, Array);

extern char* getCStr(Array);
extern Array split(char*, char*); // runs perfectly

// struct allocators
extern int* embedInt(int const);
#define _New(name, _type) _type* name = ((_type*)malloc(sizeof(_type)));
#define _New_init(self, value) *(self+0) = value;
#define _New_P(self) self + 0;
#define New(_type, value) ({ _New(_var, _type); \
	       	_New_init(_var, value); _New_P(_var); });

int* embedInt(int const _int){
	return New(int, _int);
}

Array reduce(Array arr, __CALL callback){
	Array copy = newArray(), call, node = arr;
	int c = 0;
	while(node != NULL){
		CASE(!(!node->arr && !node->string && !node->num && !node->next))
			CASE(call = callback(arr, node, c))
				append(copy, call);
		node = node->next;
		c++;
	}
	return copy;
}

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
	d->id = 3;
	return d;
}

void append(Array arr, Array item){
	CASE(item->id == 3)
		appendInt(arr, item->num);
	CASE(item->id == 1)
		appendString(arr, item->string);
	CASE(item->id == 2)
		append_array(arr, item); // BRP 
};

int _validate(Array node, Array _node){
	// two-way validation
	
	CASE(node->string == NULL && _node->string != NULL)
		return 0;
	CASE(node->string != NULL && _node->string == NULL)
		return 0;
	CASE(node->num == NULL && _node->num != NULL)
		return 0;
	CASE(node->num != NULL && _node->num == NULL)
		return 0;
	CASE(node->arr == NULL && _node->arr != NULL)
		return 0;
	CASE(node->arr != NULL && _node->arr == NULL)
		return 0;
	return 1;
}

int equals(Array arr, Array _arr){
	Array node = arr, _node = _arr;
	CASE(node == NULL && _node == NULL)
		return 1;
	CASE(node == NULL && _node != NULL)
		return 0;
	CASE(node != NULL && _node == NULL)
		return 0;
	while(node != NULL && _node != NULL){
		CASE(!_validate(node, _node))
			return 0;
		CASE(node->string && _node->string){
			if(!compareStr(node->string, _node->string))
				return 0;
		}

		CASE(node->num && _node->num){
			if(((int)*node->num) != ((int)*_node->num))
				return 0;
		}

		CASE(node->arr && _node->arr){
			CASE(!equals(node->arr, _node->arr)) // let's make my exit out of recursion!
				return 0;
		}

		node = node->next;
		_node = _node->next;
	}
	return 1;
}

void appendString(Array arr, char* string)
{
	Array last, node = arr;
	while(node != NULL){
		if(!node->next){
			last = node;
			break;
		}
		node = node->next;
	}
	last->id = 1;
	last->string = string;
	last->next = (Array)malloc(sizeof(struct Arr));
}

void appendInt(Array arr, int* num)
{
	Array last, node = arr;
        while(node != NULL){
                if(!node->next){
                        last = node;
                }
                node = node->next;
        }
	last->id = 3;
        last->num = num;
	last->next = (Array)malloc(sizeof(struct Arr));
}

void appendArray(Array arr)
{
	Array last, node = arr;
	while(node != NULL){
		if(!node->next){
			last = node;
		}
		node = node->next;
	}
	last->id = 2;
	last->arr = newArray();
	last->next = (Array)malloc(sizeof(struct Arr));
}

void append_array(Array arr, Array _new){
	Array last, node = arr;
	while(node != NULL){
		if(!node->next){
			last = node;
		}
		node = node->next;
	}
	last->id = 2;
	last->arr = _new;
	last->next = (Array)malloc(sizeof(struct Arr));
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

Array atIndexPoint(Array arr, int index)
{
	Array node = arr;
	int i, c = getLength(arr);

	if(index >= c){
		printf("INDEX ERROR!\n");
		return null;
	}
	for(i = 0; i < c; i++){
		if(i == index){
			if(node->arr || node->string || node->num)
				return node;
		}
		node = node->next;
	}
	return null;
}

Array __atIndex(Array arr, int index)
{
	Array node = arr;
        int i, c = getLength(arr);

        if(index >= c){
                printf("INDEX ERROR!\n");
                return null;
        }
        for(i = 0; i < c; i++){
                if(i == index){
                        if(node->id == 2)
                                return node;
                        if(node->id == 1)
                                return node;
                        if(node->id == 3)
                                return node;
                }
                node = node->next;
        }
        return null;
}

void newLine(void)
{
	printf("\n");
}

void printAll(Array arr)
{
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


void printArray(Array arr)
{ // redefine it with an additional line (on top of it)
	printAll(arr);
	newLine();
}

Array __removeArrays(Array arr, Array _new)
{
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

Array removeArrays(Array arr)
{
	return __removeArrays(arr, newArray());
}

void print(Array item)
{
	if(!item->string && !item->num && !item->arr && !item->next){
		printf("[None]");
		newLine();
		return;
	}
	if(item->arr){
		printArray(item->arr);
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

char* injectString(char* string, char* append)
{
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

int match(char* set, char* subset, int start)
{
	int i;
        for(i = start; i < strlen(set); i++){
                if(_trim(set, subset, i, strlen(subset)))
			return i;
        }
        return -1;
};

Array split(char* string, char* gutter)
{
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
	Array node = arr;
	int i;
	while(node != NULL){
		CASE(isEmpty(node) && isEmpty(item)) // solving the empty-array problem;
			RETURN FALSE; // nothing to search for
		CASE(__equals(node, item))
			RETURN TRUE;
		node = node->next;
	}
	RETURN FALSE;
}

void __append(Array arr, Array obj){ // auxiliary to [append]
	if(isString(obj) || isNum(obj)){
		append(arr, obj);
		RETURN;
	}

	if(isArray(obj)){
		if(getLength(obj) == 0)
			append_array(arr, obj);
		else
			append_array(arr, obj->arr);
		RETURN;
	}
	
}

int A_Validate(Array arr){
	return arr->arr == NULL;
}

int __equals(Array node1, Array node2){
	if(isArray(node1))
		return equals(node1->arr, node2);
	return equals(node1, node2);
}

int removeObject(Array* arr, Array search){ // need to use a pointer here as [Array] is a type now
	int i;
	Array _arr = *arr, copy = newArray();
	Array item, node; // variables for rent XD
	Array _node = *arr;

	if(includes(_node, search)){
		while(_node != NULL){
			if(__equals(_node, search)){
				node = _node->next;
				break;
			}else // looking to finally implement [append]
				__append(copy, _node);
			_node = _node->next;
		}

		while(node != NULL){
			__append(copy, node);
			node = node->next;
		}
		*arr = copy;
		return 1;
	}
	return 0;
}

Array __includesObjects(Array arr, Array obj, Array _new){
	Array node = arr;
	while(node != null){
		if(equals(node, obj))
			append(_new, newInt(embedInt(TRUE)));
		if(node->arr)
			_new = __includesObjects(node->arr, obj, _new);
		node = node->next;
	}
	return _new;
}

Array includesObjects(Array arr, Array obj){
	Array _new;
	_new = __includesObjects(arr, obj, newArray());
	if(getLength(obj) == 0)
		removeObject(&_new, newInt(embedInt(TRUE)));
	return _new;
}

char* getCStr(Array obj){
	if(isString(obj))
		return obj->string;
	return null;
}

Array callback1(Array arr, Array item, int index){
	if(isString(item))
		if(!compareStr(getCStr(item), " "))
			return item;
	return null;
}

int removeAll(Array* arr, Array item){
	int _bool = FALSE, i, VAL = TRUE;

	WHILE(VAL){
		(i = removeObject(arr, item));	
		CASE(i)
			_bool = TRUE;
		CASE(!i)
			VAL = FALSE;
	}
	RETURN _bool;
}
char *readFile(char* name)
{
        FILE *f = fopen(name, "rb");
        if(!f){
                exit(0);
        }
        fseek(f, 0, SEEK_END);
        long fsize = ftell(f);
        fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

        char *string = (char*)malloc(fsize + 1);
        fread(string, 1, fsize, f);
        fclose(f);

        string[fsize] = '\0';
        return string;
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
	append((Array)atIndex(arr2, 0), newArray());
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
	append(arr1, newString("WHAT?"));
	append(arr1, newString("WHATNOT"));
	append((Array)atIndex(arr1, 1), newInt(&S2));
	append(arr1, newInt(&S2));
	printArray(arr1);
	int i;
	for(i = 0; i < getLength(arr1); i++){
		print(atIndexPoint(arr1, i));
		printf("ID: %d\n", atIndexPoint(arr1, i)->id);
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
	printf("\nBEFORE DEBUG\n");
	printArray(_s);
	
	printf("----------------------------------------\n");
	Array R = newArray();
	append(R, newInt(&S2));
	append(R, newArray());
	printArray(R);


	if(removeAll(&_s, newString("")));
	append(_s, newArray());
	append(_s, newString("."));

	append((Array)atIndex(_s, getLength(_s)-2), newInt(&S2));
	append((Array)atIndex(_s, getLength(_s)-2), newArray());
	printArray(_s);

	removeObject(&_s, newString("next"));

	if(removeObject(&_s, R)){
		printArray(_s); // ["WHAT's", "for", "me", "."]
	}

	R = newArray();
	Array _var;
	append(R, newString("CLIMB"));
	append(R, newString("@CLIMB"));
	append(R, newArray());
	append(R, newArray());
	append((Array)atIndex(R, 2), newString("HA!"));
	append((Array)atIndex(R, 3), newArray());
	append((Array)atIndex((Array)atIndex(R, 3), 0), newArray());
	append(_var = (Array)atIndex((Array)atIndex(R, 3), 0), newString("mE"));
	printArray(R);
	

	append(R, newArray());
	append(R, newArray());
	Array __R = newArray();
	append(__R, newString("HA!"));

	if(removeObject(&R, __R))
		printArray(R);
	if(removeObject(&R, newString("CLIMB")))
		printArray(R);
	if(removeObject(&R, newString("@CLIMB")))
		printArray(R);

	printf("-------------------------------------------\n");

	if(removeAll(&R, newArray()))
		printArray(R);


	
	Array __var = newArray();
	append(__var, _var);

	if(removeObject(&R, __var))
		printArray(R); // []

	Array next = split("WHAT's  THAT?", "");
	append(next, newInt(&S2));
	append(next, newInt(&S2));
	printArray(next);
	next = reduce(next, callback1);
	append(next, newArray());
	append((Array)atIndex(next, 11), newString("T"));
	printArray(next); 
	// ["W", "H", "A", "T", "'", "s", "T", "H", "A", "T", "?", ["T"]]
	printArray(includesObjects(next, newArray())); // [1]
	printArray(includesObjects(next, newString("?"))); // [1]
	printArray(includesObjects(next, newString("T"))); // [1, 1, 1, 1]

	if(removeObject(&next, (Array)atIndex(next, 11)))
		printArray(next);

	// ["W", "H", "A", "T", "'", "s", "T", "H", "A", "T", "?"]

	/*	
	char* code = malloc(1000);
	scanf("%s", code); // "304,405,302,401,4045,3104,401"
	printArray(split(code, ","));
	// ["304", "405", "302", "401", "4045", "3104", "401"]
	*/
	
	return 0;
}
