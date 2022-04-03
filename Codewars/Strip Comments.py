def solution(string,markers):
    s = (string.split('\n'));
    arr = [];
    for item in s:
        _s = item;
        for marker in markers:
            try:
                _s = _s[:_s.index(marker)].strip();
            except:
                pass;
        arr.append(_s);
    return '\n'.join(arr); 

'''
from re import split, escape


def solution(string, markers):
    if markers:
        pattern = "[" + escape("".join(markers)) + "]"
    else:
        pattern = ''
    return '\n'.join(split(pattern, line)[0].rstrip() for line in string.splitlines())


def solution(string,markers):
    parts = string.split('\n')
    for s in markers:
        parts = [v.split(s)[0].rstrip() for v in parts]
    return '\n'.join(parts)
'''
