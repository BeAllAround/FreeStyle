#include<iostream>
#include<sstream>
#include "./Promise.h"

#define __ void
#define _access public:
#define _forbid private: \
		protected:
#define _THIS _1

class _1{
	_forbid
		int v;
	_access
		_THIS(int v): v{v}{}

		__ erase(__){
			_1 instance(0);
			this->operator = (instance); // or: (*this) = instance;
		}

		int value(__){
			return v;
		}
		
		__ operator>>(int& var){
			var = v;
		}

		_THIS operator<<(const int val){
			v = val;
			return *this; // a chain-like structure
		}
};

class Invoker{
	_access
		int v = 10;
		Invoker(){
			std::cout << "INVOKE\n";
		}

		Invoker(int _v){
			std::cout << "INVOKE\n";
			v = _v;
		}

		~Invoker(){
			std::cout << "YAY" <<std::endl;
		}
};

template<class T>
class smart_p{
	typedef T* P_;
	typedef T& PR;
	P_ obj;

	_access
		void *operator new(size_t) = delete;
		smart_p(P_ obj) : obj(obj){}
		~smart_p(){ delete obj; }
		PR operator*(){ return *obj; }
		P_ operator->(){ return obj; }
		smart_p<T>&operator=(const P_&_new){
			delete obj;
			obj = _new;
			return *this;
		}
};

void run(){
	std::cout << "-----------------" << std::endl;
	auto p = smart_p<Invoker>(new Invoker());
	std::cout << (*p).v << std::endl;
	p = new Invoker(55);
	std::cout << p->v << std::endl;
	std::cout << "-----------------" << std::endl;
}

int main(){
	int val;
	_1 a(101);
	std::cout << a.value() << std::endl; // 101
	a>>val; // similar to swap
	a.erase();
	std::cout << a.value() << std::endl; // 0
	a = a << 50;
	std::cout << a.value() << std::endl; // 50
	a = a << 40;

	std::cout << val << std::endl; // 101
	std::cout << a.value() << std::endl; // 40

	Invoker i1; // "INVOKE"
	Invoker* i2; // no "INVOKE"
	ECMA::Promise<Invoker*>((ECMA::wrap<Invoker*, Invoker*>)[](auto resolve, auto reject){
   	}); // it's necessary to use pointers with ECMA::Promise for now

	run();

	return 0;
}
