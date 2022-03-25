def constant(arr):
    if len(list(set(arr))) == 1:
        return True;
    return False;

def unordered(arr):
    arr_c = sorted(arr);
    return arr != arr_c;

def not_increase(arr):
    item = arr[0];
    b = False;
    for j in arr[1:]:
        if item == j:
            b = True;
        elif item < j:
            return False;
        item = j;
    return b;

def s_d(arr):
    item = arr[0];
    c = 1;
    for j in arr[1:]:
        if item > j:
            c += 1;
        item = j;
    return len(arr) == c;

def n_d(arr):
    item = arr[0];
    b = False;
    for j in arr[1:]:
        if j < item:
            return False;
        elif j == item:
            b = True;
        item = j;
    return b;

def s_i(arr):
    item = arr[0];
    c = 1;
    for j in arr[1:]:
        if j > item:
            pass;
        else:
            return False;
        item = j;
    return True;

def sequence_classifier(arr): # a crafty way to write it
    bools = [constant(arr), not_increase(arr), s_d(arr), n_d(arr), s_i(arr), unordered(arr)];
    for i, b in enumerate(bools):
        if b:
            return len(bools)-i-1;
    return -1;

'''
# Codewars
# Blind4Basics
TYPE_SEQ = {(1,): 1, (0,1): 2, (-1,):3, (-1,0): 4, (0,): 5}

def sequence_classifier(arr):
    countSet = { (a<b) - (a>b) for a,b in zip(arr, arr[1:]) }
    return TYPE_SEQ.get(tuple(sorted(countSet)), 0)

'''
