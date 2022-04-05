def calc(expr):
    arr = [];
    for e in expr.split(' '):
        if '.' in e:
            arr.append(float(e));
        elif e.isdigit():
            arr.append(int(e));
        else:
            if e == '+':
                arr[-2] = arr[-1] + arr[-2];
                del arr[-1];
            elif e == '*':
                arr[-2] = arr[-1] * arr[-2];
                del arr[-1];
            elif e == '-':
                arr[-2] = arr[-2] - arr[-1];
                del arr[-1];
            elif e == '/':
                arr[-2] = int(arr[-2] / arr[-1]);
                del arr[-1];
    arr.append(0);
    return arr.pop(0);
  
'''
import operator

def calc(expr):
    OPERATORS = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.truediv}
    stack = [0]
    for token in expr.split(" "):
        if token in OPERATORS:
            op2, op1 = stack.pop(), stack.pop()
            stack.append(OPERATORS[token](op1,op2))
        elif token:
            stack.append(float(token))
    return stack.pop()

operator = set(['+', '-', '*', '/'])

def calc(expr):
    stack = list()
    for c in expr.split():
        if c in operator : 
            first = stack.pop()
            second = stack.pop()
            stack.append(str(eval(second + c + first)))
        else : stack.append(c)
    return eval(stack.pop()) if stack else 0
'''
