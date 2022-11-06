#!/usr/bin/python3
class EndLine(Exception):
    pass

class Token:

    def __init__(self, source, c = 0):
        self.c = c
        self.source = source

    @property
    def current(self):
        if not self.c < len(self.source):
            raise EndLine("EndLine Error!")
        return self.source[self.c]

    def next_token(self):
        if self.c > len(self.source):
            raise EndLine("EndLine Error!")
        self.c += 1

    def __eq__(self, toMatch):
        if self.is_over():
            return False # return False when there is nothing to match
        if type(toMatch) != str:
            raise Exception("Can't match non-str")
        c = self.c
        for x in range(0, len(toMatch)):
            if x:
                self.next_token()
            if self.current != toMatch[x]:
                self.c = c
                return False
        return True

    def is_over(self):
        return not self.c < len(self.source)

    def set_token(self, token):
        self.source = token.source
        self.c = token.c


class Parser(Token): 
    def __init__(self, source, c = 0):
        super().__init__(source, c)
        self.vars = {}
        
    def set_vars(self, _vars):
        self.vars = _vars

def skip_space(token: Parser):
    while not token.is_over() and (token == ' ' or token == '\n'):
        token.next_token()

def expr(token: Parser, get: bool):
    left = term(token, get)

    while True:
        if token == '+':
            left += term(token, True)
        elif token == '-':
            left -= term(token, True)
        else:
            return left

def term(token: Parser, get: bool):
    left = prim(token, get)

    while True:
        if token == '*':
            left *= prim(token, True)
        elif token == '/':
            left /= prim(token, True)
        elif token == '%':
            left %= prim(token, True)
        else:
            return left

def prim(token: Parser, get: bool):
    if get:
        token.next_token()
    skip_space(token)
    if token == '(':
        value = expr(token, True)
        value_ptr = [value]
        if token != ')':
            raise SyntaxError("Missing ')'")
        token.next_token() # eat ')'
        skip_space(token)
        return value
    elif token == '-':
        t = Parser(token.source, token.c)
        token.next_token()
        if not token.is_over() and token.current == ' ':
            raise SyntaxError("white space not allowed!")
        else:
            token.set_token(t)
        return -prim(token, True)

    return parse_val(token, False)

def check_dups(arr):
    a = []
    for item in arr:
        if item not in a:
            a.append(item)
        else:
            raise Exception("Duplicate ARGS!")
            
def parse_val(token: Parser, get: bool):
    if get:
        token.next_token()

    skip_space(token)

    if not token.is_over() and token.current.isdigit():
        value = ''
        while not token.is_over() and token.current.isdigit():
            value += token.current
            token.next_token()
        skip_space(token)
        return int(value, 10) # base 10
    
    elif not token.is_over() and (token.current.isalpha() or token.current == '_'):
        parser = token
        _vars = parser.vars
        tem = parse_tem(token, False)
        skip_space(token)
        p = Parser(token.source, token.c)
        if token == '=':
            if tem in _vars.keys(): # can't re-assign functions
                if callable(_vars[tem]):
                    raise SyntaxError("Can't do that!")
                    
            v = expr(token, True)
            _vars[tem] = v
            return v
        
        elif tem == 'fn':
            fName = parse_tem(token, False)
            skip_space(token)
            if fName in _vars.keys():
                if not callable(_vars[fName]):
                    raise TypeError("can't overwrite variable with func")
            # print('fName: ', fName)
            args = []
                
            while True:
                if token == '=>':
                    # print('=>!!!')
                    token.next_token() # eat last token, which is '>'
                    break

                v = parse_tem(token, False)
                args.append(v)
                # print('args: ', args)
                skip_space(token)

            fnc_body = ''
            while not token.is_over():
                fnc_body += token.current
                token.next_token()
            
            def _lambda(*_args):
                vars_c = {}
                # vars_c.update(_vars) # requires unique scope
                if len(_args) != len(args):
                    raise TypeError("Too many args")
                for arg_x in range(0, len(_args)):
                    vars_c[args[arg_x]] = _args[arg_x]
                p = Parser(fnc_body)
                p.set_vars(vars_c)
                return expr(p, False)
                # print('vars_c: ', vars_c)
            _vars[fName] = _lambda
            test_args = []

            # print(_lambda(1, 2, 11))
            check_dups(args)
            
            for v in args:
                test_args.append(1)
            _lambda(*test_args)
            
            # print('=> args, body: ', args, fnc_body)
            return ''
        else:
            token.set_token(p)
            if tem not in _vars.keys():
                raise NameError(tem + " not defined")
            
            if callable(_vars[tem]):
                # print('callable!')
                if token.is_over(): # > one
                    return _vars[tem]()
                args = []
                
                while True:
                    
                    v = expr(token, False)
                    args.append(v)
                    # print('args: ', args)
                    try:
                        return _vars[tem](*args)
                    except TypeError:
                        continue
                        
                        # raise SyntaxError('')
                
            return _vars[tem]

    else:
        raise SyntaxError("Unexpected token " + token.current)

def parse_tem(token: Parser, get: bool, skip_s: bool = True):
    if get:
        token.next_token()
    if skip_s:
        skip_space(token)
    value = ''
    if (not token.current.isalpha()) and (token.current != '_'):
        return 
        raise SyntaxError("Expected a template to start with an alpha or _")
    value += token.current
    token.next_token()
    while not token.is_over() and (token.current.isalpha() or token.current.isdigit()):
        value += token.current
        token.next_token()
    return value

class Interpreter:
    def __init__(self):
        self.vars = {}
        self.functions = {}

    def input(self, expression):
        # print('expression: ', expression)
        parser = Parser(expression)
        parser.set_vars(self.vars)
        skip_space(parser)
        if parser.is_over():
            return ''
        evaluated = expr(parser, False)
        if not parser.is_over():
            raise SyntaxError("Unexpected token " + parser.current)
        return evaluated

def main():
    interpreter = Interpreter()
    inputs = []
    inputs.append(interpreter.input("_x = 1"))
    inputs.append(interpreter.input("_x"))

    inputs.append(interpreter.input("_01 = _02 = _03 = 2")) # nested def

    inputs.append(interpreter.input("(_04 = (_05 = (_06 = 3)))"))
    
    inputs.append(interpreter.input("fn x1 x y => x + y"))
    inputs.append(interpreter.input("fn echo x y => x + y"))
    inputs.append(interpreter.input("x1 echo 4 1 echo 3 1"))

    inputs.append(interpreter.input("fn inc x y j => x+y+j"))

    inputs.append(interpreter.input("_x + 3"))
    
    inputs.append(interpreter.input("fn one => 1"))

    inputs.append(interpreter.input("one"))
    
    # inputs.append(interpreter.input("fn add x y => x + z")) # throws!

    print(interpreter.vars)
    print(inputs)

if __name__ == '__main__':
    main()
