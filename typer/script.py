#usr/bin/python3

from time import sleep

from pynput.keyboard import Key, Controller


keyboard = Controller()

def slice_s(s, n):
    for x in range(0, len(s), n):
        yield s[x:x+n]

def type_out(s):
    for char in s:
        keyboard.press(char)
        keyboard.release(char)

def auto_type(text, sep = 3, interval = 0.1):
    for part in slice_s(text, sep):
        type_out(part)
        # keyboard.type(part)


if __name__ == '__main__':
    sleep(5)
    text = "Good morning"
    auto_type(text)

