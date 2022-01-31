def check_zeros(n1, n2):
    n1 = [*str(n1)];
    n2 = [*str(n2)];
    n1.pop(0);
    n2.pop(0);
    for item in n1:
        if item != '0':
            return False;
    for item in n2:
        if item != '0':
            return False;
    return True;

def last_digit(n1, n2):
    if(n1 >= 10 and n2 >= 10 and check_zeros(n1, n2)):
        return 0;
    elif(n1 == 0 or n2 == 0):
        return 1;
    return pow(n1%1000, n2%1000) % 10;
  
'''
    # Codewars
      pow(n1, n2, 10); # check the docs!!!
'''
