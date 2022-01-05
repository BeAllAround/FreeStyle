def split(s):
    return [int(item) for item in str(s)];

def m(s):
    _m = 1;
    for item in s:
        _m *= item;
    return _m;

def persistence(n):
    c = 1;
    s = split(n);
    if(len(s)==1):
        return 0;
    _m = m(s);
    while(len(str(_m)) != 1):
        s = split(_m);
        _m = m(s);
        c += 1;
    return c;
