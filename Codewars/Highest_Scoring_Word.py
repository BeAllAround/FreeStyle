import string;
def max_value(obj):
    key, max = None, -1;
    for item in obj:
        if obj[item] > max:
            max = obj[item];
            key = item;
    return key;

def high(x):
    obj, obj1 = {}, {};
    i = 1;
    arr_1 = x.split(' ');
    for item in string.ascii_lowercase:
        obj1[item] = i;
        i+=1;
    for item in arr_1:
        obj[item] = 0;
        for i in item:
            obj[item] += obj1[i];
    return max_value(obj);
