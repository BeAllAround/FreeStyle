def findIndex(arr, obj):
    for i in range(arr.__len__()):
        for item in arr[i]:
            if item == obj:
                return i;
    return -1;

def duplicate_encode(word):
    s, i, counter = '', None, [];
    for item in word:
        if findIndex(counter, item.lower()) == -1:
            counter.append({item.lower(): 1});
        else:
            i = findIndex(counter, item.lower());
            counter[i][item.lower()] += 1;
    for item in word:
        if (counter[findIndex(counter, item.lower())][item.lower()]) > 1:
            s += ')';
        else:
            s += '(';
    return s;
