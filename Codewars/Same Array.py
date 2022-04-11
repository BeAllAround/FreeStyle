from collections import Counter;
from copy import deepcopy;

def count(carr):
    return Counter(list(sorted(carr)));
    
def same(arr_a, arr_b):
    c = 0;
    arrb_c = deepcopy(arr_b);
    for j in arr_a:
        for x in range(len(arrb_c)):
            k = arrb_c[x];
            if count(j) == count(k):
                c += 1;
                del arrb_c[x]; # .pop(x);
                break;
    return c == len(arr_a) and c == len(arr_b);
