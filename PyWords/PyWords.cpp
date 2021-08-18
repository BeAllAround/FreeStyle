#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// -I/usr/include/python3.8 -lpython3.8 --std=c++14;


static int STARTER;

using namespace std;

int search_2(std::string, std::string, int);

const std::vector<std::string> define(std::string use){
	string str = "";
	vector<string>arr;
	string def = "->define ";
	int start, index, i, _bool = 0, l = 0;
	index = search_2(use, def, start = 0);
	if(index != -1){
		while(index != -1)
			for(i = index + def.length(); i < use.length(); i++){
				if(use[i] == ' '){
					if(_bool){
						arr.push_back(str);
						str = "";
						l = 0;
						_bool = 0;
					}
					continue; // ignore
				}else if(use[i] == '\n'){
					arr.push_back(str);
					str ="";
					l = 0;
					_bool = 0;
					while(use[++i] == ' '); // eat white space and the remaining '\n'
					index = search_2(use, def, start = i);
					STARTER = start;
					break;
				}else{
					str += use[i];
					_bool = 1;
				}
			}
		return arr;
	}
}

std::string openFile(char *name){
	std::ifstream _file(name);
	std::string str((std::istreambuf_iterator<char>(_file)), std::istreambuf_iterator<char>());
	if(_file.is_open())
		return str;
	else
		throw "CAN'T ACCESS!";
}

void Run(std::string str, char **argv){
	wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	if (program == NULL) {
		fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
		exit(1);
	}
	Py_SetProgramName(program);  /* optional but recommended */
	Py_Initialize();
	PyRun_SimpleString(str.c_str());
	if (Py_FinalizeEx() < 0) {
		exit(120);
	}
	PyMem_RawFree(program);
}

int search_2(std::string _str, std::string toFind, int start){
	if(start > _str.length() || _str.length() < 0)
		return -1;
	int i, j, n = 0;
	for(i = start; i < _str.length(); i++){
		for(j = 0; j < toFind.length(); j++)
			if(_str[i+j] != toFind[j])
				break;
		if(j == toFind.length())
			return i;
	}
	return -1;
};

std::string replace_all(std::string _str, string toReplace, string value){
	int index = search_2(_str, toReplace, 0);
	while(index != -1){
		_str.replace(index, toReplace.length(), value);
		index = search_2(_str, toReplace, index + toReplace.length());
	}
	return _str;

};

int main(int argc, char **argv){
	string fileContent = openFile(argv[1]) + " ";
	vector<string> arr = define(fileContent);
	string s1 = fileContent.substr(STARTER, fileContent.length());
	int looper = 0, looper_1 = 1;
	if(arr.size() != 0 && (!(arr.size()%2)))
		for(;;){
			if(looper_1 < arr.size()){
				s1 = replace_all(s1, arr[looper], arr[looper_1]);
				looper += 2;
				looper_1 = looper + 1;
				continue;
			}
			break;
		}
	Run(s1, argv);
	printf("\n%d\n", arr.size());
	for(int i = 0; i < arr.size(); i++){
		printf("%d: |%s|", i, arr[i].c_str());
	}

	return 0;
}
