function findIndex(arr, callback){ // bool<Object>
  for(let i = 0; i < arr.length; i++){
    if(callback(arr[i], i))
      return i;
  }
  return -1;
}

function _sort(a){
  let temp;
  for(let i = 0; i < a.length; i++)
    for(let j = i+1; j < a.length; j++)
      if(a[i][1] == a[j][1]){
        if(a[i][0] < a[j][0]){
          temp = Array.from(a[j]);
          a[j][0] = a[i][0];
          a[j][1] = a[i][1];
          
          a[i][0] = temp[0];
          a[j][1] = temp[1];
        }
      }
}

function solve(arr){
  let _dict = [];
  let index;
  arr.sort();
  for(let i of arr){
    if((index = findIndex(_dict, (v)=>v[0]==i)) != -1){
      _dict[index][1]++;
    }else
      _dict.push([i, 1]);
  }
  _dict.sort((a,b)=>{
    if(a[1] > b[1])
      return 1;
    return -1;
  });
  _sort(_dict);
  
  let _a = [], v;
  for(let i = _dict.length-1; i >= 0; i--){
    v = _dict[i];
    for(let j = 0; j < v[1]; j++)
      _a.push(v[0]);
  }
  return _a;
}
