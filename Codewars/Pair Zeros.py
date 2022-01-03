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
'''
# Codewars
from itertools import count
def pair_zeros(arr, *args):
    c = count(1)
    return [elem for elem in arr if elem != 0 or next(c) % 2]
'''
