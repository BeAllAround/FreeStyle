def fib(n):
    l = [0, 1];
    for _ in range(n-2):
        l.append(l[-1] + l[-2]);
    return l;

def productFib(prod):
    f = fib(500);
    for x in range(len(f)):
        try:
            if f[x]*f[x+1] == prod:
                return [f[x], f[x+1], True];
            elif f[x] * f[x+1] < prod < f[x+1] * f[x+2]:
                return [f[x+1], f[x+2], False];
        except IndexError:
            break; # return None

'''
#Codewars
def make_fib(a=1, b=1):
    while True:
        yield (a, b)
        a, b = b, a+b

def productFib(prod):
    for n1, n2 in make_fib():
        if n1 * n2 == prod:
            return [n1, n2, True]
        if n1 * n2 > prod:
            return[n1,n2, False]

def productFib(prod):
  a, b = 0, 1
  while prod > a * b:
    a, b = b, a + b
  return [a, b, prod == a * b]
'''
