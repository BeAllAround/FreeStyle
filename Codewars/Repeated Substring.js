function subFind(s, toFind, start){
  let i, l = start + toFind.length, str = '';
  if(l > s.length)
    return false;
  for(i = start; i < l; i++){
    str += s[i];
  }
  return str == toFind;
} 

function f_a(s, find){
  let i, str = '';
  if(find == '')
    return [];
  data = [find, 0];
  for(i = 0; i < s.length; i++){
    if(subFind(s, find, i)){
      i += (find).length - 1;
      data[1]++;
      continue;
    }
  }
  return data;
}
function maxFilter(arr){
  e = ['', 0];
  for(let item of arr)
    if(item[1] > e[1])
      e = item;
  arr = arr.filter(item => item[1] == e[1]);
  e = ['', 0];
  for(let item of arr)
    if(item[0].length > e[0].length)
      e = item;
  return (e);
}
function f(s) {
  c = 0;
  str = '';
  struct = [];
  for(let item of s){
    if(str != '')
      struct.push(f_a(s, str));
    str += item;
  }
  for(let item of struct){
    if(item[1] == 1 || item[0].length == 1)
      c++;
  }
  if(c == struct.length)
    return [s, 1];
  return maxFilter(struct);
}


// now - consecutive [ codewars! ]
function subFind(s, toFind, start){
  let i, l = start + toFind.length, str = '';
  if(l > s.length)
    return false;
  for(i = start; i < l; i++){
    str += s[i];
  }
  return str == toFind;
} 

function f_a(s, find){
  let i, str = '';
  b = true;
  if(find == '')
    return [];
  data = [find, 0];
  for(i = 0; i < s.length; i++){
    if(subFind(s, find, i) && b){
      i += (find).length - 1;
      data[1]++;
      continue;
    }else
      b = false;
  }
  return data;
}
function maxFilter(arr){
  e = ['', 0];
  for(let item of arr)
    if(item[1] > e[1])
      e = item;
  arr = arr.filter(item => item[1] == e[1]);
  e = ['', 0];
  for(let item of arr)
    if(item[0].length > e[0].length)
      e = item;
  return (e);
}
function f(s) {
  c = 0;
  str = '';
  struct = [];
  for(let item of s){
    if(str != '')
      struct.push(f_a(s, str));
    str += item;
  }
  for(let item of struct){
    if(item[1] == 1 || item[0].length == 1)
      c++;
  }
  if(c == struct.length)
    return [s, 1];
  return maxFilter(struct);
}
