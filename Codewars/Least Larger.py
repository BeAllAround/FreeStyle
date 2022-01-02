def _min(arr):
    b = [0, max(list(map(lambda x: x[1], arr)))];
    for item in arr:
        if(item[1] <= b[1]):
            b = item;
    return b[0];
        
def least_larger(a, i): 
    arr = [];
    item = a[i];
    for x in range(0, len(a)):
        if a[x] > item:
            arr.append([x, a[x]])
    if(len(arr)==0):
        return -1;
    return _min(arr);
