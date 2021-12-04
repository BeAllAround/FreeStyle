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

// class-based approach
function isEmpty(obj){
        return Object.keys(obj).length == 0;
}

class Iterator_d1{
        constructor(){
                this.nList = [];
        }
  
        depth(obj, c){
                if(obj === null || isEmpty(obj)) // "left to right" execution - check if "null" first
                        return true;
                if(obj instanceof Object && !isEmpty(obj)){
                        c++;
                        for(let name in obj)
                                if(this.depth(obj[name], c))
                                        this.nList.push(c);
                }
                return false;
        }
  
        get value(){
                return this.nList;
        }
}       

function depth(obj){
        let iter = new Iterator_d1(), arr;
        if(obj instanceof Array)
          return 0;
        return !iter.depth(obj, 0) ? Math.max(...iter.value) : 0;
}

// the "store-use" approach
function isEmpty(obj){
        return Object.keys(obj).length == 0;
}

function _depth(obj, c, _list){
                if(obj === null || isEmpty(obj)) // "left to right" execution - check if "null" first
                  return _list[0] = true, _list;
                if(obj instanceof Object && !isEmpty(obj)){
                        c++;
                        for(let name in obj)
                                ((_list = _depth(obj[name], c, _list))[0]) ?
                                        _list[1].push(c) : 0;
                }
                return _list[0] = false, _list;
}

function depth(obj){
        let arr = [false, []];
        if(obj instanceof Array)
          return 0;
        return !(arr = _depth(obj, 0, arr))[0] ? Math.max(...arr[1]) : 0;
}

// another dynamic approach to the latter
function isEmpty(obj){
  return Object.keys(obj).length == 0;
}

function _depth(obj, c, _list){
  if(obj === null || isEmpty(obj)) // "left to right" execution - check if "null" first
    return [true, _list[1]];
  if(obj instanceof Object && !isEmpty(obj)){
    c++;
    for(let name in obj)
      ((_list = _depth(obj[name], c, _list))[0]) ?
        _list[1].push(c) : 0;
  }
  return [false, _list[1]];
}

function depth(obj){
  let arr;
  if(obj instanceof Array)
    return 0;
  return !(arr = _depth(obj, 0, [false, []]))[0] ? Math.max(...arr[1]) : 0;
}
*/
