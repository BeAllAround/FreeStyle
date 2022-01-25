function shift(str, n){
  for(let _ = 0; _ < n; _++)
    str = str.slice(str.length-1, str.length) + str.slice(0, str.length-1);
  return str;
}

function shift2(str, n){
  for(let _ = 0; _ < n; _++)
   str = [str.slice(1, str.length), str.slice(0, 1)].join('');
  return str;
}

function place(str){
  str = str.split(" ");
  let s = str.shift().length;
  let arr = [0];
  arr.push(s); // + 1
  for(let item of str){
    s += item.length; // + 1
    arr.push(s);
  }
  return arr;
}

const IterativeRotationCipher = {};

function encode(n, str){
  let sep = place(str);
  let list = [];
  str = shift(str.split(' ').join(''), n);
  let item = sep.shift();
  for(let i of sep)
    list.push(shift(str.slice(item, i), n)), item = i;
  return list.join(' ');
}

IterativeRotationCipher.encode = function(n,str){
  for(let _ = 0; _ < n; _++)
    str = encode(n, str);
  return n + ' ' + str;
};

function decode(num, str){
  let list = [];
  let sep = place(str);
  str = str.split(' ');
  for(let item of str)
      list.push(shift2(item, num));
  str = shift2(list.join(''), num);
  list = [];
  let item = sep.shift();
  for(let i of sep)
    list.push(str.slice(item, i)), item = i;
  return list.join(' ');
}

IterativeRotationCipher.decode = function(str){
  num = parseFloat(str.match(/^\d+/)[0]);
  str = str.replace(num.toString() + ' ', '');
  for(let _ = 0; _ < num; _++)
    str = decode(num, str);
  return str;
};
