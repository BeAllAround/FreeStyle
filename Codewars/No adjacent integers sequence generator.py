# solver created and coded by Alex 

def generate_sequence(lower, upper):
    _list = (list(range(lower, upper)));
    value = None;
    pos = -1;
    if(len(_list)%2 == 1):
        pos = int(len(_list)/2);
        value = _list[pos];
        del _list[pos];
    arr = [];
    first, last = 0, len(_list)-1;
    b = True;
    while(first != (len(_list)/2)-1):
        if(b):
            arr.append(_list[last]);
            arr.append(_list[first]);
            b = False;
        first+=1;
        last-=1;
        arr.append(_list[last]);
        if(_list[first]+1 == arr[len(arr)-1]):
            arr.insert(0, _list[first]);
        else:
            arr.append(_list[first]);
    if(value != None):
        arr.insert(0, value);
    return arr;

'''
// bad performance
def generate_sequence(lower, upper):
    _list = (list(range(lower, upper)));
    value = None;
    pos = -1;
    if(len(_list)%2 == 1):
        pos = int(len(_list)/2);
        value = _list[pos];
        del _list[pos];
    arr = [];
    first, last = 0, len(_list)-1;
    b = True;
    while(first != (len(_list)/2)-1):
        if(b):
            arr.insert(0, _list[last]);
            arr.append(_list[first]);
            b = False;
        first+=1;
        last-=1;
        if(_list[first]+1 == arr[0] or _list[last]+1 == arr[0]):
            arr.insert(0, _list[first]);
            arr.append(_list[last]);
        else:
            arr.insert(0, _list[last]);
            arr.append(_list[first]);
    if(value != None):
        arr.insert(pos, value);
    return arr;
'''
