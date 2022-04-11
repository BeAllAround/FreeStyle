function map(head, f) {
  let l = [null], n, v, b = true;
  while(head){
    v = f(head.data);
    if(b)
      l = [n = new Node(v)], b = false;
    else
      n = n.next = new Node(v);
    head = head.next;
  }
  return l.shift();
}

/*
function map(head, f) {
  return !head ? null : new Node(f(head.data), map(head.next, f));
}

function map(head, f) {
  if (!head) return null
  return { data: f(head.data), next: map(head.next, f) }
}
*/
