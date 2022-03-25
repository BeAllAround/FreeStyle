def constant(arr):
    if len(list(set(arr))) == 1:
        return True;
    return False;

def unordered(arr):
    arr_c = sorted(arr);
    return arr != arr_c;

def not_increase(arr):
    item = arr[0];
    a = [];
    c = 0;
    b = False;
    for j in arr[1:]:
        if item > j:
            a.append(True);
        if item == j:
            b = True;
        if item < j:
            a.append(False);
        item = j;
    return all(a) and b;

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
    c = 1;
    b = False;
    a = [];
    for j in arr[1:]:
        if item >= j:
            a.append(True);
        if item == j:
            b = True;
        if j < item:
            a.append(False);
        item = j;
    return all(a) and b;

def s_i(arr):
    item = arr[0];
    c = 1;
    for j in arr[1:]:
        if j > item:
            c += 1;
        item = j;
    return c == len(arr); 

def sequence_classifier(arr):
    if constant(arr):
        return 5;
    if not_increase(arr):
        return 4;
    if s_d(arr):
        return 3;
    if n_d(arr):
        return 2;
    if s_i(arr):
        return 1;
    if unordered(arr):
        return 0;

'''
# Codewars
# Blind4Basics
TYPE_SEQ = {(1,): 1, (0,1): 2, (-1,):3, (-1,0): 4, (0,): 5}

def sequence_classifier(arr):
    countSet = { (a<b) - (a>b) for a,b in zip(arr, arr[1:]) }
    return TYPE_SEQ.get(tuple(sorted(countSet)), 0)

'''
