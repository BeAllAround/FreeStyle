import string;

def check_final(validation_arr):
    return len(validation_arr) == 4;

def check_password(s):
    valid, not_valid = "valid", "not valid";
    _limit, _arr = len(s), [];
    _range = [string.ascii_lowercase, string.ascii_uppercase, "!@#$%^&*?", string.digits];
    if(_limit < 8 or _limit >= 20):
        return not_valid;
    for item in s:
        if(item in _range[0]):
            if {"lowercase": True} not in _arr:
                _arr.append({"lowercase": True});
        elif(item in _range[1]):
            if {"uppercase": True} not in _arr:
                _arr.append({"uppercase": True});
        elif(item in _range[2]):
            if {"special": True} not in _arr:
                _arr.append({"special": True});
        elif(item in _range[3]):
            if {"digits": True} not in _arr:
                _arr.append({"digits": True});
        else:
            return not_valid;
    if(check_final(_arr)):
        return valid;
    return not_valid;

if __name__ == '__main__':
    print(check_password("password")); # "not valid"
    print(check_password("P1@pP1@p")); # "valid"
    print(check_password("P1@pP1@pP1@pP1@pP1@pP1@p")); # "not valid"
