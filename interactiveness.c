#include<stdio.h>
#include<stdlib.h>

int trim(char*str, char*toMatch, int start){
	if(start > strlen(str) || (start+strlen(toMatch)) > strlen(str))return-1;

	char*_str = (char*)malloc(10000);
	int length = 0;
	for(int i=start; i<strlen(toMatch); i++){
		_str[length++] = str[i];
	}
	_str[length++] = 0;
	return!strcmp(_str, toMatch);
}

int findString(char*str, char*toFind, int start){
	if(start > strlen(str))return-1;
	for(int i =0; i<strlen(str); i++){
		if(trim(str, toFind, i))
			return i;
	}
	return-1;
}

int findBraces(char*str, int start){
	int i, c = 0;
	for(i=start; i<strlen(str); i++){
		if(str[i]=='(')c++;
		if(str[i]==')'){
			c--;
			if(c==0)
				return i;
		}
	}
	return-1;
}

int checkIfString(char*s){
	int i1;
	if(s[0] == '-') i1 = 1;
	else i1 = 0;

	int i = 0; // swap;

	for(i = i1; i<strlen(s); i++){
		if( (int)s[i] > 57 || (int)s[i] < 48 ){
			return 0;
		};
	};
	return 1;
};

char*BOOL(int i){
	if(i)
		return"true";
	return"false";
}

int main(){
	char*function1 = "ifNum(";

	char*str = (char*)malloc(1000);
	char*out = (char*)malloc(1000);
	int outLength = 0;
	while(1){
		printf("> ");
		scanf("%s", str);
		if(trim(str, function1, 0)!=-1){
			int value = findString(str, function1, 0)+strlen(function1);
			int i;
			if(findBraces(str, 0)==-1){
				printf("SYNTAX ERROR!\n");
				continue;
			}
			for(i=value; i<findBraces(str, 0); i++){
				out[outLength++] = str[i];
			}
			printf("%s\n", BOOL(checkIfString(out)));

			// clear up
			outLength = 0;
			str = (char*)malloc(1000);
			out = (char*)malloc(1000);
		}
	}
	return 1;
}
