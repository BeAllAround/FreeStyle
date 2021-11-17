def maxSub(arr, k):
    it, dump, n, _d = '', '', '', [];
    for i in range(len(arr)):
        item = arr[i];
        if(i + k <= len(arr)):
            for j in range(i, i+k):
                dump += arr[j];
            if(len(dump) > len(n)):
                n = dump;
        dump = '';
    return n;

def longest_consec(strarr, k):
    return maxSub(strarr, k);
