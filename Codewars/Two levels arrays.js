function f(array, l, n){
  if(array instanceof Array){
    if(n == 1)
      l.push([]), l = l[l.length-1];
    n++;
    for(let item of array)
      f(item, l, n);
  }else
    l.push(array);
}

function flattenTwoLevels(array) {
  let l = [];
  f(array, l, 0);
  return l;
}

/*
// Codewars

const flatten = a => Array.isArray(a) ? a.reduce( (acc,v) => acc.concat( Array.isArray(v) ? flatten(v) : v ), [] ) : a ;
const flattenTwoLevels = a => a.map(flatten);


function flattenTwoLevels(array) {
  return array.map(x => Array.isArray(x) ? x.flat(Infinity) : x);
}

let flatten = a => Array.isArray(a) ? [].concat(...a.map(flatten)) : a;
let flattenTwoLevels = a => a.map(flatten);

function flattenTwoLevels(array) {
  return array.reduce(function(a, b) {
    return a.push(Array.isArray(b) ? flatten(b) : b), a;
  }, []);
}

function flatten(array) {
  return array.reduce(function(a, b) {
    return a.concat(Array.isArray(b) ? flatten.call(null, b) : b);
  }, []);
}
*/
