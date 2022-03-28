def zero_base(arr):
    for item in arr:
        if item != 0:
            return False;
    return True;

def expansion(matrix, n):
    _matrix = [];
    for m in matrix:
        _m = list(m);
        for j in range(n):
            _m.append(0);
        _matrix.append(_m);
    for _ in range(n):
        _matrix.append([0 for _ in range(len(_matrix[0]))])
    for x in range(len(_matrix)):
        if not zero_base(_matrix[x]):
            _i = n;
            for _ in range(n):
                _matrix[x][-_i] = (sum(_matrix[x][:-_i]));
                _i -= 1;
        else:
            c = 0;
            _s = 0;
            _arr = [];
            while c < len(_matrix[x]):
                for j in range(0, x):
                    _s += _matrix[j][c]
                c += 1;
                _arr.append(_s);
                _s = 0;
            c = 0; # reset
            _s = 0;
            for j in range(0, x):
                _s += _matrix[j][c]
                c += 1;
            _arr[c] = _s;
            c += 1;
            while c < len(_matrix[x]):
                _arr[c] = sum(_arr[:c]);
                c += 1;
            _matrix[x] = list(_arr);
    return _matrix;
