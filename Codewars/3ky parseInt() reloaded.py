def pop(arr):
    try:
        return arr.pop(0);
    except IndexError:
        return None;

def diff(num1, num2):
    num1, num2, arr = [*str(num1)], [*str(num2)], [];
    if len(num1)+1 == len(num2):
        num1.insert(len(num2) - len(num1), '0')
    return int(''.join(num1));

def clear_out(nums, _n):
    n_c = list(map(str, nums));
    nums = list(map(str, nums));
    n = [];
    l1 = pop(nums);
    l = pop(nums);
    while len(nums) != 0 and l != None:
        l1 = [*l1];
        for _ in range(len(l)):
            if len(l1) != 0 and l1[-1] == '0':
                l1.pop();
            else:
                break;
        n.append(''.join(l1) + l);
        l1 = n[-1];
        l = pop(nums);
    if l != None:
        l1 = [*l1];
        for _ in range(len(l)):
            if len(l1) != 0 and l1[-1] == '0':
                l1.pop();
            else:
                break;
        n.append(''.join(l1) + l);
        l1 = n[-1];
        l = pop(nums);
    if len(n) != 0:
        return diff(n[-1], _n);
    return n_c[-1];
        
def parse_int(string):
    arr_main = (string.split(' '));
    _dict = {'one': 1, 'two': 2, 'three': 3, 'four': 4, 'five': 5, 'six': 6, 'seven': 7, 'eight': 8, 'nine': 9, 'ten': 10
            ,
            'eleven': 11, 'twelve': 12, 'thirteen': 13, 'fourteen': 14, 'fifteen': 15, 'sixteen': 16, 'seventeen': 17, 'eighteen': 18, 'nineteen': 19
            ,
            'twenty': 20, 'thirty': 30, 'forty': 40, 'fifty': 50, 'sixty': 60, 'seventy': 70, 'eighty': 80, 'ninety': 90};
    c = 0;
    b1, b2 = True, True;
    arr = [];
    d = 1;
    for x, item in enumerate(arr_main):
        try:
            arr.append(_dict[item]);
        except KeyError:
            if item == 'hundred':
                arr[-1] *= 100;
                if b1:
                    d *= 100;
            elif item == 'thousand':
                arr[-1] *= 1000;
                if b2:
                    d *= 1000;
                b1 = False;
            elif item == 'million':
                arr[-1] *= 1000000;
                b2 = False;
            elif '-' in item:
                arr.append(sum([_dict[j] for j in item.split('-')]));
    if len(arr) == 0:
        return 0;
    return int(clear_out(arr, d));

'''
#Codewars
ONES = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine',
        'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 
        'eighteen', 'nineteen']
TENS = ['twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']

def parse_int(string):
    print(string)
    numbers = []
    for token in string.replace('-', ' ').split(' '):
        if token in ONES:
            numbers.append(ONES.index(token))
        elif token in TENS:
            numbers.append((TENS.index(token) + 2) * 10)
        elif token == 'hundred':
            numbers[-1] *= 100
        elif token == 'thousand':
            numbers = [x * 1000 for x in numbers]
        elif token == 'million':
            numbers = [x * 1000000 for x in numbers]
    return sum(numbers)

import re

SIMPLIFIER = re.compile(r'(\s|-|\band)+')
SPLITTER   = [re.compile(rf'\s*{what}\s*') for what in ('million', 'thousand', 'hundred', r'ty\b')]
COEFS      = [10**x for x in (6,3,2,1)]

vals       = "zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen".split()
VALUES     = {name:v for name,v in zip(vals, range(len(vals)))}
VALUES.update({'twen': 2, 'thir': 3, 'for': 4, 'fif': 5, 'eigh':8})


def parse_int(s): 
    return parse(0, SIMPLIFIER.sub(' ',s.lower()))

def parse(i, s):
    if i == len(SPLITTER): return VALUES.get(s,0)
        
    lst, coef, i = SPLITTER[i].split(s), COEFS[i], i+1
    
    return parse(i,lst[0]) if len(lst)==1 else coef * parse(i,lst[0]) + parse(i,lst[1])
'''
