from collections import Counter;

def check(num):
    c = 0;
    if isinstance(num, str) or num < 0:
        return 'Not valid';
    if len(str(num))==1:
        return False;
    return [*str(num)] == list(reversed([*str(num)]));

def palindrome(num):
    if check(num) == 'Not valid':
        return 'Not valid';
    n = int(num);
    num1 = int(num);
    if len(str(num)) == 1:
        return 11;
    while not check(num):
        num+=1;
    while not check(num1):
        num1-=1;
    l = [num, num1];
    l1 = [abs(n-num), abs(n-num1)];
    return l[l1.index(min(l1))];
