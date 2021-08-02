#include "./debug.h"


void inAction(){
	int i;
	for(i = 0; i < 10; i++){
		BREAK;
	}
}
int main(){
	inAction();
	return 1;
}
