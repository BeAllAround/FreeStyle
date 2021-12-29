function Node(data) {
  this.data = data;
  this.next = null;
}
function NodeToArray(node){
  let arr = [];
  while(node != null){
    arr.push(node.data);
    node = node.next;
  }
  return arr;
}

function insertSort(head) {
  if(head===null)
    return null;
  l = (NodeToArray(head));
  l.sort();
  node = new Node(l[0]);
  node_c = [node]; // make sure you store the begining entry;
  for(let i = 1; i < l.length; i++){
    node.next = new Node(l[i]);
    node = node.next;
  }
  return node_c[0];
}
