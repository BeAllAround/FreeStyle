function loop(arr){
  let arr_1 = [];
  b = arr.reduce((a,b)=>a+b, 0);
  for(let i = 0; i <= arr.length; i++){
    arr_1.push(b);
    b -= arr[i];
  }
  return arr_1;
}

function partsSums(ls) {
  return loop(ls);
}
