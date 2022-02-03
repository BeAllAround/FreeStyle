def _iter(s, _split):
    for x in range(0, len(s), _split):
        yield (s[x : x+_split]);

def check_sort(arr):
    return arr == sorted(arr);

def _find(arr):
    arr = list(map(int, arr));
    item = arr[0];
    arr1 = [];
    for j in arr[1:]:
        if(item+2 == j):
            arr1.append(item+1);
        elif(j > item+1 or j+1 < item or item == j):
            return -1;
        item = j;
    if(len(arr1) == 0 or len(arr1) > 1):
        return -1;
    return arr1[0]
    
def missing(s):
    arr = []
    arr1 = []
    item = None;
    for x in range(1, 10):
        arr = list(_iter(s, x))
        if(check_sort(arr)):
            break;
    if(_find(arr) != -1):
        return _find(arr)
    else:
        _s = s
        b = False
        for x in range(1, 10):
            arr = list(_iter(s, x))
            for item in arr:
                if(item.startswith('0')):
                    try:
                        s = (s[s.index('10'):len(s)])
                    except ValueError:
                        return -1
                    b = True
                    continue;
            if(check_sort(arr)):
                break
        b1 = False;
        if not b:
            for x in range(1, len(_s)):
                item = _s[x]
                if(item.startswith('1')):
                    arr = (list(_iter(_s[0:x], 1))) + list(_iter(_s[x:len(_s)], 2))
                    b1 = True
                    break;
        if not b1:
            c = len(arr[0]) - 1
            if(c == 0):
                c = 1
            arr = (list(_iter(_s[0:_s.index(arr[0])], c))) + arr
    return _find(arr)
'''
    # Codewars
    def missing(seq):
        for digits in range(1, len(seq) // 2 + 1):
            my_seq = last = seq[:digits]
            n = int(my_seq)
            missing = None

            while len(my_seq) < len(seq):
                n += 1
                my_seq += str(n)

                if not seq.startswith(my_seq):
                    if missing == None:
                        missing = n
                        my_seq = last
                    else:
                        break
                else:
                    last = my_seq

            if my_seq == seq and missing:
                return missing

        return -1
'''


'''
# regex generation would be nice

def _iter(s, _split):
    for x in range(0, len(s), _split):
        yield (s[x : x+_split]);

state = 0;

def check_sort(arr):
    return arr == sorted(arr);

def _find(arr):
    global state;
    arr = list(map(int, arr))
    try:
        item = arr[0]
    except IndexError:
        return -1;
    arr1 = []
    for j in arr[1:]:
        if(item+2 == j):
            arr1.append(item+1);
        elif(j > item+1 or j+1 < item or item == j):
            return -1;
        item = j;
    if(len(arr1) == 0 or len(arr1) > 1):
        if(len(arr1) == 0):
            state = -2;
        return -1;
    return arr1[0]

def __find(arr):
    try:
        item = arr[0];
    except IndexError:
        return True;
    for j in arr[1:]:
        if(item < j and j > item):
            continue;
        else:
            return False;
    return True;
    
def missing(s):
    global state;
    arr = []
    arr1 = []
    arr2 = [];
    item = None;
    # print(s);
    for x in range(1, 10):
        arr = list(_iter(s, x))
        if(check_sort(arr)):
            break
    if(_find(arr) != -1):
        return _find(arr)
    else:
        _s = s
        b = False
        _c = 1;
        for x in range(1, 10):
            arr = list(_iter(s, x))
            for item in arr:
                if(item.startswith('0')):
                    try:
                        c1 = _c;
                        c2 = 2;
                        # print("C1: ", c1, _c);
                        while(s[0:s.index('1' + '0'*_c)+c2][-1] != '0'):
                            c1+=1;
                            c2+=1;
                        s_1 = (s[0:s.index('1' + '0'*c1)]);
                        s = (s[s.index('1' + '0'*c1):len(s)])
                        # c = len(arr[0]) - 1
                        __c = _c -1;
                        # arr_2 = list(_iter(_s[0:s.index('1' + ('0' * __c))], __c));
                        # if(c == 0):
                            # c = 1
                        # print(s_1, _c);
                        arr2 = (list(_iter(s_1, c1)));
                        arr = (list(_iter(s, c1)));
                        # print(arr2, arr);
                        __b=__find(arr2);
                        if(__b):
                            arr1.extend(arr2);
                        _c += 1;
                            
                    except ValueError:
                        pass;
                        # return -1
                    b = True
                    continue;
            if(check_sort(arr)):
                break
        b1 = False;
        if not b:
            for x in range(1, len(_s)):
                item = _s[x]
                if(item.startswith('1')):
                    arr = (list(_iter(_s[0:x], 1))) + list(_iter(_s[x:len(_s)], 2))
                    b1 = True
                    break;
        if not b1:
            arr = arr1 + arr;
            if(_find(arr) != -1):
                print("D", arr);
                return _find(arr);
            c = len(arr[0]) - 1
            if(c == 0):
                c = 1
            arr = (list(_iter(_s[0:_s.index(arr[0])], c))) + arr
    return _find(arr)
    '''
