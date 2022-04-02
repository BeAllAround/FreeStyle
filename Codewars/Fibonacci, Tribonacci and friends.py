def Xbonacci(signature,n):
    arr = signature[:n];
    c = len(arr);
    for _ in range(n-c):
        arr.append(sum(arr[-c:])); # the last c elements
    return arr;

# Xbonacci(signature, n) => (n == |signature|)
