function _treeArray(tree, b, _list, __list){
        if(tree == null)
                return;
        if(__list instanceof Array)
                __list.push(tree.val);
        if(tree.left){
                b = true;
                __list.push([]);
                _treeArray(tree.left, false, _list, __list[__list.length-1]);
                if(!tree.right){
                        __list[__list.length-1].push(null);
                }
        }
        if(tree.right){
                if(!b){
                        __list.push([]);
                        __list[__list.length-1].push(null);
                }
                _treeArray(tree.right, false, _list, __list[__list.length-1]);
        }
}

function treeArray(tree){
        let l1 = [];
        let l2 = l1;
        _treeArray(tree, false, l1, l2);
        return l1;
}

const assert = require('assert');

function compare(a, b){
   try{
      assert.deepEqual(treeArray(a), treeArray(b));
      return true;
    }catch(error){
      return false;
    }
}

/*
function compare(a, b) {
  if (a === null || b === null) return a === b;
  else return a.val === b.val && compare(a.left,b.left) && compare(a.right,b.right);
}

function compare(a, b) {
    if (a === null || b === null) {
        return a === b;
    }
    return a.val === b.val && compare(a.left, b.left) && compare(a.right, b.right);
}

function compare(a, b){
  return JSON.stringify(a) === JSON.stringify(b);
}

function compare(a, b){
  return traverse(a, b)
}

function traverse(a, b) {
  if((a == null && b != null) ||
     (a != null && b == null)) return false
  if(a == null && b == null) return true
  if(a.val != b.val) return false


  if(traverse(a.left, b.left))
    return traverse(a.right, b.right)
  
  return false
}
*/
