#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define freeList(list, size) for(int i =0; i < size; i++) \
		free(list[i]);	free(list);
#define start_time clock_t s_t_a_r_t = clock();
#define end_time printf("[Cpu_time_used: %f]\n", ((double) (clock() - s_t_a_r_t)) / CLOCKS_PER_SEC);

char *string(){
	char *m = malloc(10);
	m[0] = 'a';
	m[1] = 'b';
	m[2] = 'y';
	m[3] = 0;
	return m;
}

int main(){
	long l = 0, l1 = 0;
	start_time;
	char ** restrict list = malloc(10000000), **m1 = malloc(10000000);
	for(int i = 0; i < 1000000; i++)
		list[l++] = string();
	for(int i = 0; i < l; i++){
		char *s = malloc(10);
		memcpy(s, list[i], strlen(list[i]) + 1);
		free(list[i]);
		m1[l1++] = s;
	}
	free(list);
	// freeList(list, l); // free up the first array
	

	// for(int i = 0; i < l; i++)
		// printf("%s\n", list[i]);
	/*
	printf("-------------------------\n");
	for(int i = 0; i < l1; i++) // show the copied array of data
		printf("%s ", m1[i]);
	

	printf("\n");
	*/
	freeList(m1, l);

	
 	end_time;
	return 0;
}
