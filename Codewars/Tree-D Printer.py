# preloaded TreeNode class:
"""
class TreeNode:
    def __init__(self, value, children = None):
        self.value = value
        self.children = [] if children is None else children
"""
from preloaded import TreeNode

def __(tree, l, c):
    l.append(tree.value);
    if tree.children != None:
        l.append([]);
        for item in tree.children:
            __(item, l[-1], c+1);

def max_d(arr, l, c):
    if isinstance(arr, list):
        l.append(c);
        for item in arr:
            l = max_d(item, l, c+1);
    return l;
def pick_(arr, l, c, c1):
    if isinstance(arr, list):
        for item in arr:
            l = pick_(item, l, c+1, c1);
    else:
        if c == c1:
            l.append(arr);
    return l;
def tree_printer(tree : TreeNode) -> str:
    arr = [];
    a = [];
    __(tree, a, 0);
    m = max(max_d(a, [], 0));
    for _m in range(1, m+1):
        arr.append(' '.join(map(str, pick_(a, [], 0, _m))));
    return '\n'.join(arr);

'''
# Codewars
# preloaded TreeNode class:
"""
class TreeNode:
    def __init__(self, value, children = None):
        self.value = value
        self.children = [] if children is None else children
"""
from preloaded import TreeNode
from itertools import groupby

def tree_printer(tree : TreeNode) -> str:
    
    root, k = tree, 0
    lst, answer, final_answer = [(root, 0)], [], []
    while lst:
        cur, k = lst.pop(0)
        if cur:
            for i in cur.children:
                lst.append((i, k+1))
            answer.append((cur.value, k))
    
    for i, j in groupby(answer, key=lambda x: x[1]):
        final_answer.append(' '.join([str(element[0]) for element in list(j)]))
    
    return '\n'.join(final_answer)
'''
