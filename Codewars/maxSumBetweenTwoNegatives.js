function maxSum(a){
  let arr = [[]];
  let i;
  for(i = 0; i < a.length; i++){
    if(a[i] < 0){
      if(arr[arr.length-1].length == 1)
        arr[arr.length-1].push(i);
      else if(arr[arr.length-1].length == 0)
        arr.push([i, ]);
      if(arr[arr.length-1].length == 2)
        arr.push([i, ])
    }
  }
  arr.shift();
  arr = arr.map((v)=>{
    if(v.length == 2)
      return a.slice(v[0]+1, v[1]).reduce((a, b)=>a+b, 0);
    else
      return -1;
  })
  return arr.length != 0 ? (Math.max(...arr)) : -1;
  
}

function maxSumBetweenTwoNegatives(a) {
  return maxSum(a);
}

/*
  // CodeWars
function maxSumBetweenTwoNegatives(a) {
  let i=0,c=0,m=-1;
  while(i<a.length&&a[i]>=0) i++;
  while(++i<a.length){
    if(a[i]<0){ m=m<c?c:m; c=0; }
    else c+=a[i];
  }
  return m;
}
*/
