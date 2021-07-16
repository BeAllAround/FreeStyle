#include<stdlib.h>
#include<stdio.h>

#define null NULL


struct Arr{
	int* num;
	char* string;
	int id; // make sure you navigate the initializer(s)

	struct Arr* next;
	struct Arr* arr;
};

typedef struct Arr* Array;
typedef void* voidP;

void appendString(Array arr, char* string){
	Array last, node = arr;
	while(node != NULL){
		if(!node->next){
			last = node;
		}
		node = node->next;
	}
	// last->arr = (Array)malloc(sizeof(struct Arr));
	last->next = (Array)malloc(sizeof(struct Arr));
	last->next->string = string;
}

void appendInt(Array arr, int* num){
	Array last, node = arr;
        while(node != NULL){
                if(!node->next){
                        last = node;
                }
                node = node->next;
        }
        last->next = (Array)malloc(sizeof(struct Arr));
        last->next->num = num;
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
}

Array removeArrays(Array arr, Array new){
	Array node = arr;
	if((!node->string) && (!node->num) && (!node->arr)){
		return new;
	}
	while(node != NULL){
		if(node->string)
			appendString(new, node->string);
		if(node->num)
			appendInt(new, node->num);
		if(node->arr)
			new = removeArrays(node->arr->next, new);

		node = node->next;
	}
	return new;
}

voidP atIndex(Array arr, int index){
	Array last, node = arr;
	int c, _l = 1;
	int c1 = 0;
	// if(index>0)
		// index--; // NEED TO SOLVE THIS SOMEHOW!
	if(!index){
		if(node->arr)
			return node->arr;
		if(node->num)
			return node->num;
		if(node->string)
			return node->string;
	}

	while(node != NULL){
		if(node->string){
			// printf("%s\n", node->string); // debugging part!
			if(_l == index){
				last = node;
			}
			if(c1)
				_l++;
			c1 = 1;

		}
		if(node->num){
			// printf("%d\n", *node->num);
			if(_l == index){
				last = node;
			}
			if(c1)
				_l++;
			c1 = 1;

		}
		if(node->arr){
			// printf("[Array]\n");
			if(_l == index){
				last = node;
			}
			if(c1)
				_l++;
			c1 = 1;
		}
		node = node->next;
	}

	if(index >= _l){
		printf("\"---Index ERROR\"\n"); // exit(1);
		return null;
	}

	/*
	node = arr; // reset
	for(c = 0; c < _l; c++){
		if(index == c){
			last = node;
			break;
		}
		node = node->next;
	}
	*/
	
	if(last->arr)
		return last->arr;
	if(last->string)
		return last->string;
	if(last->num)
		return last->num;
}


void printAll(Array arr){
	Array node = arr;
	int c = 0;

	printf("[");
	while(node != NULL){
		if(node->string)
			printf("\"%s\"", node->string);
		if(node->num)
			printf("%d", *node->num);

		if(node->arr){
			printf(", ");
			printAll(node->arr);
		}

		if(c){
			if(node->next)
				printf(", ");
		}

		node = node->next;
		if(!c)
			c = 1;
	}
	printf("]");
}

void printArray(Array arr){ // redefine it with an additional line
	printAll(arr);
	printf("\n");
}


int main(void){
	Array arr = (Array)malloc(sizeof(struct Arr));
	int m = 10;
	int m1 = 11;
	int m2 = 404;
	int m3 = 40000;
	Array innerArr;

	appendString(arr, "SUPER");
	appendString(arr, "_s_");
	appendInt(arr, &m1);
	appendArray(arr);

	appendString(arr->next->next->next->arr, "SUPER!!!");
	appendString(arr->next->next->next->arr, "WHAT? ");
	appendArray(arr->next->next->next->arr);
	/*
	printf("---------------------------\n");
	printf("%s\n", arr->next->next->next->arr->next->next->string);
	printf("---------------------------\n");
	*/
	appendInt(arr->next->next->next->arr->next->next->arr, &m3);
	appendInt(arr->next->next->next->arr->next->next->arr, &m2);
	appendString(arr->next->next->next->arr->next->next->arr, "LAST");
	appendInt(arr->next->next->next->arr, &m2);


	appendInt(arr, &m);
	appendInt(arr, &m1);
	appendArray(arr);
	appendString(arr->next->next->next->next->next->arr, "WHY SO?");
	appendString(arr, "FINAL");

	printArray(arr);
	// ["SUPER", "_s_", 11, ["SUPER!!!", "WHAT? ", [40000, 404, "LAST"], 404], 10, 11, ["WHY SO?"], "FINAL"]

	Array arr1 = removeArrays(arr->next, (Array)malloc(sizeof(struct Arr)));
	printArray(arr1);
	// ["SUPER", "_s_", 11, "SUPER!!!", "WHAT? ", 40000, 404, "LAST", 404, 10, 11, "WHY SO?", "FINAL"]

	int* S1 = (int*)atIndex(arr1->next, 8);
	char* S2 = (char*)atIndex(arr1->next, 12);

	printf("%s\n", S2); // "FINAL"
	printf("%d\n", *S1); // 404
	S2 = (char*)atIndex(arr1->next, 0);
	printf("%s\n", S2); // "SUPER"

	// other tryOuts;
	printArray((Array)atIndex(arr, 3)); // ["SUPER!!!", "WHAT? ", [40000, 404, "LAST"], 404]
	printArray((Array)atIndex(arr, 6)); // ["WHY SO?"]
	printArray((Array)atIndex((Array)atIndex(arr, 3), 2)); // [40000, 404, "LAST"]
	atIndex(arr1->next, 12);
	atIndex(arr1->next, 11);
	atIndex(arr1->next, 10);
	atIndex(arr1->next, 13); // "---Index ERROR" -> void*

	return 0;
}
