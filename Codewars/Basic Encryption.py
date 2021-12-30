def wrap(n):
    c = n;
    while(c > 255):
        c -= 256;
    return c;

def encrypt(text, rule):
    encrypted_text = ''
    for item in text:
        if(ord(item)+rule <= 255):
            encrypted_text += chr(ord(item)+rule)
        elif(ord(item)+rule > 255):
            encrypted_text += chr(wrap(ord(item)+rule));
    return encrypted_text
