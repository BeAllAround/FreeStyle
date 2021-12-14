function generate(){
  let obj = {};
  let n = 97;
  for(let item of 'abcdefghijklmnopqrstuvwxyz'){ 
    obj[item] = n++;
  }
  n = 65;
  for(let item of ('abcdefghijklmnopqrstuvwxyz'.toUpperCase()))
    obj[item] = n++;
  n = 48;
  for(let item of ('0123456789'))
    obj[item] = n++;
  return obj;
}

function calc(x){
  let dict = generate();
  let total1 = '', total2;
  for(let item of x)
    total1 += dict[item];
  total1 = total1.split('');
  total2 = total1.map(v=>{
    if(v === '7')
      return '1';
    return v;
  });
  total1 = total1.map(v=>parseInt(v))
  total2 = total2.map(v=>parseInt(v))
  return (total1.reduce((a, b)=>a+b, 0) -  total2.reduce((a, b)=>a+b, 0));

}
