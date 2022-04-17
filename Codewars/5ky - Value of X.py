p = lambda x, y: x+y;
m = lambda x, y: x-y;

def __eval(arr):
    if len(arr) != 0 and type(arr[0])!=int:
        arr[0] = arr[0](0, arr[1]);
        del arr[1];
    ls = list(filter(lambda x: type(x) != int, arr));
    nums = list(filter(lambda x: type(x) == int, arr));
    i = 0;
    while len(nums)!=1 and i < len(ls):
        nums.insert(0, ls[i](nums.pop(0), nums.pop(0)));
        i+=1;
    return nums.pop(0);

def add_up(arr, n):
    c = 0;
    for item in arr[::-1]:
        if type(item) == int:
            break;
        else:
            c += 1;
    return c-1;

def is_digit(n):
    try:
        int(n);
        return True;
    except ValueError:
        return False;
    
def _eval(s): # implementing a custom eval due to security issues
    arr = [];
    _m = 1;
    _p = 1;
    num = 0;
    for c in s: # c : char
        if c == '-':
            arr.append(m);
        elif c == '+':
            arr.append(p);
        elif is_digit(c):
            if len(arr) != 0 and is_digit(str(arr[-1])):
                c = int(str(arr.pop()) + c);
                r = add_up(arr, c);
                if r > 0:
                    for _ in range(r):
                        c = arr.pop()(0, c);
                arr.append(c);
            else:
                r = add_up(arr, int(c));
                if r > 0:
                    for _ in range(r):
                        c = arr.pop()(0, int(c));
                arr.append(int(c));
        elif c == ' ':
            pass;
        else:
            raise Exception("Char found");
    return __eval(arr);

def opp(s):
    if s == '+':
        return '-';
    if s == '-':
        return '+';

def solve(eq: str):
    eq = ''.join(eq.split(' '));
    if eq[:1] != '-':
        eq = '+' + eq;
    l1 = [];
    _eq = eq.split('=');
    if 'x' in _eq[0]:
        end = -1;
        start = 0;
    else:
        end = -2;
        start = -1;
    l = str(_eval(eq.split('=')[end]));
    for i in eq.split('=')[start]:
        # if i == ' ': continue;
        if i == '-':
            l += '+';
        elif i == '+':
            l += '-';
        elif i == 'x':
            if l[-1] in ['-', '+']:
                l = [*l];
                t = l[-1];
                l1 = [t];
                l = ''.join(l[:-1]);
        else:
            l += i;
    if len(l1) != 0:
        l = opp(l1[0]) + str(_eval(l));
        return _eval(l);
    else:
        return _eval(l);
      
'''
# Codewars

from collections import Counter
import re

def solve(eq: str):
    eq  = eq.replace(' ','')
    a,b = eq.split('=')
    if 'x' in b: a,b = b,a
    a,b = f(a), f(b)
    return (b-a) * (-1)**('-x' in eq)
    
def f(s):
    return sum(int(x) for x in re.findall(r'(?:[+-])?\d+',s))

######################################################################
def solve(eq):
    a,b = eq.replace('x','0').split('=')
    x = eval(a) - eval(b)
    if '- x' in eq: x*=-1
    return x if eq.index('x') > eq.index('=') else -x
'''
