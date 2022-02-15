def findIndex(arr, item):
    try:
        return arr.index(item);
    except ValueError:
        return -1;
    
class keyword_cipher(object):
    def __init__(self, abc, keyword):
        self._abc = abc;
        self.abc = [*abc];
        self.keyword = keyword;
        for x in range(len(self.keyword)):
            item = self.keyword[x];
            index = findIndex(self.abc, item);
            if index != -1:
                del self.abc[index];
        x = [*self.keyword];
        self.keyword = ''.join(list(sorted(set(x), key=x.index)));
        self.abc = self.keyword + ''.join(self.abc);
    def encode(self, plain):
        _str = '';
        inxes = [];
        _c = (len(self.abc) - len(self._abc));
        for item in plain:
            try:
                x = (self._abc.index(item));
                _str += self.abc[x];
            except ValueError:
                _str += item;
        return _str;
                
    def decode(self, ciphered):
        inxes = [];
        _str = '';
        for item in ciphered:
            try:
                x = (self.abc.index(item));
                _str += self._abc[x];
            except:
                _str += item;
        return _str;
