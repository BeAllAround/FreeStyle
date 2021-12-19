function check(i, arr){
  for(let item of arr)
    if(!(!(i/item).toString().includes('.')))
      return false;
  return true;
}

var lcm = function (...arr) {
  if(arr.includes(0))
    return 0;
  let arrA = [], arrB = [];
  let i = 1;
  while(true){
    if(check(i, arr))
      return i;
    i++;
  }
};
