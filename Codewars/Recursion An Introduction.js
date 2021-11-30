function stepDown(stair, width){
  if ( stair <= 0){
    if ( stair == 0)
      return [0]
    else
      return [];
  }
  n = stepDown(stair - width, width);
  n.push(stair);
  return n;
}
