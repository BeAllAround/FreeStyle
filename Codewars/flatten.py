def _flatten(arr, l):
    if isinstance(arr, list):
        for item in arr:
            l = _flatten(item, l);
    else:
        l.append(arr);
    return l;
    
def flatten(*args):
    return _flatten([*args], []);

'''
def flatten(*a):
    r = []
    for x in a:
        if isinstance(x, list):
            r.extend(flatten(*x))
        else:
            r.append(x)
    return r
'''
