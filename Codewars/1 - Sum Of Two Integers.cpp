#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int Add (int x, int y)
{
   vector<int> v = {x, y};
   return accumulate(v.begin(),v.end(),0);
}

/*
#include <functional>

std::plus<int> Add;
///////////////////////////////////

int Add(int x, int y)
{
    if (y == 0) return x;
    
    return Add( x ^ y, (x & y) << 1);
}
////////////////////////////////////

int Add (int x, int y)
{
  return (long)&((&((char*)NULL)[y])[x]);
}
////////////////////////////////////

int Add(int x, int y) {
  asm("add %2, %0" : "=r"(x) : "0"(x), "r"(y));
  return x;
}

/////////////////////////////////////

int32_t Add (const int32_t x,int32_t y) {
return (__builtin_add_overflow(x,y,&y),y);
}
*/
