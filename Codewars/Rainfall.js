function mean(town, string, n) {
  let arr = [], sum = 0.0, b = false, list = [], num;
  town = town + ":";
  string = string.split("\n");
  for(let item of string)
    if(item.indexOf(town) != -1){
      town = item.replace(town, '');
      b = true;
      break;
    }
  if(!b)
    return -1;
  arr = town.split(",");
  for(let item of arr){
    num = parseFloat(item.match(/\d+\.\d+/g)[0]);
    sum += num;
    list.push(num);
  }
  if(n !== undefined)
    return list; // cheating a little but whatever[type redirecting]...
  return sum/arr.length;
}

function variance(town, string) {
  let list = mean(town, string, 0), _mean = mean(town, string);
  if(list===-1)
    return -1;
  return list.map(item=>{
    return Math.pow(_mean - item, 2);
  }).reduce((a, b)=>a+b, 0)/list.length;
}
