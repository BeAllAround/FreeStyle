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
                if(len(start)!=len(item)):
                    return None;
            if(_loop(start, a)==None):
                return None;
            if(_loop(item, a)==None):
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
