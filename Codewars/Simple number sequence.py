def _iter(s, _split):
    for x in range(0, len(s), _split):
        yield (s[x : x+_split]);

def check_sort(arr):
    return arr == sorted(arr);

def _find(arr):
    arr = list(map(int, arr))
    item = arr[0]
    arr1 = []
    for j in arr[1:]:
        if(item+2 == j):
            arr1.append(item+1);
        elif not item < j:
            return -1
        item = j
    if(len(arr1) == 0 or len(arr1) > 1):
        return -1
    return arr1[0];
    
def missing(s):
    arr = [];
    arr1 = [];
    item = None
    for x in range(1, 10):
        arr = list(_iter(s, x));
        if(check_sort(arr)):
            break
    if(_find(arr) != -1):
        return _find(arr)
    else:
        _s = s
        b = False
        for x in range(1, 10):
            arr = list(_iter(s, x))
            for item in arr:
                if(item.startswith('0')):
                    try:
                        s = (s[s.index('10'):len(s)])
                    except ValueError:
                        return -1
                    b = True
                    continue;
            if(check_sort(arr)):
                break
        b1 = False;
        if not b:
            for x in range(1, len(_s)):
                item = _s[x]
                if(item.startswith('1')):
                    arr = (list(_iter(_s[0:x], 1))) + list(_iter(_s[x:len(_s)], 2))
                    b1 = True
                    break;
        if not b1:
            c = len(arr[0]) - 1
            if(c == 0):
                c = 1
            arr = (list(_iter(_s[0:_s.index(arr[0])], c))) + arr
    return _find(arr)
