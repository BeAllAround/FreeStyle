def depth(arr, a, n):
    if isinstance(arr, list):
        n+=1;
        a.append(n);
        for item in arr:
            a = depth(item, a, n);
    return a;

def check_depth(a1, a2):
    return max(depth(a1, [], 0)) == max(depth(a2, [], 0));

def flat(a1, a):
    if isinstance(a1, list):
        for item in a1:
            a = flat(item, a);
    else:
        a.append(a1);
    return a;

def check_flat(a1, a2):
    return len(flat(a1, [])) == len(flat(a2, []));

def _loop(arr, a):
    if isinstance(arr, list):
        _s = 1;
        if(len(arr)==1):
            _s = 0;
        try:
            start = arr[0];
        except:
            pass;
        for item in arr[_s::]:
            if(type(start)!=type(item)):
                return None;
            elif(isinstance(start, list) and isinstance(item, list)):
                # if(any(list(filter(lambda x: x, [not check_flat(start, item), not check_depth(start, item), len(start)!=len(item)])))):
                    # return None;
                if(not check_flat(start, item)):
                    return None;
                if(not check_depth(start, item)):
                    return None;
                if(len(start)!=len(item)):
                    return None;
            if(_loop(item, a)==None):
                return None;
            if(_loop(start, a)==None):
                return None;
            
            start = item;
    return True;

def __loop(arr, a, index1, index2):
    if isinstance(arr, list):
        if(index2 not in a[0]):
            a.append(len(arr));
            a[0].append(index2);
        for x in range(len(arr)):
            a = __loop(arr[x], a, index2, index2+1);
    return a;

def hyperrectangularity_properties(arr):
    if(len(arr)==0):
        return tuple([0]);
    if(_loop(arr, [])==None):
        return None;
    return tuple((__loop(arr, [[]], -1, 0))[1:]);

'''
# Codewars
import numpy as np

def hyperrectangularity_properties(arr):
    try:
        return np.array(arr, np.int32).shape
    except:
        return None
'''
