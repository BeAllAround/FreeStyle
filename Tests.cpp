#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <sstream>
#include <vector>


struct Node{
	int item;
	struct Node *node{NULL};
	Node()=default;
	Node(int _item){
		item = _item;
	}
};
typedef struct Node Node;
extern void show(Node*);

void append(Node*&n, int _item){
	Node*&P = n;
	if(P->item==NULL){
		P->item = _item;
		return; // dead code elimination
	}

	Node *P0 = n, *PLast{NULL};

	while(P0!=NULL){
		if(!P0->node)
			PLast = P0;
		P0 = P0->node;	
	}
	PLast->node = new Node(_item); // inject the missing node
	// PLast->node->item = _item; // and assign new data
}

extern std::ostream&show(std::ostream&, Node*);

/*
void remove(Node *&n, int _item){
	// Node *n1 = n;
	Node *Copy, *Shift{new Node}; // empty Node;
	bool first = true;
	Node **n_ = (Node**)malloc(1000);
	int l = 0;

	while(n){
		if(n->item == _item){
			// P = P1;
			// P = P->node ? P->node : NULL;
			Copy = n->node; // skip the node;
			// n_[l++] = n->node;
			//delete n;
			// Copy = P->node;
			// P = Shift->node;
			//std::cout << *P1->item << std::endl;
			break;
		}else{
			append(Shift, n->item); // else append(Shift, P->item); // save the up-current;
		}
		// n_[l++] = n;
		n = n->node;
		delete n;
		if(!first){
			P1 = P1->node;
		}else first = false;
	}
	while(Copy){
		append(Shift, Copy->item);
		// n_[l++] = Copy;
		Copy = Copy->node;
	}
	
	show(std::cout, n1);
	std::cout << std::endl;
	std::cout << "--------------------------" << std::endl;
	// n = P1;
	//delete n;
	//delete Copy;

	show(std::cout, n);
	std::cout << std::endl;
	int i = 0;
	while(i < l){
		std::cout << n_[i]->item << std::endl;
		delete n_[i];
		i++;
	}
	// delete n;
	n = Shift; // overwrite the existing variable;
	delete n_;
	return;
}
*/

std::ostream&show(std::ostream&C, Node*node){
	Node*&n = node;
	C << "[";
	while(n!=NULL){
		printf("%d", n->item);
		if(n->node)
			std::cout << ", ";
		n = n->node;
	}
	C << "]";
	return C;
}



std::ostream&operator<<(std::ostream&, Node*&);

std::ostream&operator<<(std::ostream&input, Node*&n){
	return show(input, n);
}

int main(){
	Node*n = (struct Node*)malloc(sizeof(struct Node));
	int i1 = 20;
	int i2 = 300;
	int i3 = 30;

	for(int i = 0; i < 100; i++){
		append(n, i);
	}

	// tests
	/*
	remove(n, 99);
	remove(n, 98);
	remove(n, 0);
	remove(n, 4);
	remove(n, 1);
	remove(n, 10);
	remove(n, 22);
	remove(n, 74);
	remove(n, 51);
	remove(n, 94);
	remove(n, 26);
	*/
	std::cout << n << std::endl;
	return 0;
}
