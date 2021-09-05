#include <iostream>
#include <sstream>
#include <string>

void _v(std::stringstream&iter){
	static bool b = false;
	char chr;
	while(iter >> chr){
		if(chr == '('){
			try{
				_v(iter);
				b = true;
			}catch(int&err){
				// do nothing
			}
			if(b)
				throw 1;
		}
		else if(chr == ')')
			throw 1;
	}
}

bool validate(std::string str){
	std::stringstream iter;
	int i;
	for(i = 0; i < str.length(); i++)
		iter << str[i];
	try{
		_v(iter);
	}catch(int&err){
		return false;
	}
	return true;
}

int main(){
	validate("()()(())()()()()"); // 1
	validate("((())()"); // 0
	return 1;
}


