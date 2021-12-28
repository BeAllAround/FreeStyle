from fractions import Fraction;
from functools import reduce

def sum_fracts(lst):
    s = 0;
    f_c = 0;
    for item in lst:
        s += item[0] / item[1];
    if(s%1 == 0):
        if(s == 0):
            return None;
        return (int(s));
    f_c = reduce(lambda a, b: a + Fraction(b[0], b[1]), lst[1:], Fraction(lst[0][0], lst[0][1]));
    return list(map(lambda x: int(x), str(f_c).split('/')));
