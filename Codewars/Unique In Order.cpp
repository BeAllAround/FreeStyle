#include <string>
#include <vector>

std::vector<int> uniqueInOrder(const std::vector<int>& iterable){
  std::vector<int>arr;
  if(iterable.size()==0)
    return arr;
  int save = iterable[0];
  arr.push_back(iterable[0]);
  for(int i=1; i<iterable.size(); i++){
    if(save!=iterable[i])
      arr.push_back(iterable[i]);
    save = iterable[i];
  }
  return arr;
}

std::vector<char> uniqueInOrder(const std::string& iterable){
  std::vector<char>arr;
  if(iterable=="")
    return arr;
  char save = iterable[0];
  arr.push_back(iterable[0]);
  for(int i=1; i<iterable.length(); i++){
    if(save!=iterable[i])
      arr.push_back(iterable[i]);
    save = iterable[i];
  }
  return arr;
}


std::vector<char> uniqueInOrder(const std::vector<char>& iterable){
  std::vector<char>arr;
  if(iterable.size()==0)
    return arr;
  char save = iterable[0];
  arr.push_back(iterable[0]);
  for(int i=1; i<iterable.size(); i++){
    if(save!=iterable[i])
      arr.push_back(iterable[i]);
    save = iterable[i];
  }
  return arr;
}
