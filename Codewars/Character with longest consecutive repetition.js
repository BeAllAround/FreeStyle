function _max(arr){
        let v = ['k', -1];
        for(let item of arr)
                if(item[1] > v[1])
                        v = item;
        return v;
}

function crack(arr){
  var item_copy = arr[0];
  var arr_c = [[item_copy, 1]];
  for(var item of arr.slice(1, arr.length)){
    if(item_copy == item)
      arr_c[arr_c.length-1][1] += 1;
    else
      arr_c.push([item, 1]);
    item_copy = item;
  }
  return arr_c;
}

function longestRepetition(s) {
  if(s == '')
    return ['', 0];
  return _max(crack(s));
}

console.log(longestRepetition("bbbaaabaaaa"));
console.log(longestRepetition("cbdeuuu900"));
