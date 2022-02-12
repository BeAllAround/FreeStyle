def to_underscore(string):
    if(string.__class__ == int):
        return str(string);
    s = '';
    l = [];
    item = None;
    x = 0;
    while x < len(string):
        item = string[x];
        if(item.isupper()):
            s += item;
            x += 1;
            while(x < len(string) and (string[x].islower() or string[x].isdigit())):
                s += string[x];
                x += 1;
            l.append(s);
            s = '';
            continue;
        elif item.isdigit():
            s+=item;
        else:
            s += item;
        x += 1;
    return '_'.join(list(map(lambda x: x.lower(), l)));

  '''
# Codewars
import re

def to_underscore(string):
    return re.sub(r'(.)([A-Z])', r'\1_\2', str(string)).lower()   
'''
