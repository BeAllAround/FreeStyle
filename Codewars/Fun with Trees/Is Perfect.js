function _treeArray(tree, b, _list, __list){
        if(tree == null)
          return;
        if(__list instanceof Array)
          __list.push(tree.value);
        if(tree.left){
          b = true;
          __list.push([]);
          _treeArray(tree.left, false, _list, __list[__list.length-1]);
        }
        if(tree.right){
          _treeArray(tree.right, false, _list, __list[__list.length-1]);
          if(!b)
            __list.push([]);
        }
}

function treeArray(tree){
        let l1 = [];
        let l2 = l1;
        _treeArray(tree, false, l1, l2);
        return l1;
}

function depth(obj, l, n){
  if(obj instanceof Array){
    l.push(n);
    for(let item of obj)
      l = depth(item, l, n+1);
  }else
    l.push(n);
  return l;
}

Array.prototype.sum = function(){
  return this.reduce((a,b)=>a+b, 0);
}

class TreeNode {

  constructor(left = null, right = null) {
    this.left = left;
    this.right = right;
  }

  static isPerfect(root) {
    if(root === null)
      return true;
    return depth(treeArray(root.left), [], 0).sum() == depth(treeArray(root.right), [], 0).sum();
  }
  
  static leaf() {
    return new TreeNode();
  }
  
  static join(left, right) {
    return new TreeNode().withChildren(left, right);
  }
  
  withLeft(left) {
    this.left = left;
    return this;
  }

  withRight(right) {
    this.right = right;
    return this;
  }

  withChildren(left, right) {
    this.left = left;
    this.right = right;
    return this;
  }

  withLeftLeaf() {
    return this.withLeft(TreeNode.leaf());
  }

  withRightLeaf() {
    return this.withRight(TreeNode.leaf());
  }

  withLeaves() {
    return this.withChildren(TreeNode.leaf(), TreeNode.leaf());
  }
  
}


/*
  // Codewars
  class TreeNode {

  constructor(left = null, right = null) {
    this.left = left;
    this.right = right;
  }

  static isPerfect(root) {
    if (!root) return true;
    if (TreeNode.countChildren(root.left) !== TreeNode.countChildren(root.right)) return false;
    return TreeNode.isPerfect(root.left) && TreeNode.isPerfect(root.right);
  }
  
  static countChildren(root) {
    if (!root) return 0;
    return 1 + TreeNode.countChildren(root.left) + TreeNode.countChildren(root.right);
  }
  
  static leaf() {
    return new TreeNode();
  }
  
  static join(left, right) {
    return new TreeNode().withChildren(left, right);
  }
  
  withLeft(left) {
    this.left = left;
    return this;
  }

  withRight(right) {
    this.right = right;
    return this;
  }

  withChildren(left, right) {
    this.left = left;
    this.right = right;
    return this;
  }

  withLeftLeaf() {
    return this.withLeft(TreeNode.leaf());
  }

  withRightLeaf() {
    return this.withRight(TreeNode.leaf());
  }

  withLeaves() {
    return this.withChildren(TreeNode.leaf(), TreeNode.leaf());
  } 
}
*/
