function findItem(arr, item){
  let i;
  for(i = 0; i < arr.length; i++)
    if(arr[i] == item)
      return i;
  return -1;
}
function cycle(dir, arr, cur) {
  let b = false, index = -1;
  if(dir < 0)
    b = true;
  dir = Math.abs(dir);
  if((index = findItem(arr, cur)) == -1)
    return null;
  if(b)
    if((index - dir) < 0)
      return arr[arr.length-dir];
    else
      return arr[index-dir];
  if(index + dir > arr.length)
    return null;
  if(index + dir == arr.length)
    return arr[0]
  return arr[index+dir];
}
