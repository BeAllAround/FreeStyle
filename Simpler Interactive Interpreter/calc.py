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

    return parse_int(token, False)

def parse_int(token: Parser, get: bool):
    if get:
        token.next_token()

    skip_space(token)

    if token.current.isdigit():
        value = ''
        while not token.is_over() and token.current.isdigit():
            value += token.current
            token.next_token()
        skip_space(token)
        return int(value, 10) # base 10

    else:
        raise SyntaxError("Unexpected token " + token.current)

def calc(expression):
    p = Parser(expression)
    evaluated = expr(p, False)
    if not p.is_over():
        raise SyntaxError("Unexpected token " + p.current)
    return evaluated

def main():
    print(calc('-1 + 2'))
    print(calc('(((10)))'))

if __name__ == '__main__':
    main()
