def _eval_parentheses(s):
    n = 0
    l = 0
    r = 0
    
    while s.l < len(s.s):
        if s.a and s.at == '(' and s.s[s.l+1] == ')':
            n+=1
            s.adv
            # s.adv
        elif s.at == '(':
            s.adv
            n1 = _eval_parentheses(s,)
            n += 2*n1
        else:
            return n
        s.adv
        
    return n

class S:
    def __init__(self, s):
        self.s = s
        self.l = 0
        
    @property
    def at(self):
        return self.s[self.l]
    
    @property
    def w(self):
        return self.l < len(self.s)
    
    @property
    def a(self):
        return self.l+1 < len(self.s)
    
    @property
    def adv(self):
        self.l += 1
        
        
def eval_parentheses(s):
    return _eval_parentheses(S(s))
