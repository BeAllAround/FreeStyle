def encrypt_this(text):
    arr = [];
    s = '';
    for t in text.split(' '):
        t = [*t];
        if len(t) >= 1:
            s += str(ord(t[0]));
            if len(t) == 1:
                s += ' ';
        if len(t) > 2:
            s += t[-1] + ''.join(t[2:len(t)-1]) + ''.join(t[1:2]) + ' ';
            # t = t[1:]; # alternative approach
            # temp = t[0];
            # t[0] = t[-1];
            # t[-1] = temp;
            # s += ''.join(t) + ' ';
        elif len(t) == 2:
            s += t[-1] + ' ';
    return s.strip();
