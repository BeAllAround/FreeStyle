alphanumeric = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";

def alpha_n(message):
    for char in message:
        if char not in alphanumeric:
            return False;
    return True;

def separate(m, n):
    return [m[x:x+n] for x in range(0, len(m), n)];

def convert(num, bits):
    s = bin(num)[2:];
    return ((bits - len(s)) * '0') + s;

def numeric(message):
    for char in message:
        if char not in [str(x) for x in range(0, 10)]:
            return False;
    return True;

def NUMERIC():
    pass;
def ALPHA():
    pass;
def BYTE():
    pass;

def prefix(_type, message):
    if _type == NUMERIC:
        return "0001" + convert(len(message), 10);
    if _type == ALPHA:
        return "0010" + convert(len(message), 9);
    if _type == BYTE:
        return "0100" + convert(len(message), 8);

def qr_encode(message):
    if numeric(message):
        _p = prefix(NUMERIC, message);
        nums = (list(map(lambda x: str(int(x)), separate(message, 3))));
        for x, i in enumerate(nums):
            if len(i) == 3:
                nums[x] = convert(int(i), 10);
            elif len(i) == 2:
                nums[x] = convert(int(i), 7);
            elif i == '0':
                nums[x] = '0000';
            elif len(i) == 1:
                nums[x] = convert(int(i), 4);
        return _p + ''.join(nums);
    elif alpha_n(message):
        chars = separate(message, 2);
        _p = prefix(ALPHA, message);
        for x in range(len(chars)):
            if len(chars[x]) == 2:
                c = alphanumeric.index(chars[x][0]) * 45 + alphanumeric.index(chars[x][1]);
                chars[x] = convert(c, 11);
            elif len(chars[x]) == 1:
                c = alphanumeric.index(chars[x][0]);
                chars[x] = convert(c, 6);
        return _p + ''.join(chars);
    else:
        _p = prefix(BYTE, message);
        arr = [];
        for char in message:
            arr.append(convert(ord(char), 8));
        return _p + ''.join(arr);
'''
# #Codewars #Blind4Basics
CHAR_SET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:"
ALPHA    = {c:i for i,c in enumerate(CHAR_SET)}
NUMS_SET = set('0123456789')


def qr_encode(s):
    n    = 3 if set(s) <= NUMS_SET else 2 if all(map(ALPHA.__contains__,s)) else 1
    func = (_byte, _alnum, _num)[n-1]
    msg  = ''.join( func(s[i:i+n]) for i in range(0,len(s),n) )
    return f'{ "0" * n }1{ len(s) :0>10b}{ msg }'


def _byte(s):
    return f'{ ord(s) :0>8b}'

def _alnum(s):
    v = sum(ALPHA[c] * 45**i for i,c in enumerate(s[::-1]))
    return f'{ v :0>{ 6 + 5*(len(s)>1) }b}'

def _num(s):
    s = s.lstrip('0') or '0'
    return f'{ int(s) :0>{ 1+3*len(s) }b}'
'''
