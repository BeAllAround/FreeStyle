function reduce(head, f, init) {
  while(head){
    init = f(init, head.data);
    head = head.next;
  }
  return init;
}

/*
function reduce(head, f, init) {
  return head ? reduce(head.next, f, f(init, head.data)) : init;
}

function reduce(head, f, init) {
  const _reduce = (node, accumulator) => {
    return !node ? accumulator : _reduce(node.next, f(accumulator, node.data));
  };
  
  return _reduce(head, init);
}
*/
