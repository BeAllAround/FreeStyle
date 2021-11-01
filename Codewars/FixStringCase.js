function isLower(s){
    return s.toLowerCase() == s;
}

function solve(s){
  data = [0, 0];
  for(let item of s){
    if(isLower(item))
      data[0]++;
    else
      data[1]++;
  }
  if(data[0] > data[1])
    return s.toLowerCase();
  else if(data[0] == data[1])
    return s.toLowerCase();
  return s.toUpperCase();
}
