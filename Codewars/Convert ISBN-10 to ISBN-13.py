def isbn_converter(isbn):
    isbn = [*isbn];
    isbn.pop();
    isbn.pop();
    isbn = ''.join(isbn);
    isbn = [str(978)] + isbn.split('-');
    isbn_1 = ''.join(isbn);
    i = 0;
    l = [1, 3];
    arr = [];
    for item in isbn_1:
        arr.append(l[i] * int(item));
        if not i:
            i = 1;
        else:
            i = 0;
    n_1 = 10 - (sum(arr) % 10);
    if n_1 == 10:
        n_1 = 0;
    return '-'.join(isbn) + '-' + str(n_1);

'''
def isbn_converter(isbn):
    s = '978' + isbn.replace('-','')[:-1]
    m = sum( int(d)*(1+2*(i&1)) for i,d in enumerate(s)) % 10
    return f'978-{ isbn[:-1] }{ m and 10-m }'
'''
