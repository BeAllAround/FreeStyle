from functools import reduce;

def _m(a, b):
    if len(b) > len(a):
        a = b;
    return a;

def _get(s, item): # exception-free
    try:
        return s[item];
    except IndexError:
        return '';

def sep_str(st): 
    s = st.split(' ');
    arr = [];
    _ = (reduce(_m, s, ''));
    for x in range(len(_)):
        arr.append([]);
        for item in s:
            arr[-1].append(_get(item, x));
    return arr;
  
'''
from itertools import zip_longest
from functools import partial

sep = partial(zip_longest, fillvalue='')

def sep_str(st): 
    return list(map(list, sep(*st.split())))
    
    

from itertools import zip_longest


def sep_str(st):
    return [[*cs] for cs in zip_longest(*st.split(), fillvalue='')]
'''
