def compress(sentence):
    if(sentence == ''):
        return '';
    arr = []
    print(sentence);
    sentence = ((sentence.lower().split(' ')));
    s = [];
    for item in sentence:
        if item not in s:
            s.append(item);
    for item in sentence:
        arr.append(str(s.index(item)));
    return ''.join(arr);
