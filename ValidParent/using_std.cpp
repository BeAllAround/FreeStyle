#include <iostream>
#include <sstream>
#include <string>
/*
// codeWars source code
#include <sstream>

class Error{
  public:
    Error()=default;
};

class Error_2{
  public:
      Error_2()=default;
};

void _v(std::stringstream&iter){
  bool b = false, b1 = false, b2 = false;
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
    else if(chr == '['){
      try{
        _v(iter);
        b1 = true;
      }catch(Error&err){};
      if(b1)
        throw Error();
    }else if(chr == ']')
      throw Error();
    if(chr == '{'){
      try{
        _v(iter);
        b2 = true; 
      }catch(Error_2&err){};
      if(b2)
        throw Error_2();
    }else if(chr == '}')
      throw Error_2();
  }
}

bool valid_braces(std::string str){
  std::stringstream iter(str);
  try{
    _v(iter);
  }catch(...){
    return false;
  }
  return true;
}
*/
void _v(std::stringstream&iter){
	bool b = false;
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


