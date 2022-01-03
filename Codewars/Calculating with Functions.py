def evaluate(n, *args):
    if(len(args) == 0):
        return n;
    name = args[0].__name__;
    num = args[0]();
    if(name == 't'):
        return n * num;
    if(name == 'p'):
        return n + num;
    if(name == 'm'):
        return n - num;
    if(name == 'd'):
        return int(n / num);
    
def zero(*args):
    return evaluate(0, *args);
def one(*args):
    return evaluate(1, *args);
def two(*args):
    return evaluate(2, *args);
def three(*args):
    return evaluate(3, *args);
def four(*args): 
    return evaluate(4, *args);
def five(*args):
    return evaluate(5, *args);
def six(*args):
    return evaluate(6, *args);
def seven(*args):
    return evaluate(7, *args);
def eight(*args):
    return evaluate(8, *args);
def nine(*args):
    return evaluate(9, *args);

def plus(n):
    def p():
        return n;
    return p;
def minus(n):
    def m():
        return n;
    return m;
def times(n):
    def t():
        return n;
    return t;
def divided_by(n):
    def d():
        return n;
    return d;
