def valid_ISBN10(isbn): 
    arr = [];
    for x, i in enumerate(isbn):
        try:
            arr.append(int(i) * (x+1));
        except ValueError:
            if x == len(isbn)-1 and i == 'X': # islast
                arr.append({'X': 10}['X'] * 10)
    if len(arr) != 10:
        return False;
    return sum(arr) % 11 == 0;
