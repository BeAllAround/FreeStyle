def data_reverse(data):
    arr, arr1 = [], [];
    for x in range(0, len(data), 8):
        arr.append(data[x:x+8])
    arr.reverse();
    for item in arr:
        arr1.extend(item);
    return arr1;
