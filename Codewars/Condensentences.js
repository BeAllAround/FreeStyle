function _concat(str1, str2){
  let s = str1.split('');
  let _s = '', a = [];
  let i, v;
  for(let _ of str2){
    _s += _;
    a.push([_s, _s.length, str1.endsWith(_s)]);
  }
  a = a.filter(v=>v[2] == true);
  let _a = (a.reduce((a,b)=>{
    if(b[1] > a[1])
      return b;
    return a;
  }, ['', 0, false]));
  for(let j = 0; j < _a[0].length; j++)
    s.pop();
  return s.join('') + str2;
}

const condense = (str) =>{
  if(str == '')
    return '';
  let str1 = str.split(' ').filter(v=>v!='');
  let s = str1[0];
  for(let i = 1; i < str1.length; i++)
    s = _concat(s, str1[i]);
  return s;
}
