#include<iostream>
// BASED ON THE JAVASCRIPT IMPLEMENTATION

using namespace std;

extern int findIndex(string, int, char, char);
extern bool validBraces(string);
extern bool looper(string, int, char, char, char, char, char, char);
extern int FIND(string, char, int);

int findIndex(string str, int index, char open, char close){
	int c = 0;
	for(int i=index; i<str.length(); i++){
		if(str[i]==open)c++;
		if(str[i]==close){
			c--;
			if(c==0)
				return i;
		}
	}
	return-1;
}
bool validBraces(string braces){
	int c =0, c1=0, c2=0;
	bool first, second;

	for(int i=0; i<braces.length(); i++){
		if(braces[i]=='(')c++;
		if(braces[i]==')')c--;
		if(braces[i]=='{')c1++;
		if(braces[i]=='}')c1--;
		if(braces[i]=='[')c2++;
		if(braces[i]==']')c2--;
	}

	if(c==0 && c1==0 && c2==0){
		first = true;
	}else first = false;
	if(first)
		return looper((string)"["+braces+(string)"]", 0, '[', ']', '{', '}', '(', ')');
	return false;
}
int FIND(string str, char s, int start){
	for(int i=start; i<str.length(); i++){
		if(str[i]==s)
			return i;
	}
	return-1;
}

bool looper(string str, int start, char brace, char _brace, char brace1, char _brace1,  char brace2, char _brace2){
	int c0, c=start;
	int inner=0, inner1=0, inner2=0;
	if(FIND(str, brace, c)!=-1 && findIndex(str, FIND(str, brace, c), brace, _brace)!=-1){
		c = FIND(str, brace, c);
		c0 = c;
		c = findIndex(str, c, brace, _brace);

		for(int i=c0+1; i<c; i++){
                        if(str[i]==brace){
                                if(findIndex(str, i, brace, _brace)==-1)
                                        return false;
                                if(!looper(str, i, brace, _brace, brace1, _brace1, brace2, _brace2))return false;
                        }
                        if(str[i]==brace1){
                                if(findIndex(str, i, brace1, _brace1)==-1)
                                        return false;
                                if(!looper(str, i, brace1, _brace1, brace, _brace, brace2, _brace2))return false;

                        }
                        if(str[i]==brace2){
                                if(findIndex(str, i, brace2, _brace2)==-1)
                                        return false;
                                if(!looper(str, i, brace2, _brace2, brace, _brace, brace1, _brace1))return false;
                        }
			if(str[i]==brace1)inner1++;
                        if(str[i]==_brace1)inner1--;
                        if(str[i]==brace2)inner++;
                        if(str[i]==_brace2)inner--;
                        if(str[i]==brace)inner2++;
                        if(str[i]==_brace)inner2--;

		}
	}
	if(inner1!=0 || inner!=0 || inner2!=0)
		return false;
	return true;

}

int main(){
	cout << validBraces("(") << endl;
	return 0;
}


