from collections import Counter;

def palindrome(num):
    c = 0;
    if isinstance(num, str) or num < 0:
        return 'Not valid';
    if len(str(num))==1:
        return False;
    _d = dict(Counter([*str(num)]));
    for item in _d:
        if(_d[item] % 2 != 0):
            c+=1;
        if c == 2:
            return False;
    return True;
