def _f(l, s):
    i = 0;
    _s = 0;
    for item in s[::-1]:
        _s += l.index(item) * pow(len(l), i);
        i += 1;
    return _s;

def _all(n, d, l):
    s = '';
    n = _f(d, n);
    if n == 0:
        return l[n];
    while n > 0:
        s += (l[n % len(l)]);
        n = int(n/len(l));
    return s[::-1];

def convert(input, source, target):
    return _all(input, source, target);
  
'''

bin      = '01'
oct      = '01234567'
dec      = '0123456789'
hex      = '0123456789abcdef'
allow    = 'abcdefghijklmnopqrstuvwxyz'
allup    = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
alpha    = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
alphanum = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'


convert("15", dec, bin)       ==>  "1111"
convert("15", dec, oct)       ==>  "17"
convert("1010", bin, dec)     ==>  "10"
convert("1010", bin, hex)     ==>  "a"
convert("0", dec, alpha)      ==>  "a"
convert("27", dec, allow)     ==>  "bb"
convert("hello", allow, hex)  ==>  "320048"


'''
