#include <stdio.h>
#include <stdlib.h>


struct Py_{
	int v;
};
typedef struct Py_* Py;

Py f_m[100];
static int f_l = 0;

void release(){
	int i;
	for(i = 0; i < f_l; i++){
		// printf("%d", f_m[i]->v);
		// free(f_m[i]->otherP);
		free(f_m[i]);
		f_m[i] = NULL;
	}
	f_l = 0;
}

Py newPy(int v){
	Py p = (Py)malloc(sizeof(struct Py_));
	p->v = v;
	f_m[f_l++] = p;
	return p;
}


int main(){
	Py p = newPy(4);
	Py p1 = newPy(40);
	Py p2 = newPy(301);
	printf("{%d}\n", p->v);
	release();
	return 1;
}
