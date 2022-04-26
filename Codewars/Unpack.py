def d(l, _l):
    try:
        if not type(l) == str:
            for item in l:
                d(item, _l);
                if type(l) == dict:
                    d(l[item], _l);
        else:
            _l.append(l);
    except TypeError:
        _l.append(l);

def unpack(l):
    v = [];
    d(l, v);
    return v;

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
