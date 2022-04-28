def diamond(n):
    d = '*';
    _d = ['*']
    if n == 1:
        return '*\n';
    if (n % 2 == 0) or (n <= 0):
        return None;
    n1 = n;
    while n1 > 0:
        if len(_d[-1]) == n:
            break;
        _d.append('*' +  _d[-1] + '*');
        n1 -= 1;
    f = (len(_d)-1);
    i = 0;
    while f > 0: 
        _d[i] = ' '* f + _d[i];
        f -= 1;
        i += 1;
    _d.extend(_d[:-1][::-1]);
    return '\n'.join(_d) + '\n';
