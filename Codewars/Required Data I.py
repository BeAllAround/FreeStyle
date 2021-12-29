from collections import Counter;

def __max(arr):
    _ = 0;
    for item in arr:
        if item[1] > _:
            _ = item[1];
    return _;

def count_sel(lst):
    _d = (dict(Counter(lst)));
    arr = [];
    for item in _d:
        arr.append([item, _d[item]]);
    _max = __max(arr);
    one = len(arr);
    two = len(list(filter(lambda x: x[1] == 1, arr)));
    three = list(map(lambda x: x[0], list(filter(lambda x: x[1] == _max, arr))));
    three.sort();
    
    return ([len(lst), one, two, [three, _max]]);
