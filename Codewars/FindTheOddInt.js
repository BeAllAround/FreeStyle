function findIndex(arr, item){
  let i;
  for(i = 0; i < arr.length; i++)
    if(arr[i][0] == item)
      return i;
  return -1;
}

function findOdd(A) {
  let arr = [], index = -1;
  for(let item of A)
    if((index = findIndex(arr, item))==-1)
      arr.push([item, 1]);
    else
      arr[index][1]++;
  for(let item of arr)
    if(item[1]%2 != 0)
      return item[0];
}
