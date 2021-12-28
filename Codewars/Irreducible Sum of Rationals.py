from fractions import Fraction;
from functools import reduce

def sum_fracts(lst):
    s, f_c = 0, 0;
    s = reduce(lambda a, b: a+b[0]/b[1], lst, 0);
    if(s%1 == 0): # check for remainder 
        if(s == 0):
            return None;
        return int(s);
    f_c = reduce(lambda a, b: a + Fraction(b[0], b[1]), lst[1:], Fraction(lst[0][0], lst[0][1]));
    return list(map(int, str(f_c).split('/')));
