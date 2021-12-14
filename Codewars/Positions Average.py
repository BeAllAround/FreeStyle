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
            for x1 in range(first, len(item)):
                for j1 in range(last, len(item2)):
                    if(item[x1] == item2[j1] and x1 == j1):
                        first = x1+1;
                        last = j1+1;
                        c+=1;
                        break;
            arr.append(c);
            c = 0;

    ''' ### main algorithm!!!
    item = s[3];
    item2 = s[5];
    print('--------------------------------');
    item = list(item);
    item2 = list(item2);
    last = 0;
    print(item, item2);
    for x in range(len(item)):
        for j in range(last, len(item2)):
            if(item[x] == item2[j] and x == j):
                # del item[x];
                last = j+1;
                # del item2[j];
                c+=1;
                break;
    ''';
    _final = (sum(arr) / (len(arr) * len(s[0]))) * 100;  # The calc!
    return _final; # float(format(_final, '.10f'));
