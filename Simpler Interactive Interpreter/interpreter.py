#!/usr/bin/python3
from parser import Parser

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
        # value_ptr = [value]
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
            v = expr(token, True)
            _vars[tem] = v
            return v
        else:
            token.set_token(p)
            if tem not in _vars.keys():
                raise NameError(tem + " not defined")
            return _vars[tem]

    else:
        raise SyntaxError("Unexpected token " + token.current)

def parse_tem(token: Parser, get: bool):
    if get:
        token.next_token()
    value = ''
    if (not token.current.isalpha()) and (token.current != '_'):
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

    print(interpreter.vars)
    print(inputs)

if __name__ == '__main__':
    main()
