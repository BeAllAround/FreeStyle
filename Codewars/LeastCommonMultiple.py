from functools import reduce;
import math;

def _sum(arr):
    a = arr[0];
    for x in range(1, len(arr)):
        a = a * arr[x] // math.gcd(a, arr[x]); # a = lcm(a, arr[x]);
    return a;
# 3 numbers - > lcm(lcm(x1, x2), x3) -> reduce(lcm, [x1, x2, x3])

def lcm(*args):
    if(args == ()):
        return 1;
    try:
        return _sum(args);
    except ZeroDivisionError:
        return 0;
