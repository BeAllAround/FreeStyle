def digital_root(n):
    n = sum(list(map(int, [*str(n)])))
    if len(str(n)) == 1:
        return n
    return digital_root(n)
