function _reduce(arr, func, start){
        if(arr instanceof Array)
                for(let item of arr)
                        start = _reduce(item, func, start);
        else
                start = func(start, arr);
        return start;
}

function _add(s, func, ...n){
  var fn = function(...x) {
    return _add(s, func, _reduce(n, func, s), _reduce(x, func, s));
  };

  fn.valueOf = function() {
    return _reduce(n, func, s);
  };
  return fn;
}

function __add(s, func){
        return (...args)=>_add(s, func, args);
}

// test-cases
console.log((__add('', (a, b)=>a+b))('uh', 'oh')('b', '1')([[['3']]]).valueOf());
console.log(__add(0, (p, n)=>(typeof n == 'function') ? n(p) : n)([3, o=>o+3]).valueOf());
