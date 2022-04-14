def solve(n):
    l = [500, 200, 100, 50, 20, 10];
    c = 0;
    b = True;
    while n > 0:
        for item in l:
            if n-item >= 0:
                n -= item;
                c += 1;
                b = False;
                break;
        if b:
            return -1;
        b = True;
    return c;
