function removeParentheses(s){
  let arrayFalse = [], arrayTrue = [];
  let i, item;
  let str = '';
  for(i = 0; i < s.length; i++){
    if(s[i] == '('){
      arrayTrue.push(true);
    }else if(s[i] == ')'){
      arrayFalse.push(false);
    }
    if(arrayTrue.length == arrayFalse.length){
      if(s[i] != '(' && s[i] != ')')
        str+=s[i];
    }
  }
  return str;
}
