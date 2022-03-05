def one(arr):
    for BOOL in arr:
        if BOOL:
            return True
    return False

def _unpack(l, _list):
    if one([isinstance(l, _type) for _type in [list, tuple, set]]):
        for item in l:
            _list = _unpack(item, _list)
    elif isinstance(l, dict):
        for key in l.keys():
            _list.append(key)
            _list = _unpack(l[key], _list)
    else:
        _list.append(l)
    return _list

def unpack(l):
    for _ in range(2):
        l = _unpack(l, [])
    return l

'''
  # Codewars
  from collections import Iterable

  def unpack(iterable):
      lst = []
      for x in iterable:
          if   isinstance(x,dict):     x = unpack(x.items())
          elif isinstance(x,str):      x = [x]
          elif isinstance(x,Iterable): x = unpack(x)
          else:                        x = [x]
          lst.extend(x)
      return lst
'''
