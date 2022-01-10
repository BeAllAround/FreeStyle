#include <iostream>
#include <vector>


template<class T>
std::vector<T> execute(std::vector<T>& v, T item){
	v.push_back(item);
	return v;
}

template<class T, class...Types>
std::vector<T> execute(std::vector<T>& v, T item, Types...args){
	v.push_back(item);
	return execute(v, args...);	
}

template<class T, class...Types>
std::vector<T> _execute(Types...args){
	std::vector<T> v;
	return execute(v, args...);
}


int main(){
	// std::vector<int> v;
	auto v = _execute<int>(1, 4, 5, 6068, 800); // or, more practically, std::vector<int>({1, 4, 5, 50});
	for(auto item : v)
		std::cout << item << std::endl;
	return 0;
}
