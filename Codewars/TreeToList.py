class Node:
    def __init__(self, data, child_nodes=None):
        self.data = data
        self.child_nodes = [] if child_nodes is None else child_nodes

def tree_to_list(tree_root):
    if isinstance(tree_root, list) and tree_root.__len__() == 0:
        return [];
    arr = [*tree_root.child_nodes];
    l = [];
    l.append(tree_root.data);
    for item in arr:
        l.append(item.data);
        if item.child_nodes != None:
            arr.extend(item.child_nodes); # update the arr, which will keep us in the loop
    return l;
