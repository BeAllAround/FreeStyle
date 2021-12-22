function stringFormatFromSeconds(value){
  var t = new Date(1970, 0, 1);
  var R = "";
  t.setSeconds(value);
  if(t.getHours()<10){
     R += "0" + t.getHours() + ":";
  }else R += t.getHours()+":";
  
  if(t.getMinutes() < 10){
    R+= "0" + t.getMinutes();
  }else R += t.getMinutes();
  
  return R;
}

function toNumber(str){
  let n1 = str.split(":");
  return Number(parseInt(n1[0])*3600 + parseInt(n1[1])*60);
}

function filter(arr){
  let emptyArr = [];
  for(var i = 0; i<arr.length; i++)
    if(!emptyArr.includes(arr[i]))
      emptyArr.push(arr[i]);
  return emptyArr;
}

function solve(arr){
  if(arr.length ==1) return "23:59";
  let arrC = arr.sort();
  arrC = filter(arr);
  let arrP = new Array();
  for(var i = 0; i<arrC.length; i++)
    if(i+1 < arrC.length)
      arrP.push(toNumber(arrC[i+1]) - toNumber(arrC[i]) - 60);
    
  arrP.push(toNumber(arrC[0]) - toNumber(arrC[arrC.length-1]) - 60);
  arr_s = (arrP.map(v=>stringFormatFromSeconds(v)));
  arrP = arr_s.map(toNumber);
  return stringFormatFromSeconds(Math.max(...arrP));
}
