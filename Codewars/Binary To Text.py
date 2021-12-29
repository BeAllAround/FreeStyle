def binary_to_string(binary):
    if(binary==''):
        return '';
    binary_int = int(binary, 2)

    ascii_code = binary_int.to_bytes(binary_int.bit_length(), "big").decode();

    return str(ascii_code.replace("\x00", ''));
