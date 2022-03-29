function format(date){
  return date.getMonth()+1 + '/' + '13' + '/' + date.getFullYear();
}

function fridayTheThirteenths(start, end) {
  if(end == undefined)
    end = start;
  let n = 0, arr = [];
  let date = new Date(start, n, 13);
  while((date=new Date(start, n, 13)).getFullYear() <= end){
    if (date.getFullYear() > end)
      break;
    if(date.toString().startsWith("Fri"))
      arr.push(format(date));
    n++; 
  }
  return arr.join(' ');
}
