def loop(n1, n, arr):
    for item in arr:
        if isinstance(item, list):
            n = loop(n1+1, n, item)
        else:
            n += item**n1;
    return n;
def sum_nested_numbers(arr):
    return loop(1, 0, arr);

def nested(n, arr):
    if(isinstance(arr, list)):
        for item in arr:
            n = nested(n, item);
    else:
        n += arr;
    return n;
def sum_nested(lst):
    return nested(0, lst);
