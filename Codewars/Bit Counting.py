from functools import reduce;

def _call(a, b):
    if(b=='1'):
        a += 1;
    return a;

def split(arr):
    return [item for item in arr];

def count_bits(n):
    return reduce(_call, split(bin(n)[2:]), 0);
