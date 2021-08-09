var moveZeros = function (arr) {
  var v = arr;
  var v1 = [];
  let i, end, c = 0;
  end = (v.length);
  for(i = 0; i < end; i++)
    if(v[i] === 0)
	  c++;
    else
	  v1.push(v[i]);
  for(i = 0; i < c; i++)
	v1.push(0);
  return v1;
}

console.log(moveZeros([0, false,null, 0, 0, 1, "a"]));
