function _reduce(arr, func, init){
        init = ( init === undefined) ? arr[0] : init;
        var start = (init === undefined) ? 1 : 0
        if(arr instanceof Array)
                for(var i = start; i < arr.length; i++)
                        init = _reduce(arr[i], func, init);
        else
          init = func(init, arr);
        return init;
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
/*
// Codewars
        const flat = arr => arr.reduce((acc, val) => Array.isArray(val) ? acc.concat(flat(val)) : acc.concat(val), []);

        const hyperReduce = (fn, init) => {
          const inner = (...args) => hyperReduce(fn, flat(args).reduce(fn, init));

          inner.valueOf = () => init;
          return inner;
        };
*/
