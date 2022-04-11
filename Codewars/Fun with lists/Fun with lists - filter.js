function filter(head, p) {
  let n = [null];
  let node, b = true;
  while(head){
    if(p(head.data))
      if(b)
        n[0]=new Node(head.data), node = n[0], b=false;
      else
        node = node.next = new Node(head.data);
    head = head.next;
  }
  return n.shift();
}

/*
function filter(head, p) {
  return !head ? null : p(head.data) ? new Node(head.data, filter(head.next, p)) : filter(head.next, p);
}
const filter = (head, p) => {
  if (!head) return head;
  if (!p(head.data)) return filter(head.next, p);
  return new Node(head.data, filter(head.next, p));
};
*/
