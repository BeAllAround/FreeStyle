def _stringify(_num):
    n = 1;
    if len(str(_num)) >= 3:
        n = 2;
    _dict = {1: "st", 2: "nd", 3: "rd"};
    for x in range(10, 20):
        _dict[x] = 'th';
    try:
        return str(_num) + _dict[_num];
    except KeyError:
        try:
            return str(_num) + _dict[int(str(_num)[(len(str(_num))-n):len(str(_num))])];
        except KeyError:
            return str(_num) + 'th';

def what_century(year):
    digits = '123456789';
    y__ = int(year)/100;
    y_ = str(y__);
    for d in (y_[y_.index('.')+1:]):
        if d in digits:
            return _stringify(int(y__+1));
    return _stringify(int(y__));

'''
#Codewars
def what_century(year):
    n = (int(year) - 1) // 100 + 1
    return str(n) + ("th" if n < 20 else {1: "st", 2: "nd", 3: "rd"}.get(n % 10, "th"))

import math
def whatCentury(year):
    year = math.ceil(int(year)/100)
    if year//10 == 1 :
      return str(year) + 'th'
    elif year%10 == 1 :
      return str(year) + 'st'
    elif year%10 == 2 :
      return str(year) + 'nd'
    elif year%10 == 3 :
      return str(year) + 'rd'
    else :
      return str(year) + 'th'
'''
