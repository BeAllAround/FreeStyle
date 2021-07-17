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


struct Arr{
	int* num;
	char* string;
	int id; // make sure you navigate the initializer(s)

	struct Arr* next; // nextIndex slot
	struct Arr* arr; // Array slot
};

typedef struct Arr* Array;
typedef void* voidP;

extern void printAll(Array);
extern void printArray(Array);
extern int getLength(Array);
extern int equals(Array, Array);
extern int _validate(Array, Array);
extern int __validate(Array, Array);
extern int ___validate(Array, Array);

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
			if(!equals(node->arr, _node->arr))
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
	last->next = (Array)malloc(sizeof(struct Arr));
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
        last->next = (Array)malloc(sizeof(struct Arr));
}

void appendArray(Array arr){
	Array last, node = arr;
	while(node != NULL){
		if(!node->next){
			last = node;
		}
		node = node->next;
	}
	last->arr = (Array)malloc(sizeof(struct Arr));
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
	printf("\n");
}

Array __removeArrays(Array arr, Array new){
	Array node = arr;
	if((!node->string) && (!node->num) && (!node->arr))
		return new;

	while(node != NULL){
		if(node->string)
			appendString(new, node->string);
		if(node->num)
			appendInt(new, node->num);
		if(node->arr)
			new = __removeArrays(node->arr, new);

		node = node->next;
	}
	return new;
}

Array removeArrays(Array arr){
	return __removeArrays(arr, (Array)malloc(sizeof(struct Arr)));
}

int main(void){
	int value = 40, value1= 30;
	Array arr = (Array)malloc(sizeof(struct Arr));
	Array arr1 = (Array)malloc(sizeof(struct Arr));
	Array arr2 = (Array)malloc(sizeof(struct Arr));
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

	appendArray(arr1);
	appendArray(arr2);
	appendArray(arr1);
	appendArray(arr2);
	appendArray((Array)atIndex(arr2, 0));

	printf("EQUALS: %d\n", equals(arr, arr)); // 1
	printf("EQUALS: %d\n", equals(arr, arr1)); // 0
	printArray(arr1);
	printArray(arr2);
	printf("EQUALS: %d\n", equals(arr1, arr2)); // 0
	appendArray((Array)atIndex(arr1, 0));
	printArray(arr1);
	printArray(arr2);
	printf("EQUALS: %d\n", equals(arr1, arr2)); // 1

	return 0;
}
