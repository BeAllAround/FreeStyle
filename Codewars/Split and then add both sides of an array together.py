def diff(arr, arr1):
    for _ in range(len(arr1)-len(arr)):
        arr.insert(0, 0);
    return arr;

def split_and_add(numbers, n):
    while n > 0:
        d = int(len(numbers)/2);
        a = numbers[:d];
        a1 = numbers[d:];
        a = diff(a, a1);
        a1 = diff(a1, a);
        for x in range(len(a)):
            a[x] += a1[x];
        numbers = list(a);
        n -= 1;
    return numbers;
