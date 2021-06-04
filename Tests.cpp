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
extern void show(Node*);

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
	PLast->node = new Node; // inject the missing node
	PLast->node->item = _item; // and assign new data
}

void remove(Node*&n, int _item){
	Node*&P = n;
	Node*Copy, *Shift{new Node}; // empty Node;

	while(P!=NULL){
		if(*(P->item) == _item){
			Copy = P->node; // skip the node;
			break;
		}else append(Shift, P->item); // save the up-current;
		P = P->node;
	}
	while(Copy!=NULL){
		append(Shift, Copy->item);
		Copy = Copy->node;
	}

	n = Shift; // overwrite the existing variable;
	return;
}

void show(Node*node){
	Node*&n = node;
	std::cout << "[ ";
	while(n!=NULL){
		printf("%d, ", *(n->item));
		n = n->node;
	}
	std::cout << "]";
}



std::ostream&operator<<(std::ostream&, Node*&);

std::ostream&operator<<(std::ostream&input, Node*&n){
	show(n);
	return input;
}

int main(){
	Node*n = (struct Node*)malloc(sizeof(struct Node));
	int i1 = 20;
	int i2 = 300;
	int i3 = 30;

	for(int i =0; i<100; i++){
		append(n, new int(i));
	}

	// tests
	remove(n, 99);
	remove(n, 0);
	remove(n, 4);
	remove(n, 1);
	remove(n, 10);
	remove(n, 22);
	remove(n, 74);
	remove(n, 51);
	remove(n, 94);

	std::cout << n << std::endl;
	return 0;
}
