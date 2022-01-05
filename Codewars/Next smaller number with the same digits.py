def _insert(n):
    _l = [item for item in str(n)];
    _min = [];
    l_c = list(_l);
    c = len(l_c);
    for x in range(len(_l)):
        item = l_c[x];
        del l_c[x];
        L = list(l_c);
        for j in range(len(_l)):
            L.insert(j, item);
            if(L[0] != '0'):
                n1 = (int(''.join(L)));
                _min.append(n1);
            L = list(l_c);
        l_c = list(_l);
    _min.reverse(); 
    __min = [];
    return _min;

def next_smaller(n):
    num = n;
    _n = [];
    n1 = _insert(n);
    for item in n1:
        if item < n:
            _n.append(item);
    
    if(len(_n)==0):
        return -1;
    
    while(len(_n) != 0):
        n = max(_n);
        _n = [];
        n1 = _insert(n);
        for item in n1:
            if item > n and item < num:
                _n.append(item);
    return n;
