from functools import cmp_to_key;

def _f(c1, c2):
    c3 = sum(map(int, c1));
    c4 = sum(map(int, c2));
    if c3 < c4:
        return -1;
    elif c3 > c4:
        return 0;
    elif c3 == c4:
        if c1 < c2:
            return -1;
    return 0;

def order_weight(string):
    l = list(filter(lambda x: x != ' ', string.split(' ')));
    l.sort(key=cmp_to_key(_f));
    return ' '.join(l);
