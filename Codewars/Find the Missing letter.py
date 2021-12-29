import string;
def find_missing_letter(chars):
    _l = [item for item in string.ascii_letters];
    for item in chars:
        if _l[_l.index(item)+1] not in chars:
            return _l[_l.index(item)+1];
