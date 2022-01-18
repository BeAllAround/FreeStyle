#include "./debug.h"


void inAction(){
	int i;
	for(i = 0; i < 10; i++){
		BREAK;
	}
}
int main(){
	int i;
	start_time;
	// inAction();
	for(i = 0; i < 1000000; i++)
		printf("%d\n", i);
	end_time;
	return 1;
}
