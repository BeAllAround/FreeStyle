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
  n = 1;
  for(let item of 'abcdefghijklmnopqrstuvwxyz')
    obj[item+'.'] = n++;
  return obj;
}

function percentage(num, per)
{
  return (per / 100) * num;
}

function cake(x, y){
  let obj = generate();
  str = 0;
  for(let item in y)
    if(item % 2 == 0)
      str += obj[y[item]];
    else
      str += obj[y[item]+'.'];
  if(str > percentage(x, 70))
    return 'Fire!'
  return 'That was close!';
}
