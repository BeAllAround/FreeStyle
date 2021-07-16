#include<stdlib.h>
#include<stdio.h>

#define null NULL

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

	return 0;
}
