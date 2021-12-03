function isEmpty(obj){
  return Object.keys(obj).length == 0;
}

function goDeep(obj, _list, n){
  if(obj instanceof Object)
    if(!isEmpty(obj)){
     n++;
     for(let name in obj){
        _list = (goDeep(obj[name], _list, n)); // (_list = (goDeep(obj[name], _list, n))).push(n);
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

/* // another "Clear-out" solution

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

function clearOut(arr){
        let i, j;
        for(i = 0; i < arr.length; i++)
                if(arr[i]-1 >= 1)
                        for(j = i+1; j < arr[i]+ i; j++)
                                delete arr[j];
        return arr.filter(Math.abs);
}

function depth(obj) {
  var d = 0, b = false, b1 = false, arr = [];
  if (obj instanceof Array || obj === null)
    return 0;
  arr = clearOut(arr);
  return (arr = goDeep(obj, [], 0)).length != 0 ? Math.max(...arr) : 0;
}
*/
