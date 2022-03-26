function clone(arr){
  if(arr[0] == 'null')
    return null;
  return new Node(parseInt(arr.shift()), clone(arr));
}

function parse(string) {
  return clone(string.split(' -> '));
}
