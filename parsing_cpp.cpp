#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Object{
	public:
		string name;
		string value;
		Object(string name, string value):name{name}, value{value}{};
};

int findObject(vector<Object>arr, string name){
	int i;
	for(i = 0; i < arr.size(); i++)
		if(arr[i].name == name)
			return i;
	return -1;
	
}


vector<Object> parse(const string&str){
	char token = 0;
	string back = "", _final = "";
	vector<Object> vars;
	vars.push_back(Object("super", "s"));
	vars.push_back(Object("_s", "WELCOME"));
	vars.push_back(Object("space", " "));
	int i, b = false;
	for(i = 0; i < str.length(); i++){
		if(str[i] == ' ') // ignore
			continue;
		else if(str[i] == ';'){
			if(token == '+')
				_final += vars[findObject(vars, back)].value;
			else
				_final += vars[findObject(vars, back)].value;
			if(b)
				vars[vars.size()-1].value = _final;
			back = "";
		}
		else if(str[i] == '+'){
			token = '+';
			if(back=="")
				throw "SYNTAX ERROR";
			_final += vars[findObject(vars, back)].value;
			back = "";
		}
		else if(str[i] == '='){
			vars.push_back(Object(back, ""));
			b = true;
			back = "";
		}
		else{
			back += str[i];
		}
	}
	return vars;
}


int main(){
	string input;
	// cin >> input;
	cout << parse("new_var_111 =  _s + space + _s + space + _s + super + space;\n")[3].value;

	return 1;
};
