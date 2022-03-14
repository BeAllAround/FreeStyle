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

/*
#include <string>
#include <vector>

std::string splice(std::string, unsigned long, unsigned long);
std::string splice(std::string, unsigned long);

std::string splice(std::string str, unsigned long start = 0){
    return splice(str, start, str.length());
}

std::string splice(std::string str, unsigned long start, unsigned long end){
    std::string _new;
    unsigned long i(start);
    while(str[i] != 0 && i < end)
        _new += str[i++];
    return _new;
}


std::vector<std::string> solution(const std::string &s)
{
  std::vector<std::string>v;
  if(s == "")
    return v;
  for(unsigned long i = 0; i < s.length(); i+=2)
    v.push_back(splice(s, i, i+2));
  size_t size = v.size();
  if(v[size-1].length() == 1)
    v[size-1] = v[size-1] + "_";
  return v;
}

// Codewars
std::vector<std::string> solution(const std::string &s) {
    std::vector <std::string> res;
    for (int i = 0; i < s.length(); i += 2) res.push_back(s.substr(i, 2));
    if (s.length() % 2) res[res.size() - 1] += "_";
    return res;
}

#include <string>
#include <vector>
#include <regex>

std::vector<std::string> solution(const std::string &s)
{
    std::regex r{".."};
    auto str = s + '_';
    return {std::sregex_token_iterator(str.begin(), str.end(), r), {}};
}
*/

int main(){
	auto v = solution("");
	int t{};
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
