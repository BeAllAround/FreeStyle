#include <iostream>

using namespace std;

class INT{
        public:
        int n;
                INT(int _n):n{_n}{};
  
                INT(INT&other) : n{other.n} {};
                INT(INT&&other) : n{other.n} {};
  
                INT operator()(int v){
                        return INT(n+v);
                }
  
                bool operator==(const int other){
                  return n==other;
                }
  
                bool operator!=(const int other){
                  return n!=other;
                  }
  
                bool operator==(const INT other){
                  return n == other.n;
                }
  
    bool operator<(const int other) const
    {
        return n == other;
    }
    bool operator>(const int other) const
    {
      return n == other;
      }
  
    INT operator+(const int other) const
      {
      
      return INT(n+ other);
    }
    INT operator-(const int other) const
      {
      return INT(n-other);
      }
  
    INT operator*(const int other) const
      {
      return INT(n* other);
      }
  
    INT operator/(const int other) const
      {
      return INT(n/ other);
      }
  
                INT& operator=(INT other) {
                  n = other.n;
                  return *this;
                }
  
                operator int() const{ // const IMPORTANT!
                  return n;
                }
  
                INT& operator=(int other) {
                  n = other;
                  return *this;
                }
  /*
                */

};

ostream&operator<<(ostream&S, const INT& b) {
 S << b.n;
 return S; 
}

INT _add(int n)
{
  return n;
}

#define add(n) _add(n)
// #define add(n) (int)_add(n)
// #define add(n)(n1) (INT)_add(n)(n1)
