function isEmpty(obj){
  return Object.keys(obj).length == 0;
}

function goDeep(obj, _list, n){
  if(obj instanceof Object)
    if(!isEmpty(obj)){
     n++;
     for(let name in obj){
        _list = (goDeep(obj[name],_list, n));
        _list.push(n);
     }
    }
  return _list;
}

function depth(obj) {
  var d = 0, b = false, b1 = false, arr = [];
  if (obj instanceof Array || obj === null)
    return 0;
  return (arr = goDeep(obj, [], 0)).length != 0 ? Math.max(...arr) : 0;
}
