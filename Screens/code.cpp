#include <iostream>
#define _FREE(v) delete[]v

enum class Types {Option1, Option2, Option3, Option4};


template<class T>
void _copy(T *start, T *end, T *dest){ // (void *start, void *end, void *dest, size_t size) // since "void" assigns the entire new pointer address, this behavior in C is not possible and thus, we pass "size" in the function
	while(start != end)
		*dest++ = *start++;
}

int main(){
	int *n = new int[3];
	int *n1 = new int[3];
	size_t size = 0;
	n[size++] = 1;
	n[size++] = 4;
	n[size++] = 2;
	_copy(n, n + size, n1); 
	std::cout << "--------------------" << std::endl;
	_FREE(n);
	for(int i = 0; i < size; i++)
		std::cout << n1[i] << std::endl;
	std::cout << "--------------------" << std::endl;
	_FREE(n1);

	return 0;
}
