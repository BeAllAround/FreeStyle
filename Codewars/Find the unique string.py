def equal(item, item2):
    c = 0;
    item = list(set([*item]));
    item2 = list(set([*item2]));
    for i in item:
        if i in item2:
            c += 1;
    return c == len(item2);

def _f(s):
    if s == '':
        return ' ';
    return s;

def every(arr):
    a = list(arr);
    try:
        item = a.pop(0);
    except IndexError:
        return True
    for j in a:
        if item != j:
            return False;
    return True;

def find_uniq(arr):
    arr_c = list(map(_f, arr));
    item = arr_c.pop(0);
    if(every(arr_c)):
        return item;
    for j in arr_c:
        if not equal(item.lower(), j.lower()):
            return j;
        item = j;
'''
    # Codewars
    from collections import defaultdict

    def find_uniq(a):
        d = {}
        c = defaultdict(int)
        for e in a:
            t = frozenset(e.strip().lower())
            d[t] = e
            c[t] += 1

        return d[next(filter(lambda k: c[k] == 1, c))]
'''
