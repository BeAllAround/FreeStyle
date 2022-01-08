function _flatten(root, l){
  if(root.value){
    list = root.value;
    while(list != null){
      l.push(list.data);
      list = list.next;
    }
  }
  if(root.left)
    _flatten(root.left, l);
  if(root.right)
    _flatten(root.right, l);
  
}
function flatten(root) {
  if(root == null)
    return null;
  let list = [], _l = [], _list = new ListNode(), c_l = _list;
  _flatten(root, list);
  for(let item of list)
    if(!(_l.includes(item)))
      _l.push(item);
  _l.sort((a, b)=>a-b);
  for(let i in _l){
    _list.data = _l[i];
    if(i != _l.length-1){
      _list.next = new ListNode();
      _list = _list.next;
    }
  }
  return c_l;
};

/*
  // Codewars
  function flatten(root) {
  list = node => node && [node.data].concat(list(node.next)) || []
  tree = node => node && list(node.value).concat(tree(node.left), tree(node.right)) || []
  return Array.from(new Set(tree(root))).sort((a,b) => b-a).reduce((a,b) => new ListNode(b, a), null)
};

*/
