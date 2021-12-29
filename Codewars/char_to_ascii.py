def findO(obj, item):
    for _item in obj:
        if _item == item:
            return True;
    return False;

def char_to_ascii(string):
    if(len(string)==0):
        return None;
    obj = {};
    for item in string:
        if not findO(obj, item) and item.isalpha():
            obj[item] = ord(item);
    return obj;
