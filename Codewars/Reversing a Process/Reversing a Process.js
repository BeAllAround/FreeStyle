function findDict(arr, c){
  for(let item of arr){
    if(item[0] == c)
      return item[1];
  }
  return -1;
}

function decode(r) {
  let ascii = 'abcdefghijklmnopqrstuvwxyz', dict = [], c = 0, _str = '', add = '';
  for(let item of ascii)
    dict.push([item, c++]);

  num = parseFloat(_str = (r.match(/^(\d+)/gi)[0]));
  _str = (r.slice(r.search(_str) + _str.length));
  for(let s of _str){
    y = (findDict(dict, s));
    for(let item of dict)
      if((item[1] * num % 26)==y)
        add+=item[0];
  }
  
  if(_str.length != add.length)
    return "Impossible to decode";
  return (add);
}
