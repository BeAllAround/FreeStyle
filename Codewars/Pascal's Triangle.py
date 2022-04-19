from math import factorial;

def f(n, k): return factorial(n) // (factorial(k) * factorial(n-k));

def _split(arr):
    _a = [];
    for x in range(len(arr)):
        if x+2 <= len(arr):
            _a.append(arr[x:x+2]);
    return _a;

def pascals_triangle(n):
    if n == 1:
        return [1];
    elif n == 2:
        return [1, 1, 1];
    arr = [[1], [1, 1]];
    n1 = 0;
    for x in range(1, n-1):
        _arr = [];
        for i in range(len(arr[x])):
            _arr.append(f(x, i));
        arr.append([1] + list(map(sum, _split(_arr))) + [1]);
    a_c = [];
    for item in arr: # spread out the matrix
        a_c.extend(item);
    return a_c;
