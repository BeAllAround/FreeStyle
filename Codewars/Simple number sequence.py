def _iter(s, _split):
    for x in range(0, len(s), _split):
        yield (s[x : x+_split]);

def check_sort(arr):
    return arr == sorted(arr);

def _find(arr):
    arr = list(map(int, arr));
    item = arr[0];
    arr1 = [];
    for j in arr[1:]:
        if(item+2 == j):
            arr1.append(item+1);
        item = j;
    if(len(arr1) == 0 or len(arr1) > 1):
        return -1;
    return arr1[0];
    
def missing(s):
    arr = [];
    arr1 = []
    item = None
    for x in range(1, 10000):
        arr = list(_iter(s, x));
        if(check_sort(arr)):
            break;
    if len(arr) == 1 or len(arr) == 2:
        _s = s;
        b = False;
        for x in range(1, 10010):
            arr = list(_iter(s, x));
            for item in arr:
                if(item.startswith('0')):
                    s = (s[s.index('10'):len(s)])
                    b = True
                    continue
            if(check_sort(arr)):
                break
        if not b:
            return 10
        arr = (list(_iter(_s[0:_s.index(arr[0])], len(arr[0])-1))) + arr;
    return _find(arr)
