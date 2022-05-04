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
        pre = _Node(self.tail.v); #
        self.tail.next = n;
        self.tail = self.tail.next;
        self.tail.previous = pre;

    def remove(self, value):
        head = self;
        if head and head.v == value:
            self = self.next;
            self.previous = None;
            if not self:
                return None;
            tail = self;
            while tail:
                if tail.next == None:
                    break;
                tail = tail.next;
            self.tail = tail;
            return self;

        while head != None:
            if head.next:
                if head.next.v == value:
                    break;
            head = head.next;
        if not head:
            return self;

        if head.next.next:
            head.next.next.previous = head.next.previous;
            head.next = head.next.next;
        else:
            head.next = None;

        while head:
            if head.next == None:
                self.tail = head;
            head = head.next;
        while head:
            if head.previous == None:
                self.next = head;
                break;
            else:
                head = head.previous;

        return self;

    def __repr__(self):
        n = self;
        arr = [];
        while n != None:
            arr.append(n.v);
            n = n.next;
        return '{' + arr.__repr__() + '}';
    
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
for x in range(1, 10):
    n._append(x);
print(n);
n = n.remove(0);
n = n.remove(9);
n = n.remove(2);
n = n.remove(3);
n = n.remove(5);
n = n.remove(6);
n = n.remove(7);
n.append(101);
n = n.remove(101);
n = n.remove(101);
n._append(101);
n._append(101);
n._append(104);
n = n.remove(104);
n._append(107);
n = n.remove(107);
n = n.remove(101);
n = n.remove(1);
print('AFTER: ', n.toObject());
# print(n.toObject());
# print(n.toObject());
print(time() - start);
