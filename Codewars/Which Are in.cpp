#include <algorithm>

class WhichAreIn
{

  public:
  static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2);
};

std::vector<std::string> WhichAreIn::inArray(std::vector<std::string>&array1, std::vector<std::string>&array2){
  std::vector<std::string>arr;
  std::size_t found;
  for(auto item : array1)
    for(auto jtem : array2)
      if((found = jtem.find(item))!=std::string::npos && !std::count(arr.begin(), arr.end(), item))
        arr.push_back(item);
  std::sort(arr.begin(), arr.end());
  return arr;
}

/*
  // Codewars
  #include <algorithm>

  class WhichAreIn
  {
  public:
      static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
      {
          std::vector<std::string> results;

          std::copy_if( array1.begin( ), array1.end( ), std::back_inserter( results ),
              [&](const std::string &item1) {
                  return std::any_of( array2.begin( ), array2.end( ), 
                      [&](const std::string &item2) {
                          return item2.find( item1 ) != std::string::npos;
                      } 
                  );
              } 
          );

          std::sort( results.begin( ), results.end( ) );

          return results;
      }
  };
*/
