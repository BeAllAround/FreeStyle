function split(arr, prop) {
  let arr_1 = [[], []];
  var c1 = 0, c2 = 1;
  for(let item of arr){
    if(Object.keys(item).length == 0)
      arr_1[c2].push({});
    for(let k in item){
      if(prop == void 0){
        arr_1[c2].push(item);
        break;
      }
      else if(k == prop){
        if(Boolean(item[k]))
          arr_1[c1].push(item);
        else if(!Boolean(item[k]))
          arr_1[c2].push(item);
        break; // "break" on first matching
      };
    }
  }
  return arr_1;
}
