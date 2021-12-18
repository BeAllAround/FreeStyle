function trouble(x, t){
  let i;
  for(i = 0; i < x.length; i++)
    if(i+1 <= x.length)
      if((x[i] + x[i+1]) == t){
        delete x[i+1];
        x = x.filter(Number);
        i--;
      }
  return x;
}
