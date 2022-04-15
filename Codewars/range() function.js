function range(start = 0, end, step) {
  let arr = [], i;
  if(end === undefined)
    end = start, start = 0;
  if (step == undefined)
    step = 1;
  if(step != 0)
    for(i = start; i < end; i += step)
      arr.push(i);
  else
    for(i = start; i < end; i++)
      arr.push(start);
  return arr;
}

/*
function range(start, end, step) {
  
  var result = [],
      a = arguments.length == 1 ? 0 : start,
      b = arguments.length == 1 ? start : end,
      c = step != void(0) ? step : 1;
  if( b < a ) return result;
  
  for (var i = a; (step == 0 ? result.length + a : i) < b; i = i + c) {
    result.push(i);
  }
  return result;
}
*/
