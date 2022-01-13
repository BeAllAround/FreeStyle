import string, hashlib;

def produce_check(arr, hash):
    l1 = [];
    b = True;
    try:
        l2 = arr.pop(0);
        l_ = arr.pop(0);
    except IndexError:
        b = False;
    while b:
        for item in l2:
            for jtem in l_:
                string = item+jtem;
                if hashlib.sha1(string.encode()).hexdigest() == hash:
                    return string;
                l1.append(string);
        l2 = list(l1);
        try:
            l_ = arr.pop(0);
        except IndexError:
            b = False;
        l1.clear();
    raise "Not found";
    
def password_cracker(hash):
    return produce_check([string.ascii_lowercase for x in range(5)], hash);
  
  '''
    # Codewars
    import hashlib
    import itertools

    def password_cracker(hash):
        for length in range(6):
            for candidate in map("".join, itertools.product("abcdefghijklmnopqrstuvwxyz", repeat=length)):
                if hashlib.sha1(candidate.encode()).hexdigest() == hash:
                    return candidate
'''
