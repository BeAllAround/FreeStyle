from collections import Counter

def find_uniq(arr):
    d = dict(Counter(arr));
    return [item for item in d if d[item] == 1][0];
