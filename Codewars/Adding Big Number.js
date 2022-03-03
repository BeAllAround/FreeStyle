function backIndex(arr, item){
  for(let i = arr.length-1; i >= 0; i--)
    if(arr[i] == item)
      return i;
  return -1;
}

function add(a, b) { // getting knotty, as usual...
  let n = [0];
  if(b.length > a.length){
    let t = a;
    a = b;
    b = t;
  }
  a = a.split('').map(Number);
  b = b.split('').map(Number);
  let x, y, c;
  let a_l = a.length-1;
  let i;
  for(i = b.length-1; i >=0; i--){
    c = a[a_l--] + b[i];
    if(c >= 10){
      if(a_l == -1){
        a_l++;
        a.unshift(0);
        a[a_l] = (a[a_l] + Number(c.toString()[0]))
        a[a_l+1] = Number(c.toString()[1]);
        if((c = a[a_l]) >= 10){
          a[a_l-1] = a[a_l-1] + Number(c.toString()[0]);
          a[a_l] = Number(c.toString()[1])
        }
        a_l--;
      }else{
      a[a_l] = a[a_l] + Number(c.toString()[0]);
      a[a_l+1] = Number(c.toString()[1]);
     }
    }else
      a[a_l+1] = c;
  }
  
  let index = backIndex(a, 10), _s;
  if(a[0] >= 10)
    return a.join('');
  while(index != -1){
    _s = a[index].toString();
    a[index-1] = a[index-1] + Number(_s[0]);
    a[index] = Number(_s[1]);
    index = backIndex(a, 10);
    if(a[0] >= 10)
      break;
  }
  return a.join('');
}

/*
  // Codewars
  function add (a, b) {
    var res = '', c = 0
    a = a.split('')
    b = b.split('')
    while (a.length || b.length || c) {
      c += ~~a.pop() + ~~b.pop()
      res = c % 10 + res
      c = c > 9
    }
    return res
  }
*/
