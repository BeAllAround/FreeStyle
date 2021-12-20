from functools import reduce;
import math;

def _sum(arr):
    a = arr[0];
    for x in range(1, len(arr)):
        a = a * arr[x] // math.gcd(a, arr[x]);
    return a;

def lcm(*args):
    if(args == ()):
        return 1;
    try:
        return _sum(args);
    except ZeroDivisionError:
        return 0;
