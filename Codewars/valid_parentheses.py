class Token:
    def __init__(self, s):
        self.s = s;
        self.i = -1;
        self.b = False;
    def get(self):
        if self.i == len(self.s)-1:
            return False;
        self.i += 1;
        return True;
    @property
    def current(self):
        return self.s[self.i];
    @property
    def lp(self):
        return self.current == '(';
    @property
    def rp(self):
        return self.current == ')';
    
def _valid(t):
    while t.get():
        if t.lp:
            try:
                _valid(t);
            except Exception:
                if(not t.rp):
                    raise Exception();
            else:
                raise Exception();
        elif t.rp:
            raise Exception();
    
def valid_parentheses(string):
    # print(string);
    c = 0;
    if(string==''):
        return True;
    t = Token(string);
    try:
        (_valid(t));
    except Exception:
        return (False);
    return True;

if __name__ == "__main__":
    print(valid_parentheses("dd()jtkr(urmf)i()d")); # True
    print(valid_parentheses("(())(())")); # True
    print(valid_parentheses("((()))")); # True
    print(valid_parentheses("hi(hi)()")); # True;
    print(valid_parentheses("((()))())")); # False
    print(valid_parentheses(")()()")); # False
    print(valid_parentheses("()()(")); # False
    print(valid_parentheses("()())(")); # False
