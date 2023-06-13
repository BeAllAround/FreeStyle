from preloaded import Any, Normal, Or, Str, ZeroOrMore

# preloaded defines the following:

# class RegExp:
#     def __init__(self, *args):
#         self.args = args
#     def __repr__(self):
#         args = ", ".join(map(repr, self.args))
#         return f"{self.__class__.__name__}({args})"
#     def __eq__(self, other):
#         return type(self) is type(other) and self.args == other.args
# class Any(RegExp): pass
# class Normal(RegExp): pass
# class Or(RegExp): pass
# class Str(RegExp): pass
# class ZeroOrMore(RegExp): pass

# Your task is to build an AST using those nodes.
# See sample tests or test output for examples of usage.

class Ch:
    def __init__(self, s, c = 0):
        self.s = s
        self.c = c
    
    def peek(self):
        try:
            return self.s[self.c]
        except IndexError:
            return ''
        
    def is_over(self):
        return self.c >= len(self.s)
    
    def adv(self):
        c = self.c
        self.c += 1
        return self.s[c]
    
    def skip_space(self):
        while not self.is_over() and self.peek() == ' ':
            self.adv()
        
cha = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!"#$%&\'+,-/:;<=>?@[\\]^_`{}~ \t\n\r\x0b\x0c*.'

def expr(ch, b = 0):
    if b:
        ch.adv()
    left = term(ch, 0)
    l = 0
    while 1:
        if ch.peek() == '|':
            right = term(ch, 1)
            
            if l: # 'a|t|y'
                raise SyntaxError('OR')
            # if type(left) == Or:
                # raise SyntaxError('OR')
            
            left = Or(left, right)
            l+=1
        else:
            return left
        
def term(ch, b = 0):
    if b:
        ch.adv()
    coll = []
    w = 0
    while 1:
        if ch.peek() != '' and ch.peek() in cha:
            while ch.peek() != '' and ch.peek() in cha:
                if ch.peek() == '.':
                    ch.adv()
                    coll.append(Any())
                elif ch.peek() == '*':
                    ch.adv()
                    if len(coll) == 0:
                        raise SyntaxError('ZeroOrMore')
                    if w and type(coll[-1]) == ZeroOrMore:
                        raise SyntaxError("ZeroOrMore")
                    coll[-1] = ZeroOrMore(coll[-1])
                    w += 1 # for the case: '(c*)*'
                else:
                    coll.append(Normal(ch.adv()))
        elif ch.peek() == '(':
            left = expr(ch, 1)
            if ch.peek() != ')':
                raise SyntaxError("closing: ')'")
            ch.adv()
            if type(left) == Str and len(left.args[0]) == 0: # invalid case: '()'
                raise SyntaxError("invalid case: '()'")
                
            coll.append(left)
        else:
            if len(coll) == 1:
                return coll[0]
            else:
                return Str(coll)
                
            
    
        

def parse_regexp(indata):
    if indata == '':
        return None
    
    # print('in: ', indata)
    ch = Ch(indata)
    try:
        e = expr(ch)
        if not ch.is_over():
            # print('over', [ch.peek()] )
            # print(e)
            return None
    except SyntaxError as err:
        # print('err: ', err)
        return None
    
    return e
