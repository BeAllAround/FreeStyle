#include <iostream>

class INT{
        int n;
        public:
                INT(int _n):n{_n}{};
                operator int(){ // redirection
                        return n;
                };
                INT&operator()(int v){
                        n += v;
                        return *this;
                }
                bool operator==(int b){
                        return n == b;
                }

};

auto add(int n){
        return INT(n);
}

void print(int v){
        std::cout << v << std::endl;
}

int main(){
        std::cout << ((add(5)(4)(100)(1)) == 110) <<std::endl;
        return 0;
}  
