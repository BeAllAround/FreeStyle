function rowSumOddNumbers(n) {
  let _n = 1, i, j, s = 0; 
  n++;
  for(i = 0; i < n; i++)
    for(j = 0; j < i; j++){
      if(i == n-1)
        s += _n;
      _n += 2;
    }
  return s;
}
