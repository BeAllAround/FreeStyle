#include <stdio.h>

#define TEST() void TESTS()

extern void RUN();
extern void TESTS();
extern int main();

void __attribute__((destructor)) RUN();


void RUN(){
        printf("Running Tests...\n");
	TESTS();
	main();
}
int main(){return 0;};
