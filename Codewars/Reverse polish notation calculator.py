def calc(expr):
    arr = [];
    opers = {'+': lambda x, y: x + y,
             '-': lambda x, y: x - y,
             '*': lambda x, y: x * y,
             '/': lambda x, y: x / y
            };
    for e in expr.split(' '):
        if '.' in e:
            arr.append(float(e));
        elif e.isdigit():
            arr.append(int(e));
        elif e in ['-', '+', '*', '/']:
            arr.append(opers[e](arr.pop(len(arr)-2), arr.pop()));
    arr.append(0);
    return arr.pop(0);
