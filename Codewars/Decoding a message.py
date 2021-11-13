import string;

def generate():
    list_1 = string.ascii_lowercase;
    dict_1 = [];
    c = len(list_1)-1;
    c1 = 0;
    while(c > 0):
        dict_1.append([list_1[c1], list_1[c]]);
        dict_1.append([list_1[c], list_1[c1]]);
        c -= 1;
        c1 += 1;
    return dict_1;

def decode(message):
    v = generate();
    str_1 = '';
    for item in message:
        if item == ' ':
            str_1 += ' ';
            continue;
        for inner in v:
            if inner[1] == item:
                str_1 += (inner[0]);
                break;
    return str_1;
