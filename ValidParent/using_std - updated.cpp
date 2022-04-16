#include <sstream>
#include <cassert>

int _v(std::stringstream &iter){
	char chr;
	while(iter >> chr)
		if(chr == '('){
			if(_v(iter) != -1)
				return -2;
		}else if(chr == ')')
			return -1;
	return 0;
}

bool validate(std::string str){
	std::stringstream iter{str};
	return _v(iter) == 0;
}

void test_cases(void){
	assert(validate("(()(()(()())()))"));
        assert(!validate("((())()"));
	assert(!validate("(("));
	assert(!validate("(()"));
	assert(validate("(())"));
}

int main(){
	test_cases();
	return 1;
}
