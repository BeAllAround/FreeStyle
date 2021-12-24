def myFunc(e):
    return len(e)

def valid_word(seq, word):
    if(len(seq)==0):
        return False;
    seq = sorted(seq, reverse=True);
    seq.sort(key=myFunc, reverse=True);
    word_c = str(word); # copy
    for item in seq:
        word_c = word_c.replace(item, '');
    return word_c=='';

''' 
# Codewars recommended solution:
import re
def valid_word(seq, word): 
    regex = '^(' + '|'.join(seq) + ')+$'
    if re.match(regex, word):
        return True
    return False
 '''
