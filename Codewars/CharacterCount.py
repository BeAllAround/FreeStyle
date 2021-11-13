def validate_word(word):
    data = [[word[0].lower(), 1]];
    b = False;
    for item in word[1:]:
        for s in data:
            if s[0] == item.lower():
                s[1] += 1;
                b = True;
        if not b:
            data.append([item.lower(), 1]);
        b = False;
    _max = data[0][1];
    for item in data:
        if item[1] != _max:
            return False;
    return True;
