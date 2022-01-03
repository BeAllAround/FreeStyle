def search(arr, inx):
    for x in range(inx+1, len(arr)):
        if arr[x] == 0:
            return x;
    return -1;

def pair_zeros(arr):
    arr_1 = list(arr);
    inx = -1;
    x = 0;
    modify_size = len(arr_1);
    while(x < modify_size):
        if(arr_1[x] == 0):
            inx = search(arr_1, x)
            if(inx!=-1):
                del arr_1[inx];
                modify_size = len(arr_1); # keep the fixed size
        x+=1;
    return arr_1;

def pair_zeros(arr):
    _arr, inxs, c = [], [], 1;
    c_inx = [];

    for x in range(len(arr)):
        if(arr[x] == 0):
            inxs.append(x);
            if c == 2:
                inxs.pop(0);
                c_inx.extend([*inxs]);
                inxs = [];
                c = 1;
                continue;
            c += 1;

    for x in range(len(arr)):
        if x not in c_inx:
            _arr.append(arr[x]);
    return _arr;

'''
# Codewars
from itertools import count;

def pair_zeros(arr, *args):
    c = count(1)
    return [elem for elem in arr if elem != 0 or next(c) % 2]; # excelent solution and great "left - right" in-code execution!
'''
