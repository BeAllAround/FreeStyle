def pop(arr):
    try:
        return arr.pop(0);
    except IndexError:
        return None;
    
def _use(_arr, n):
    s = '';
    __arr = [];
    _pop = pop(_arr);
    __pop = pop(_arr);
    while(_pop!=None and __pop != None):
        for item in _pop:
            for jtem in __pop:
                s+= item + jtem;
                __arr.append(s);
                s = '';
        _pop = pop(_arr);
        __pop = pop(_arr);
            
    return __arr;
    
def crop(arr):
    l1 = [];
    _arr = list(arr);
    l = (_use(arr, 0));
    try:
        pop(_arr);
        pop(_arr);
    except IndexError:
        pass;
    if(len(_arr)==0):
        return l;
    l_ = pop(_arr);
    while(l_!=None):
        for item in l:
            for jtem in l_:
                l1.append(item+jtem)
        l = list(l1);
        l_ = pop(_arr);
        if(l_ == None):
            return list(set(l));
        l1 = [];

def get_pins(observed):
    pins = {1: [1,2, 4], 2: [1,2, 3, 5], 3: [3,2, 6], 4: [1, 4,5,7], 5: [2, 4,5, 6, 8], 6:[3, 5,6, 9], 7: [4,7, 8], 8: [5, 7,8, 9, 0], 9: [8, 6, 9], 0:[0,8]}
    arr = [];
    for item in observed:
        arr.append([])
        arr[len(arr)-1].extend(list(map(str, pins[int(item)])));
    use = (arr).pop(0);
    if(len(arr) == 0):
        return use;
    _arr = [];
    if(len(arr) == 1):
        for item in use:
            for jtem in arr:
                for k in jtem:
                    _arr.append(item+k)
        return _arr;
    arr = crop(arr);
    
    for item in use:
        for jtem in arr:
            _arr.append(item+jtem);
    return _arr;

'''
    # Codewars
    from itertools import product

    ADJACENTS = ('08', '124', '2135', '326', '4157', '52468', '6359', '748', '85790', '968')

    def get_pins(observed):
        return [''.join(p) for p in product(*(ADJACENTS[int(d)] for d in observed))]
'''
