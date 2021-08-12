as_long_as = False;
def includes(arr, item):
    for _item in arr:
        if _item == item:
            return True;
    return False;

def findIndex(arr, item):
    for x in range(0, len(arr)):
        if arr[x] == item:
            return x;
    return -1;

def removeItem(arr, item):
    global as_long_as; # take advantage of the keyword "global" or wrap all of it into a class since there are no pointers in python!
    inx, _new = None, [];
    if includes(arr, item):
        inx = findIndex(arr, item);
        if inx != -1:
            for x in range(0, inx):
                _new.append(arr[x]);
            for x in range(inx+1, len(arr)):
                _new.append(arr[x]);
            as_long_as = True;
        return _new;
    as_long_as = False;
    return arr;

def array_diff(a, b):
    if(len(a) == 0):
        return [];
    if(len(b) == 0):
        return a;
    for item in b:
        a = removeItem(a, item);
        while(as_long_as): # remove as long as you can
            a = removeItem(a, item);
    return a;

if __name__ == '__main__':
    print(array_diff([1, 2, 2], [2]));
