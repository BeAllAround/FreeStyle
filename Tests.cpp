#include<iostream>
#include<sstream>
#include<vector>

#include<stdlib.h>
#include<stdio.h>

struct Node{
	int*item{NULL};
	struct Node*node{NULL};
	Node()=default;
};

typedef struct Node Node;
struct Node* newNode(int*data)
{
    // Allocate memory for new node
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
 
    node->item = data;
 
    return (node);
}

void append(Node*&n, int*_item){
	Node*&P = n;
	if(P->item==NULL){
		P->item = _item;
		return; // dead code elimination
	}

	Node *P0 = n, *PLast{NULL};

	while(P0!=NULL){
		if(!P0->node){
			PLast = P0;
		}
		P0 = P0->node;	
	}
	PLast->node = new Node;
	PLast->node->item = _item;
}

void show(Node*node){
	Node*n = node;
	printf("---show---\n");
	while(n!=NULL){
		printf("%d\n", *(n->item));
		n = n->node;
	}
	printf("---show---\n");
}



int main(){
	Node*n = (struct Node*)malloc(sizeof(struct Node));
	int i1 = 20;
	int i2 = 300;
	int i3 = 30;

	for(int i =0; i<100; i++){
		append(n, new int(i));
	}

	show(n);
	return 0;
}
