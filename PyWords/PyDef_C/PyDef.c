#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "engine.h"

#define RESET str = (char*)malloc(MAXBUFFER); \
		    l = 0;_bool = 0;

static int STARTER;

STRINGArr define(STRING use){
	char* str = (char*)malloc(MAXBUFFER);
	STRINGArr arr = StringArr(MAXBUFFER);
	STRING def = String("->define ");
	int start, index, i, _bool = 0, l = 0;
	index = search(&use, def, start = 0);
	if(index != -1){
		while(index!=-1){
		for(i = index + def.length; i < use.length; i++){
			if(use.root[i] == ' '){
				if(_bool){
					add(&arr, String(str));
					RESET;
				}
				continue; // ignore
			}else if(use.root[i] == '\n'){
				add(&arr, String(str));
				RESET;
				while(use.root[++i] == ' '); // eat white space and the remaining '\n'
				index = search(&use, def, start = i);
				STARTER = start;
				break;
			}else{
				str[l++] = use.root[i];
				_bool = 1;
			}
		}
	}
	return arr;
	}
}

void Run(STRING str, char **argv){
	wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	if (program == NULL) {
		fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
		exit(1);
	}
	Py_SetProgramName(program);  /* optional but recommended */
	Py_Initialize();
	PyRun_SimpleString(CStr(str));
	if (Py_FinalizeEx() < 0) {
		exit(120);
	}
	PyMem_RawFree(program);
}

int main(int argc, char **argv){
	///////////////////////////////////////
	FILE *f = fopen(argv[1], "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

	char *string = malloc(fsize + 1);
	fread(string, 1, fsize, f);
	fclose(f);

	string[fsize] = 0;
	///////////////////////////////////////

	STRINGArr arr = define(String(string));
	STRING s1 = subString(String(string), STARTER, strlen(string));

	int looper = 0, looper_1 = 1;
	if(arr.length != 0 && (!(arr.length%2)))
		for(;;){
			if(looper_1 < arr.length){
				// printf("%s %s\n", arr.arr[looper].root, arr.arr[looper_1].root);
				s1 = replaceAll(s1.root, arr.arr[looper].root, arr.arr[looper_1].root);
				looper += 2;
				looper_1 = looper + 1;
				continue;
			}
			break;
		}
	// printf("%s\n", s1.root);
	Run(s1, argv);

	// display "->defs"
	printf("\n%d\n", arr.length);
	for(int i = 0; i < arr.length; i++){
		printf("%d: |%s|\n", i, CStr(arr.arr[i]));
	}

	return 0;
}
