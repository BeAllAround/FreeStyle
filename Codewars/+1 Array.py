def up_array(arr):
    try:
        for item in arr:
            if len(str(item)) != 1:
                return None;
        return list(map(int, [*str(int(''.join(map(str, arr)))+1)]));
    except ValueError:
        return None;

'''
#Codewars
def up_array(arr):
    if not arr or min(arr) < 0 or max(arr) > 9:
        return None
    else:
        return [int(y) for y in str(int("".join([str(x) for x in arr])) + 1)]

def up_array(arr):
    if arr and all(0<=v<=9 for v in arr):
        return map(int, str(int(''.join(map(str,arr)))+1))

def up_array(a):
    if not a or any(not 0 <= x < 10 for x in a): return
    for i in range(1, len(a)+1):
        a[-i] = (a[-i] + 1) % 10
        if a[-i]: break
    else: a[:0] = [1]
    return a

def up_array(arr):
    return None if arr==[] or any([x not in range(10) for x in arr]) else [int(c) for c in str(int("".join([str(x) for x in arr]))+1)]
'''
