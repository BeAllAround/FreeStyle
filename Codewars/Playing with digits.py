def dig_pow(n, p):
    c = 0
    n_s = list(map(int, [*str(n)]))
    for item in n_s:
        c += pow(item, p)
        p += 1
    num = c/n
    if not num.is_integer():
        return -1
    return num
  
'''
    # Codewars
    def dig_pow(n, p):
      s = 0
      for i,c in enumerate(str(n)):
         s += pow(int(c),p+i)
      return s/n if s%n==0 else -1
'''
