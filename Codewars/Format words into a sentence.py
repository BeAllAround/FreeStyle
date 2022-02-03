def format_words(words):
    if(words == None):
        return '';
    words = list(filter(lambda x: x!='', words));
    if(len(words) == 1):
        return words[0];
    elif(words == []): # len(words) == 0;
        return '';
    words.insert(len(words)-1, 'and');
    return ', '.join(words[0:words.index('and')]) + ' and ' + words[len(words)-1];
