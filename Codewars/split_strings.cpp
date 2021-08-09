#include <sstream>
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> trans(const std::string& s){
  unsigned long i, j, size = s.length();
  std::string _s;
  std::vector<std::string>__s;
  for(i = 0; i < size; i++){
      if(i + 2 <= size){
	      for(j = 0; j < 2; j++){
		      if(size != i+j){
			      _s += s[i+j];
			      if(size != i+j)
				      i = i+j;
		      }
	      }
      }else{
	     _s = s[i];
	     _s += "_";
      }
      __s.push_back(_s);
      _s = "";
  }
  return __s;
}

std::vector<std::string>solution(const std::string &s)
{
  return trans(s);
}

std::ostream&operator<<(std::ostream&o, std::vector<std::string>const v){
	int i;
	for(i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;
	return o;
}

int main(){
	auto v = solution("");
	int t = 0;
	std::cout << "TEST# " << ++t << std::endl;
	std::cout << v;
	std::cout << "TEST# " << ++t << std::endl;
	v = solution("ab");
	std::cout << v;
	std::cout << "TEST# " << ++t << std::endl;
	v = solution("abc");
	std::cout << v;
	std::cout << "TEST# " << ++t << std::endl;
	v = solution("abcd");
	std::cout << v;
	std::cout << "TEST# " << ++t << std::endl;
	v = solution("abcdf");
	std::cout << v;
}
