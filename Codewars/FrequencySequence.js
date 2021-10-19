function findIndex(list, s){
  for(let i = 0; i < list.length; i++)
    if(list[i][0] == s)
      return i;
  return -1;
}

function count(str){
  var arr = [];
  for(let i = 0; i < str.length; i++)
    if(findIndex(arr, str[i]) == -1)
      arr.push([str[i], 1]);
    else{
      arr[findIndex(arr, str[i])][1]++;
      arr.push(arr[findIndex(arr, str[i])]); // add it up
    }
  return arr;
}

function freqSeq(str, sep) {
  return count(str).map(v=>v[1].toString()).join(sep);
}
