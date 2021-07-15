#include<stdlib.h>
#include<stdio.h>

struct Arr{
	int* num;
	char* string;
	int* id;

	struct Arr* next;
	struct Arr* arr;
};

typedef struct Arr* Array;

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
	last->next->num = NULL;
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
	last->next->string = NULL;
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

void printAll(Array arr){
	Array node = arr;
	int c = 0;

	printf("[");
	while(node != NULL){
		if(node->string)
			printf("\"%s\"", node->string);
		if(node->num)
			printf("%d", *node->num);
		if(c){
			if(node->next)
				printf(", ");
		}
		if(node->arr){
			printAll(node->arr);
			printf(", ");
		}

		node = node->next;
		c = 1;
	}
	printf("]");
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
	appendInt(arr->next->next->next->arr, &m2);


	appendInt(arr, &m);
	appendInt(arr, &m);
	appendArray(arr);

	printAll(arr);
	printf("\n");

	return 0;
}
