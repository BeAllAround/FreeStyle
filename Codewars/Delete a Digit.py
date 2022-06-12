def delete_digit(n):
    arr = [];
    n1 = [*str(n)];
    for i, j in enumerate(str(n)): 
        del n1[i];
        arr.append(int(''.join(n1), 10));
        n1 = [*str(n)];
    return max(arr);
