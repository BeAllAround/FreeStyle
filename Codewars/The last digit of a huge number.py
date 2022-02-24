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

    def last_digit(lst):
        if not lst:
            return 1
        else:
            out = 1
            for n in lst[len(lst):0:-1]:
                out = n**out
                if out > 2:
                    out -= 2
                    out %= 4
                    out += 2
        return lst[0]**out% 10
        
   def last_digit(lst):
    n = 1
    for x in reversed(lst):
        n = x ** (n if n < 4 else n % 4 + 4)
    return n % 10
'''
