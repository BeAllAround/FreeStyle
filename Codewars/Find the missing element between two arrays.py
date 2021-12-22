def findIndex(arr, item):
    for x in range(len(arr)):
        if(arr[x] == item):
            return x;
    return -1;

def find_missing(arr1, arr2):
    arr_c = list(arr1);
    x = 0;
    for item in arr2:
        x = findIndex(arr_c, item);
        if(x != -1):
            del arr_c[x];
    return arr_c[0]; # just return what's left
