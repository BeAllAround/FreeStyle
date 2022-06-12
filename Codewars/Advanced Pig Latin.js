function isVow(s){
  let vows = ['a', 'e', 'i', 'o', 'u']
  for(let v of vows)
    if(s.toLowerCase().startsWith(v)) // ignore case
      return true;
  return false;
}

function isCap(s){
  return s[0].toUpperCase() == s[0];
}

function toCap(s){
  return s[0].toUpperCase() + s.slice(1);
}

function findVowel(s){
  let vows = ['a', 'e', 'i', 'o', 'u']
  let l = [];
  for(let v of vows)
    if(s.indexOf(v) != -1)
      l.push(s.indexOf(v));
  if(l.length == 0)
    return -1;
  return Math.min(...l);
}

function clear(s){
  let chrs = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'.split('');
  let pun = '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'.split('');
  let s1 = '';
  let s2 = '';
  for(let item of s)
    if(chrs.includes(item))
      s1 += item;
    else if(pun.includes(item))
      s2 += item;
  return s1 + s2;
}

function translate(sentence) {
  let s = sentence.split(' ');
  let l = [];
  
  for(let item of s){
    let c = findVowel(item);
    if(isVow(item))
      l.push(clear(item + 'way'));
    else if(isCap(item))
      l.push(clear(toCap(item.slice(c) + item.slice(0, c).toLowerCase()) + 'ay'));
    else
      l.push(clear(item.slice(c) + item.slice(0,c) + 'ay'));
  }
  return l.join(' ');
};
