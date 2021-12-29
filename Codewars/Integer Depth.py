def compute_depth(n):
    arr, i = [], 1;
    while(True):
        for item in str(n*i):
            if(item not in arr):
                arr.append(item);
        if(len(arr) == 10):
            return i;
        i+=1;
