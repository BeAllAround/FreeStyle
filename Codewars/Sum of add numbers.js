function suM(arr){
	let s = 0;
	for(const item of arr)
		s += item;
	return s;
}

function rowSumOddNumbers(n) {
  let _n = 1, i, j;
  let data = [];
  n++;
  for(i = 0; i < n; i++){
    data.push([]);
    for(j = 0; j < i; j++){
      data[i].push(_n);
      _n += 2; 
    }
  }
 return suM(data[--n]);
}

