def code(strng):
    dic = {"10": "0", "11": "1", "0110": "2", "0111": "3", "001110": "6", "00011001": "9", "00011000": "8", "001100": "4", "001101": "5", "001111": "7"}
    s = '';
    dic_ = {};
    for item in dic:
        dic_[dic[item]] = item;
    for item in strng:
        s += dic_[item];
    return s;
    
def decode(string):
    dic = {"10": "0", "11": "1", "0110": "2", "0111": "3", "001100": "4", "001101": "5", "001110": "6", "001111": "7", "00011000": "8", "00011001": "9"}
    i = 0;
    _str, s = '', '';
    while i < len(string):
        _str += string[i];
        if len(_str) >= 2:
            try:
                s += dic[_str];
                _str = '';
            except KeyError:
                pass;
        i += 1;
    return s;
  
'''
    # Codewars
    def code(s):
      return ''.join( f'{"0"*(d.bit_length()-1)}1{d:b}' for d in map(int,s))

    def decode(s):
        it, n, out = iter(s), 1, []
        for c in it:
            if c=='0':
                n += 1
            else:
                out.append( int(''.join(next(it) for _ in range(n)), 2) )
                n = 1
        return ''.join(map(str, out))
    #####################################################################
    from re import compile

    ENC = {str(n): '0' * ~-n.bit_length() + f'1{n:b}' for n in range(10)}
    DEC = {v: k for k, v in ENC.items()}
    BIN = compile('|'.join(reversed(DEC.keys())))

    def code(dec_str: str) -> str:
        return ''.join(map(ENC.get, dec_str))

    def decode(bin_str: str) -> str:
        return ''.join(map(DEC.get, BIN.findall(bin_str)))
'''
