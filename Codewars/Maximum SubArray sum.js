var maxSequence = function(arr){
  if(arr.length == 0)
    return 0;
  let i,j, _a = [];
  for(i = 0; i <= arr.length; i++)
    for(j = i; j <= arr.length; j++)
      _a.push(arr.slice(i, j).reduce((a,b)=>a+b, 0));
  return Math.max(..._a);
}
