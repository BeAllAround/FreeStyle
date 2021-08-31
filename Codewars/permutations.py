import itertools;

def permutations(string):
    arr_2, str_1, arr = [], '', (list(itertools.permutations(string, len(string))));
    for item in arr:
        for j in item:
            str_1 += j;
        arr_2.append(str_1);
        str_1 = '';
    return list(set(arr_2));

def permutations(string):
    return list(set([''.join(item) for item in itertools.permutations(string, len(string))])); # a python native solution
