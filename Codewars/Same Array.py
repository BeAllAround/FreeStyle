from collections import Counter;

def count(carr):
    return Counter(list(sorted(carr)));
    
def same(arr_a, arr_b):
    c = 0;
    for j in arr_a:
        for k in arr_b:
            if count(j) == count(k):
                c += 1;
                break;
    return c == len(arr_a) and c == len(arr_b);
