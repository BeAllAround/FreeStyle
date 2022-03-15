def solve(s):
    c = 0;
    for x in range(0, len(s)):
        _s = '';
        for j in range(x, len(s)):
            _s += s[j];
            num = int(_s);
            if num%2 != 0:
                c += 1;
    return c;

'''
# less efficient
def solve(s):
    arr = [];
    for x in range(0, len(s)):
        _s = '';
        for j in range(x, len(s)):
            _s += s[j];
            arr.append(int(_s));
    return len(list(filter(lambda x: x%2!=0, arr)));
'''
