from functools import reduce;
from math import gcd;

def gcdi(x,y):
    return gcd(x, y);

def lcmu(x, y):
    return abs(x * y // gcd(x, y))

def som(a, b):
    return a+b;

def maxi(a, b):
    return max(a, b);

def mini(a, b):
    return min(a, b);

def oper_array(fct, arr, init): 
    l = [];
    for item in arr:
        init = fct(item, init);
        l.append(init);
    return l;
