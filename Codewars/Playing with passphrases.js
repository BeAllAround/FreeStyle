import string;

def shift(c, n):
    n1 = n;
    _dic = string.ascii_lowercase;
    n = _dic.index(c.lower());
    while n+n1 >= 26:
        n -= 26;
    return _dic[n+n1];

def play_pass(s, n):
    _str = '';
    digits = [str(item) for item in range(0, 10)];
    for x in range(len(s)):
        item = s[x].lower();
        if(item in digits):
            _str += str(9 - int(item));
        elif item in string.ascii_lowercase:
            if(x % 2 == 0):
                _str += shift(item, n).upper();
            else:
                _str += shift(item, n).lower();
        else:
            _str += item;
    return ''.join(list(reversed([*_str])));
