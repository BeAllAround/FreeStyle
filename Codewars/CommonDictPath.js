function print(...v){
  console.log(...v);
}

function checker(v){
  _v = v[0];
  for(let i = 1; i < v.length; i++){
    if(_v[0] != v[i][0])
      return '';
    if(_v[0] == v[i][0])
      try{
         if((_v.match(/(\w+)/g)[0] != v[i].match(/(\w+)/g)[0]))
          return '/';
      }catch(error){
        return '/';
      }

  }
  return '$';
}

function getCommonDirectoryPath(pathes) {
  arr = [];
  check = '';
  str_c = '';
  str = '';
  let j, i; 
  if((check = checker(pathes)) != '$')
    return check;
  path = pathes[0];
  for(j = 1; j < pathes.length; j++){
    path1 = pathes[j];
    c = 0, c1 = 0;
    while(path[c] === path1[c1] && c < path.length){
      str += path[c];
      c++;
      c1++;
    } 
    i = str.length-1;
    while(str[i]!='/')
          i--;
    str_c = str = (str.slice(0, i+1));
    arr.push(str_c);
    str = '';
  }
  _max = ['', Number.POSITIVE_INFINITY];
  for(item of arr)
        if(item.length < _max[1])
                _max = [item, item.length];
  return _max[0];
}
/* // reintegrated
function getCommonDirectoryPath(pathes) {
  arr = [];
  check = '';
  str_c = ['', Number.POSITIVE_INFINITY];
  str = '';
  let j, i; 
  if((check = checker(pathes)) != '$'){
    return check;
  }
  path = pathes[0];
  for(j = 1; j < pathes.length; j++){
    path1 = pathes[j];
    c = 0, c1 = 0;
    while(path[c] === path1[c1] && c < path.length){
      str += path[c];
      c++;
      c1++;
    } 
    i = str.length-1;
    while(str[i]!='/')
          i--;
    str = str.slice(0, i+1);
    if(str.length < str_c[1])
      str_c = [str, str.length];
    str = '';
  }
  return str_c[0];
}
*/
