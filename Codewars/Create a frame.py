def _max(arr):
    if len(arr) == 1:
        return arr[0];
    elif len(arr) == 0:
        return None;
    c = [arr[0], len(arr[0])];
    for item in arr[1:]:
        if len(item) > c[1]:
            c = [item, len(item)];
    return c[0];

def frame(text, char):
    _maxItem = (_max(text));
    s = '';
    hor = ((char * 2) + (char * len(_maxItem)) + (char*2));
    s += hor + '\n';
    for item in text:
        s += char + ' ' + item + (' ' * (len(_maxItem) - len(item))) + ' ' + char + '\n';
    s += hor;
    return s;
