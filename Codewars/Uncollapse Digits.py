def uncollapse(digits):
    d = "zero nine one one eight two seven three six four two five".split(' ');
    i = 0;
    s = '';
    arr = [];
    while i < len(digits):
        s += digits[i];
        if s in d:
            arr.append(s);
            s = '';
        i += 1;
    return ' '.join(arr);

'''
# Codewars
import re

def uncollapse(digits):
    return ' '.join(re.findall('zero|one|two|three|four|five|six|seven|eight|nine', digits))
'''
