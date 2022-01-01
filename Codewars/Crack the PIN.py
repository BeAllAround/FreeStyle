import hashlib;

def encrypt(_pass):
    return hashlib.md5(_pass.encode()).hexdigest();

def search(hash, _s, n):
    if n > 5:
        return [False, '']
    if n == 5:
        if encrypt(_s) == hash:
            return [True, _s];
        else:
            return [False, ''];
    for x in range(0, 10):
        v = search(hash, _s+str(x), n+1);
        if v[0]:
            return v;
    return [False, ''];

def crack(hash):
    b, value = search(hash, '', 0);
    if b:
        return value;
    return '';
