function* _smaller(nums) {
  let arr = [], item, i;
  let end = nums.length;
  for(i = 0; i < end; i++)
    item = nums.shift(), yield nums.filter(b => b < item).length;
}

function smaller(arr){
  return [..._smaller(arr)];
}
