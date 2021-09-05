#include "Emulator.cc"

using namespace ENHANCED;

void _v(Iterator<char>&iter){
	bool b = false;
	char chr;
	while(++iter){
		// std::cout << *iter << std::endl;
		/*
		if(*iter == '(')
		{
			_v(iter);
			--iter;
		}
		*/
		if(*iter == '('){
			try{
				_v(iter);
				--iter;
				b = true;
			}catch(int&err){
				// do nothing
			}
			if(b)
				throw 1;
		}
		else if(*iter == ')')
			throw 1;
	}
}

bool validate(std::string str){
	Iterator<char> iter;
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
	validate("(()())"); // 1
	validate("()()()("); // 0
	return 1;
}


