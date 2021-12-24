class Converter():
    @staticmethod
    def to_ascii(h):
        _s = '';
        h = [item for item in h];
        n = 0;
        n1 = 2;
        while(n <= len(h)): # add exception handling if needed
            _s += (bytes.fromhex(''.join(h[n:n1])).decode("ASCII"));
            n += 2;
            n1 += 2;
        return _s;
    @staticmethod
    def to_hex(s):
        return ''.join([hex(ord(item))[2::] for item in s]);

    
# or more suitable scripting Python-based solution
'''
class Converter():
    @staticmethod
    def to_ascii(h):
        return ''.join([bytes.fromhex(h[x:x+2]).decode("ASCII") for x in range(0, len(h), 2)]);
    @staticmethod
    def to_hex(s):
        return ''.join([hex(ord(item))[2::] for item in s]);
'''
