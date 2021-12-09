def isEmpty(arr):
    return len(arr) == 0;

def loop(arr, n):
    if( n <= -1):
        return [];
    arr_1 = loop(arr, n-1);
    arr_1.append(sum(arr[n:]));
    return arr_1;

def parts_sums(ls):
    # l_s = list(ls);
    return(loop(ls, len(ls)));
    # l = [ sum(ls[x:]) for x in range(0, len(ls))];
    # l.append(0);
    '''
    while n < ls.__len__(): // significantly lower
        l.append(sum(ls[n:]));
        n+=1;
    l.append(0);
    '''
    # return l;
