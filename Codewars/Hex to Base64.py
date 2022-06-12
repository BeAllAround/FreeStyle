import re;

_text = '''000000   A   010000  Q   100000  g   110000  w
000001  B   010001  R   100001  h   110001  x
000010  C   010010  S   100010  i   110010  y
000011  D   010011  T   100011  j   110011  z
000100  E   010100  U   100100  k   110100  0
000101  F   010101  V   100101  l   110101  1
000110  G   010110  W   100110  m   110110  2
000111  H   010111  X   100111  n   110111  3
001000  I   011000  Y   101000  o   111000  4
001001  J   011001  Z   101001  p   111001  5
001010  K   011010  a   101010  q   111010  6
001011  L   011011  b   101011  r   111011  7
001100  M   011100  c   101100  s   111100  8
001101  N   011101  d   101101  t   111101  9
001110  O   011110  e   101110  u   111110  +
001111  P   011111  f   101111  v   111111  /''';

l = re.split('\t|\n', _text);
_d = {};
for x in range(0, len(l), 2):
    _d[l[x]] =  l[x+1];

def _(_bin, _bits, v = 0):
    _s = bin(int(_bin, 16))[2:];
    return ('0' * (_bits - len(_s))) + _s;

def toBin(_str, bits):
    S = '';
    for x in range(0, len(_str), 2):
        i = _str[x:x+2];
        S+=_(i, bits);
    return S;

def _t(s): # pre-padding
    _s = '';
    i = None;
    for x in range(0, len(s), 6):
        i = s[x:x+6];
        _s += (i + ('0' * (6 - len(i))));
    return _s;

def _c(s):
    c = 0;
    i = None;
    l = [];
    for x in range(0, len(s), 4):
        i = s[x:x+4];
        l.append(i);
    return l;
    
def hex_to_base64(hex: str) -> str:
    _s = '';
    __s = '';
    __t = (_t(toBin(hex, 8)));
    for item in __t:
        _s += item;
        try:
            __s += _d[_s] 
            _s = '';
        except KeyError:
            pass;
    _l = (_c(__s));
    if len(_l[-1]) != 4: # padding
        _l[-1] = _l[-1] + ('=' * (4 - len(_l[-1])));
    return ''.join(_l);
