def pop(arr):
    try:
        return arr.pop(0);
    except IndexError:
        return None;
    
def produce(arr):
    l1 = [];
    l2 = pop(arr);
    l_ = pop(arr);
    while l_ != None:
        for item in l2:
            for jtem in l_:
                l1.append(item+jtem)
        l2 = list(l1);
        l_ = pop(arr);
        if(l_ == None):
            return l2;
        l1 = []; ### l1.clear();
        
def get_pins(observed):
    pins = {1: [1,2, 4], 2: [1,2, 3, 5], 3: [3,2, 6], 4: [1, 4,5,7], 5: [2, 4,5, 6, 8], 6:[3, 5,6, 9], 7: [4,7, 8], 8: [5, 7,8, 9, 0], 9: [8, 6, 9], 0:[0,8]}
    arr = [];
    for item in observed:
        arr.append([])
        arr[len(arr)-1].extend(list(map(str, pins[int(item)])));
    use = (arr).pop(0);
    if(len(arr) == 0):
        return use;
    return produce([use, *arr]);

'''
    # Codewars
    from itertools import product

    ADJACENTS = ('08', '124', '2135', '326', '4157', '52468', '6359', '748', '85790', '968')

    def get_pins(observed):
        return [''.join(p) for p in product(*(ADJACENTS[int(d)] for d in observed))]
'''
