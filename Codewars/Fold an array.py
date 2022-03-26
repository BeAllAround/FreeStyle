def diff(arr, arr1):
    for _ in range(len(arr1)-len(arr)):
        arr.append(0);
    return arr;

def fold_array(array, runs):
    while runs > 0:
        if len(array)%2 != 0:
            d = int((len(array) / 2)) + 1;
            a = array[:d];
            a1 = list(reversed(array[d:]));
            a1 = diff(a1, a);
            for x in range(len(a)):
                a[x] += a1[x];
            array = list(a);
        else:
            d = int(len(array)/2);
            a = array[:d];
            a1 = list(reversed(array[d:]));
            for x in range(len(a)):
                a[x] += a1[x];
            array = list(a);
        runs -= 1;
    return array;
