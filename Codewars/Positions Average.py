def pos_average(s):
    s = s.split(', ');
    n = 6 * len(s);
    c = 0;
    arr = [];
    for x in range(0, len(s)):
        item = s[x];
        for j in range(x+1, len(s)):
            item2 = (s[j]);
            item = list(item);
            item2 = list(item2);
            first, last = 0, 0;
            for x1 in range(len(item)):
                if(item[x1] == item2[x1]):
                    c += 1;
            arr.append(c);
            c = 0;

    ''' ### main algorithm!!!
    item = s[3];
    item2 = s[5];
    print('--------------------------------');
    item = list(item);
    item2 = list(item2);
    first, last = 0, 0;
    print(item, item2);
    for x in range(first, len(item)):
        for j in range(last, len(item2)):
            if(item[x] == item2[j] and x == j):
                # del item[x];
                first = x+1;
                last = j+1;
                # del item2[j];
                c+=1;
                break;
    ''';
    _final = (sum(arr) / (len(arr) * len(s[0]))) * 100;  # The calc!
    return _final; # float(format(_final, '.10f'));
