def hex_string_to_RGB(hex_string): 
    arr = [];
    for x in range(1, len(hex_string), 2):
        arr.append(int(hex_string[x:x+2], 16));
    return {'r': arr[0], 'g': arr[1], 'b': arr[2]};
