#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "engine_1.h"

#define RESET str = (char*)malloc(MAXBUFFER); \
		    l = 0;_bool = 0;
#define MAXBUFFER 10000

static int STARTER;

StringVec define(String use){
	char* str = (char*)malloc(MAXBUFFER);
	StringVec arr = newStringVec(MAXBUFFER);
	String def = newString("->define ");
	int start, index, i, _bool = 0, l = 0;
	index = _strIndex(Str(use), Str(def), start = 0);
	if(index != -1){
		while(index!=-1){
		for(i = index + size(def); i < size(use); i++){
			if(use->root[i] == ' '){
				if(_bool){
					add(arr, newString(str));
					RESET;
				}
				continue; // ignore
			}else if(use->root[i] == '\n'){
				add(arr, newString(str));
				RESET;
				while(use->root[++i] == ' '); // eat white space and the remaining '\n'
				index = _strIndex(Str(use), Str(def), start = i);
				STARTER = start;
				break;
			}else{
				str[l++] = use->root[i];
				_bool = 1;
			}
		}
	}
	return arr;
	}
}

void Run(String str, char **argv){
	wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	if (program == NULL) {
		fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
		exit(1);
	}
	Py_SetProgramName(program);  /* optional but recommended */
	Py_Initialize();
	PyRun_SimpleString(Str(str));
	if (Py_FinalizeEx() < 0) {
		exit(120);
	}
	PyMem_RawFree(program);
}

int main(int argc, char **argv){

	String string = readFile(argv[1]);

	StringVec arr = define(string);
	String s1 = subString(string, STARTER, size(string));

	int looper = 0, looper_1 = 1;
	if(arr->size != 0 && (!(arr->size%2)))
		for(;;){
			if(looper_1 < arr->size){
				// printf("%s %s\n", arr.arr[looper].root, arr.arr[looper_1].root);
				s1 = replaceAll(s1, arr->arr[looper], arr->arr[looper_1]);
				looper += 2;
				looper_1 = looper + 1;
				continue;
			}
			break;
		}

	// printf("%s\n", s1->root);
	Run(s1, argv);

	// display "->defs"
	printf("\n%d\n", arr->size);
	for(int i = 0; i < arr->size; i++){
		printf("%d: |%s|\n", i, Str(arr->arr[i]));
	}

	return 0;
}
