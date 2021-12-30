std::vector<int> tribonacci(std::vector<int> signature, int n)
{
  int l = signature.size();
  std::vector<int> result;
  if(n!=0)
    result = signature; // std::copy;
  if(n == 2 || n == 1){
    for(int _ = 1; _ < (n==1 ? n+2 : n); _++)
      result.pop_back();
    return result;
  }
  for(int i = 0; i < n-l; i++)
    result.push_back(result[result.size()-1] + result[result.size()-2] + result[result.size()-3]); 
  return result;
}
