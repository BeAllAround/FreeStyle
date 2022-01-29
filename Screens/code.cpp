#include <iostream>
#include <memory>


// "-fsanitize=address and -fsanitize=leak" tested
#define _FREE(v) delete[]v

enum class Types {Option1, Option2, Option3, Option4};


template<class T>
void _copy(T *start, T *end, T *dest){ // (void *start, void *end, void *dest, size_t size) // since "void" assigns the entire new pointer address, this behavior in C is not possible and thus, we pass "size" in the function
	if(end < start) // in case we get (end + -n) - apparently not available in the std::copy;
		return;
	while(start != end)
		*dest++ = *start++;
}

#define __CLEAN delete[] data_c;
template<class T>
void _insert(T *&data, unsigned index, size_t& size, T item){
	T *data_c = new T[size + 1];
	if(index >= size){
		_copy(data, data + size, data_c);
		*(data_c + size++) = item;
		delete[]data;
		_copy(data_c, data_c + size, data = new T[size]);
	}else{
		_copy(data + 0, data + index, data_c);
		*(data_c + index++) = item;
		_copy(data + index-1, data + size++, data_c + index);
		delete[]data;
		_copy(data_c, data_c + size, data = new T[size]);
	}
	__CLEAN
}

int main(){
	int *n = new int[3];
	int *n1 = new int[30];
	size_t size = 0;
	n[size++] = 1;
	n[size++] = 4;
	n[size++] = 2;
	_insert(n, 4, size, 5);
	// _insert(n, 0, size, 5);
	// std::cout << size << std::endl;
	// _insert(n, 3, size, 65);

	_copy(n, n + size, n1);
	// _copy(n, n + size, n1); 
	std::cout << "--------------------" << std::endl;
	_FREE(n);
	for(int i = 0; i < size; i++)
		std::cout << n1[i] << std::endl;
	std::cout << "--------------------" << std::endl;
	_FREE(n1);

	return 0;
}
