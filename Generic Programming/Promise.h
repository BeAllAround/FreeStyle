#include<iostream>
#include<string>

#define _RETURN return
#define THIS this
#define _STRING string
#define _THROW(message) throw(_STRING(message));
#define _VOID_ void

/*
 * DEVELOPED ESPECUALLY FOR JAVASCRIPT ADDICTS, including myself!
 */

using namespace std;

template<class call, class...types>using _function = call(*)(types...);

//////////////////////////////////////////////////////////////////////////////
template<typename T,class TR=T> // the same embedded definition/implementation - like a JS engine;
class scope{
	template<class...types>using _TYPEC = _function<_VOID_, _function<_VOID_, T>, _function<_VOID_, TR>, types...>;

	protected:private:
		T returnValue;
		TR rejector;
		bool c = false;
		// string state = "pending...";
		static scope<T, TR>instance;
		static int staticConstructor;

	        T resolveBack(T arg){
			return arg;
		};
		TR rejectBack(TR arg){
			return arg;

		};

		void _resolve(T args){
			if(!c){
				returnValue = resolveBack(args);
				c = true;
			}
		};

		void _reject(TR args){
			if(!c){
				rejector = rejectBack(args);
				c = true;
			}
		};

		const void reset(void){ //
			instance.returnValue = T{};
			instance.rejector = TR{};
			instance.c = 0;
		};

		static void auxiliaryResolver(T);
		static void auxiliaryRejector(TR);


		scope(_VOID_); // cloak the constructor;
	public:
		template<class...types>
			scope(_TYPEC<types...> callback, types...args){
				scope();
				callback(auxiliaryResolver, auxiliaryRejector, args...);
			}

		static scope<T, TR> resolve(T);
		static scope<T, TR> reject(TR);

		template<class C, class...types>
			scope<T, TR>*then(C, types...);

		scope<T, TR>* then(void);

		T& await(void);

		template<typename...types>
			static scope<T, TR> async(_function<T, types...>, types...);
};

template<class T, class TR>
int scope<T, TR>::staticConstructor{0};

template<class T, class TR>
scope<T, TR> scope<T, TR>::instance{};

template<class T, class TR>
scope<T, TR> scope<T, TR>::resolve(T item){
	scope<T, TR> _instance{}; // reset;
	auxiliaryResolver(item); // scope<T>::auxiliaryResolver(item);
	return _instance;
};

template<class T, class TR>
scope<T, TR> scope<T, TR>::reject(TR item){
	scope<T, TR> _instance{}; // reset;
	auxiliaryRejector(item);
	return _instance;
};

template<class T, class TR>
void scope<T, TR>::auxiliaryResolver(T item){
	return instance._resolve(item);
};

template<class T, class TR>
void scope<T, TR>::auxiliaryRejector(TR item){
	return instance._reject(item);
};


template<class T, class TR> // specification;
template<typename C, typename...types>
scope<T, TR>* scope<T, TR>::then(C callback, types...args){
	//__check(); // needless - for now;
	callback(instance.returnValue, instance.rejector, args...);
	_RETURN THIS;
};

template<class T, class TR>
scope<T, TR>* scope<T, TR>::then(){
	_RETURN THIS;
};

template<class T, class TR>
T& scope<T, TR>::await(){
	return instance.returnValue;
};

template<class T, class TR>
scope<T, TR>::scope(_VOID_){
	reset();
};

template<class T, class TR>
template<class...types>
scope<T, TR> scope<T, TR>::async(_function<T, types...>callback, types...args){
	return resolve(callback(args...));
};


namespace ECMA{
	template<class T, class TR=T>
		using Promise = scope<T, TR>;
	
	template<class TYPE_, class TYPE__, typename...types>
		using wrap = _function<void, _function<void, TYPE_>, _function<void, TYPE__>, types...>;

	template<class TYPE_, typename...types>
		using wrapAsync = _function<TYPE_, types...>;
};

//////////////////////////////////////////////////////////////////////////////


/*
int main(void){ // usage;
	int f_ = 42;++f_;
	auto s = new ECMA::Promise<int*, char*>((ECMA::wrap<int*, char*, int*>)[](auto resolve, auto reject, auto outside){
			resolve(outside);
			reject("SUPERB");
	}, &f_);
	s->then([](auto resolve, auto reject){
			if(resolve)
				cout << resolve << endl;
			if(reject)
				cout << reject << endl;
	});
	auto s2 = new ECMA::Promise<int*, int>((ECMA::wrap<int*, int, int*>)[](auto resolve, auto reject, auto V){
			resolve(V);
	}, new int(23));
	cout << s2->await() << endl;

	cout << ECMA::Promise<int*>::async((ECMA::wrapAsync<int*>)[](){
			return new int(11+10);
	}).await() << endl;

	cout << ECMA::Promise<char*>::async((ECMA::wrapAsync<char*>)[](){
			return(char*)"DIMINISH";
	}).await() << endl;

	ECMA::Promise<int*>::resolve(new int(22)).then([](auto resolve, auto reject){
			cout << resolve << endl;
			cout << (reject==NULL) <<endl; // 1
	});

	return 0;
};
*/
