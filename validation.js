function findIndex(string, index, open, close){
	var c = 0;
	for(let i=index; i<string.length; i++){
		if(string[i]==open)c++;
		if(string[i]==close){
			c--;
			if(c==0)
				return i;
		}
	}
	return-1;
}

function validBraces(braces){
  let c = 0, c1=0, c2=0;
  var first, second;
  if(braces=="")return false;
  for(let i = 0; i<braces.length; i++){
    if(braces[i]=="(")c++
    if(braces[i]==")")c--;
    if(braces[i]=="{")c1++;
    if(braces[i]=="}")c1--;
    if(braces[i]=="[")c2++;
    if(braces[i]==']')c2--;

  }
  if(c==0 && c1==0 && c2==0){ // validation
      first =  true;
  }else first = false;

 if(first)
	return (looper('['+braces+']', 0, '[', ']', '{', '}', '(', ')'));
 return false;

}

function FIND(string, s, start){
	for(let i=start; i<string.length; i++){
		if(string[i]==s) 
			return i;
	}
	return-1;
}

function looper(string, start, brace, _brace, brace1, _brace1, brace2, _brace2){
	var c0, c=start;
	var inner=0, inner1=0, inner2 = 0;

	if(FIND(string, brace, c)!=-1 && findIndex(string, FIND(string, brace, c), brace, _brace)!=-1){
		c = FIND(string, brace, c);
		c0 = c;
		c = findIndex(string, c, brace, _brace);
		for(let i=c0+1; i<c; i++){
			if(string[i]==brace){
				if(findIndex(string, i, brace, _brace)==-1)
					return false;
				if(!looper(string, i, brace, _brace, brace1, _brace1, brace2, _brace2))return false;
			}
			if(string[i]==brace1){
				if(findIndex(string, i, brace1, _brace1)==-1)
					return false;
				if(!looper(string, i, brace1, _brace1, brace, _brace, brace2, _brace2))return false;

			}
			if(string[i]==brace2){
				if(findIndex(string, i, brace2, _brace2)==-1)
					return false;
				if(!looper(string, i, brace2, _brace2, brace, _brace, brace1, _brace1))return false;
			}
			if(string[i]==brace1)inner1++;
			if(string[i]==_brace1)inner1--;
			if(string[i]==brace2)inner++;
			if(string[i]==_brace2)inner--;
			if(string[i]==brace)inner2++;
			if(string[i]==_brace)inner2--;
		}
	}
	if(inner1!=0 || inner!=0 || inner2!=0)
		return false;
  return true;
}

console.log(validBraces("[({})] {}(){}(){[]}(((())))({{{{}}}})")); // true
console.log(validBraces("[] [] [((), [])]")); // true
console.log(validBraces("[] [] {[}((), [])]")); // false
console.log(validBraces("[] [] [[(](), [])]")); // false
console.log(validBraces("() [] {)")); // false
console.log(validBraces("() [] {(})")); // false
console.log(validBraces("() [] {[}]")); // false
console.log(validBraces("() [] ({)}")); // false
console.log(validBraces("() [] [{]}")); // false
console.log(validBraces("() [] ([)]")); // false
console.log(validBraces("() [] (()[)]")); // false
console.log(validBraces("() [] ((()[)(]))")); // false
console.log(validBraces("() [] {{{}(}{)}}")); // false
console.log(validBraces("() [] {{{}[}{]}}")); // false
console.log(validBraces("() [] [([[][][[]]])]")); // true
console.log(validBraces("() [] [([[(])[]()[[]]])]")); // false
console.log(validBraces("({}, {(), []},) [] [[[[]{}]{}]()]")); // true
console.log(validBraces("[] [] {[]}{} {{{{{}}}}}()[](())({)}()")); // false

// CodeWars tests
console.log("-------------------");
console.log(validBraces("(){}[]")); // true
console.log(validBraces("([{}])")); // true
console.log(validBraces("(}")); // false
console.log(validBraces("[(])")); // false
console.log(validBraces("[({})](]")); // false
console.log(validBraces(")(}{][")); // false
