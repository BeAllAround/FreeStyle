#include <vector>
#include <iostream>
#include <functional>

std::vector<std::string> split(std::string, std::string);

std::vector<std::string> split(std::string str, std::function<bool(std::string)> call){
	std::vector<std::string> v;
	int i, j;
	bool b = false;
	std::string __s;
	for(i = 0; i < str.length(); i++){
		std::string _s;
		for(j = i; j < str.length(); j++){ // for(j = 0; j < sep.length() && i+j < str.length(); j++){
			_s += str[j];
			if(call(_s)){
				b = true;
				break;
			}
		}
		if(b)
			v.push_back(__s), i += _s.length()-1, __s.clear();
		else
			__s += str[i];
		b = false;
	}
	v.push_back(__s);
	return v;
}

std::ostream&operator<<(std::ostream&o, std::vector<std::string>v){
	std::cout << '[';
	for(auto item : v)
		std::cout << '"' << item << "\", ";
	std::cout << ']';
	std::cout << std::endl;
}

int main(){
	std::cout << split("192.168.0.1..", [](std::string b){
			return b == "..";
			}) << std::endl;
	return 0;
}
