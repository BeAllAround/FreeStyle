def multiplication_table(size):
    arr = [];
    for x in range(1, size+1):
        a = [];
        for j in range(0, size*x, x):
            a.append(x+j);
        arr.append(a);
    return arr;
