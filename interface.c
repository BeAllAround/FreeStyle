#include <stdio.h>

#define def(name, type) type name

def(sum(int x, int y), int){
	return x + y;
}

int main(void){
	printf("sum: %d\n", sum(91, 11));
}
