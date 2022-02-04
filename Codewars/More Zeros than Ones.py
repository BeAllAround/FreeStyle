from functools import reduce

def f(a, v):
    if v == '1':
        a[0] += 1
    else:
        a[1] += 1
    return a
    
def more_zeros(s):
    arr = []
    for item in s:
        ones, zeros = (reduce(f, [*bin(ord(item))[2:]], [0, 0]))
        if ones < zeros and item not in arr:
            arr.append(item)
    return arr
