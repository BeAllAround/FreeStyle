from time import time;
from sys import setrecursionlimit;
# from math import inf;

setrecursionlimit(pow(10, 5));

class _Node:
    def __init__(self, v, n = None):
        self.v = v;
        self.previous = None;
        self.next = n;
        self.tail = self;

    def append(self, value): # O(n^2);
        n = self;
        while n != None:
            if n.next == None:
                break;
            n = n.next;
        n.next = _Node(value);

    def _append(self, value): # O(n);
        n = _Node(value);
        pre = self.tail.v;
        self.tail.next = n;
        self.tail = self.tail.next;
        self.tail.previous = pre;

    def __repr__(self):
        n = self;
        arr = [];
        while n != None:
            arr.append(n.v);
            n = n.next;
        return arr.__repr__();
    
    def toObject(self):
        obj = {};
        d = obj;
        n = self;
        while n != None:
            d['pre'] = n.previous;
            d['v'] = n.v;
            if n.next != None:
                d['next'] = {};
            else:
                d['next'] = None;
            n = n.next;
            d = d['next'];
        return obj;


start = time();
n = _Node(0);
for x in range(1, 10000):
    n._append(x);
print(n);
# print(n.toObject());
print(time() - start);
