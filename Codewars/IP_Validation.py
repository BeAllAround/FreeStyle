import string as _str;
_str.all = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~ ';
def is_valid_IP(string):
    arr = (string.split('.'));
    item = None;
    range_1 = [str(item) for item in range(0, 255+1)];
    if(len(arr) != 4):
        return False;
    for i in range(len(arr)):
        item = arr[i];
        if(item[0] == '0' and len(item) > 1):
            return False;
        elif(item in _str.all):
            return False;
        elif(item not in range_1):
            return False;
    return True;

print(is_valid_IP('192.168.1.300'));
print(is_valid_IP('123.456.789.0'));
print(is_valid_IP('0.34.82.53'));
print(is_valid_IP('0.0.0.0'));


