def last_digit(lst):
    if len(lst) == 0:
        return 1
    if len(lst) == 2:
        return pow(lst[0], lst[1], 10)
    if len(lst) == 1:
        return lst[0] % 10;
    l2 = lst.pop()
    l = lst.pop()
    n = 1000000000000000000000000000 # n = int("1" +  ("0000000000000000000000" * 20))
    _l = pow(l, l2, n)
    num = pow(lst.pop(), _l, n);
    while len(lst) != 0:
        num = pow(lst.pop(),num, n)
    return num % 10

'''
  #Codewars
  import functools
  def powmod(e, b):
      if e==0 or b==1:
          return 1
      if e==1 or b==0:
          return b
      else:
          return pow(b, e, 20)+20


  def last_digit(lst):
      return functools.reduce(powmod, lst[::-1], 1) % 10
'''
