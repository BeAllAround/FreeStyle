def _find(arr, c):
    for i, a in enumerate(arr):
        if a[0] == c:
            return i;
    return -1;
            
def stock_list(listOfArt, listOfCat):
    a, i = [], -1;
    for cat in listOfCat:
        for art in listOfArt:
            i = _find(a, cat);
            if art.startswith(cat):
                if i == -1:
                    a.append([cat, int(art.split(' ')[1])]);
                else:
                    a[i][1] += int(art.split(' ')[1]);
            else:
                if i == -1:
                    a.append([cat, 0]);
    return ' - '.join(map(lambda x: '(' + str(x[0]) + ' : ' + str(x[1]) + ')', a));
