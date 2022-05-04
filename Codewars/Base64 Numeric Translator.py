def base64_to_base10(str):
    l = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/';
    i, s = 0, 0;
    for item in str[::-1]:
        s += (l.index(item) * pow(64, i));
        i+=1;
    return s;
