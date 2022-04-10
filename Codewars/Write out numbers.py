_d = {
       '0': 'zero',
       '1': 'one',
       '2': 'two',
        '3':'three',
        '4':'four',
        '5':'five',
        '6': 'six',
        '7': 'seven',
        '8': 'eight',
        '9': 'nine',
        '10': 'ten',
        '11': 'eleven',
        '12': 'twelve',
        '13': 'thirteen',
        '14': 'fourteen',
        '15': 'fifteen',
        '16': 'sixteen',
        '17': 'seventeen',
        '18': 'eighteen',
        '19': 'nineteen',
        '20': 'twenty',
        '30': 'thirty',
        '40': 'forty',
        '50': 'fifty',
        '60': 'sixty',
        '70': 'seventy',
        '80': 'eighty',
        '90': 'ninety',
};

def two_digits(n, b=True):
    n1 = str(n);
    if n == 0 and b:
        return '';
    if len(n1) == 1:
        return _d[n1];
    elif len(n1) == 2:
        if n1[1] != '0' and n >= 20:
            return _d[str(int(n1[0])*10)] + '-' + _d[n1[1]];
        return _d[n1];

def t_digits(n):
    n1 = str(n);
    if len(n1) <= 2:
        return two_digits(n);
    n2 = two_digits(int(n1[0]));
    n3 = two_digits(int(n1[1:]));
    if n2 != '':
        return (n2 + ' hundred ' + n3).rstrip();
    return n3;

def f_digits(n):
    n1 = str(n);
    if len(n1) <= 3:
        return t_digits(n);
    n2 = two_digits(int(n1[0]));
    n3 = t_digits(n1[1:]);
    if n2 != '':
        return (n2 + ' thousand ' + n3).rstrip();
    return n3;

def f__digits(n):
    n1 = str(n);
    if len(n1) <= 4:
        return f_digits(n);
    n2 = two_digits(int(n1[:2]));
    n3 = f_digits(int(n1[2:]));
    if n2 != '':
        return (n2 + ' thousand ' + n3).rstrip();
    return n3;

def s_digits(n):
    n1 = str(n);
    if len(n1) <= 5:
        return f__digits(n);
    n4 = '';
    n2 = two_digits(int(n1[:1]));
    n3 = f__digits(int(n1[1:]));
    if n1[1]+n1[2] == '00':
        n4 = 'thousand ';
    if n2 != '':
        return (n2 + ' hundred ' + n4 + n3).rstrip();
    return n3;

def number2words(n):
    n1 = str(n);
    if len(n1) == 1:
        return two_digits(n, False);
    return s_digits(n);

'''
#Codewars

words = "zero one two three four five six seven eight nine" + \
" ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty" + \
" thirty forty fifty sixty seventy eighty ninety"
words = words.split(" ")

def number2words(n):
    if n < 20:
        return words[n]
    elif n < 100:
        return words[18 + n // 10] + ('' if n % 10 == 0 else '-' + words[n % 10])
    elif n < 1000:
        return number2words(n // 100) + " hundred" + (' ' + number2words(n % 100) if n % 100 > 0 else '')
    elif n < 1000000:
        return number2words(n // 1000) + " thousand" + (' ' + number2words(n % 1000) if n % 1000 > 0 else '')
'''
