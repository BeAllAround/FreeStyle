function *produce(arr){
  let l1 = [];
  let l2 = arr.shift();
  let l_ = arr.shift();
  for(let item of l2)
    yield item;
  while(l_!==undefined){
    for(let item of l2)
      for(let jtem of l_){
        l1.push(item+jtem);
        yield item+jtem;
      }
    l2 = Object.assign([], l1);
    l_ = arr.shift(); 
    l1 = [];
  }
}

function *letters() {
  yield *(produce(["abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"]));
}

/*
  // Codewars
  function* letters() {  
    let chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    yield* chars

    for (let prefix of letters()) {
      for (let char of chars) {
        yield `${prefix}${char}`;
      }
    }
  }
  
  ////////////////////////////////////////////////////////
  let S = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  function* letters() {
    for (let i = 1;; i++) yield f(i);
  }

  function f(n) {
    let r = [];
    while (n) r.push(S[--n % 52]), n = n / 52 | 0;
    r = r.reverse().join("");
    return r;
  }
  ///////////////////////////////////////////////////////
  function* letters(A="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") {
    let is=[0], S=A.length, arr=[A[0]], c=0;
    const write=_=>(arr[c]=_||A[is[c]]);
    while(1){
      yield arr.slice().reverse().join('');
      is[c]++;
      if(is[c]===S){
        while(c<is.length&&is[c]===S){
          is[c]=0; write(); c++;
          if(c<is.length){ is[c]++; write(); }
        }
        if(c==is.length){ is=Array(is.length+1).fill(0); write('a'); }
        c=0;
      } 
      write();
    }
  }
  ///////////////////////////////////////////////////////
  const abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  function* impl(n) {
    if (n == 0) {
      yield '';
    } else {
      for (const x of impl(n-1))
        for (const c of abc)
          yield x + c;
    }
  }

  function* letters() {
    for (let i=1;; ++i) yield* impl(i);
  }
*/
