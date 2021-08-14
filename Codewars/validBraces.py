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
    @property
    def rb(self):
        return self.current == '}';
    @property
    def lb(self):
        return self.current == '{';
    @property
    def r_b(self):
        return self.current == ']';
    @property
    def l_b(self):
        return self.current == '[';

class Parenthesis(Exception):
    pass;

class Bracket(Exception):
    pass;

class Bracket1(Exception):
    pass;

def _valid(t):
    while t.get():
        if t.lp:
            try:
                _valid(t);
            except Parenthesis:
                if not t.rp:
                    raise Parenthesis();
            else:
                raise Parenthesis();
        elif t.rp:
            raise Parenthesis();

        elif t.lb:
            try:
                _valid(t);
            except Bracket:
                if not t.rb:
                    raise Bracket();
            else:
                raise Bracket();
        elif t.rb:
            raise Bracket();

        elif t.l_b:
            try:
                _valid(t);
            except Bracket1:
                if not t.r_b:
                    raise Bracket1();
            else:
                raise Bracket1();
        elif t.r_b:
            raise Bracket1();
def validBraces(string):
    t = Token(string);
    try:
        _valid(t);
    except Exception:
        return False;
    return True;

if __name__ == "__main__":
    print(validBraces("")); # True
    print(validBraces("dd()jtkr(urmf)i()d")); # True
    print(validBraces("(())(())")); # True
    print(validBraces("((()))")); # True
    print(validBraces("hi(hi)()")); # True;
    print(validBraces("((()))())")); # False
    print(validBraces(")()()")); # False
    print(validBraces("()()(")); # False
    print(validBraces("()())(")); # False
    print(validBraces("()(){d{}}(){}[[]][[]]")); # True
    print(validBraces('[(])')); # False
