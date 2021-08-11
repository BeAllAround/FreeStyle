xrange = range;
def space_me(arr, inx):
    for i in xrange(inx, 2):
        if(arr[i] != ''):
            return False;
    return True;

def __includesObject(obj, name, toFind):
    if name == toFind:
        return True;
    if isinstance(obj, dict):
        for i in obj:
            if __includesObject(obj[i], i, toFind):
                return True;
    return False;

class _____D_U_M__Y: # create a dummy that you can begin your recursion with so that the Python built-in types can't interfere - __eq__ NotImplemented;
    None;
    
def includesObject(obj, toFind):
    return __includesObject(obj, _____D_U_M__Y(), toFind);

def clear(arr):
    _new = [];
    c = False;
    for item in arr:
            if item == '':
                if not c:
                    continue;
                else:
                    _new.append('');
            else:
                _new.append(item);
                c = True;
    i = len(_new)-1;
    while(i >= 0):
        if(_new[i] == ''):
            _new[i] = None;
        else:
            break;
        i -= 1;
    _new = [a for a in _new if a != None]; # filter
    return _new;

def decodeMorse(morse_code):
    out = '';
    morse_code = morse_code.split(' ');
    morse_code = clear(morse_code);
    MORSE_DATA = {'!': '-.-.--', '.': '.-.-.-', 'SOS': '...---...', 'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..', '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....', '7': '--...', '8': '---..', '9': '----.'}
    MORSE_SEARCH = {};
    for item in MORSE_DATA: # flip
        MORSE_SEARCH[MORSE_DATA[item]] = item;
    if(len(morse_code) == 1):
        if(includesObject(MORSE_SEARCH, morse_code[0])):
            return MORSE_SEARCH[morse_code[0]];
        if(morse_code[0] == '...---...'):
            return "SOS";
    i = 0;
    while(i < len(morse_code)):
        if(includesObject(MORSE_SEARCH, morse_code[i])):
            out += MORSE_SEARCH[morse_code[i]];
        if(morse_code[i] == ''):
            if(space_me(morse_code, i)):
                out += ' ';
                i += 1;
        i += 1;
    return out;
if __name__ == "__main__":
    print({"OUTPUT: ": decodeMorse('.... . -.--   .--- ..- -.. .')});
    # 'HEY JUDE'
