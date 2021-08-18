->define WHILE while
->define include import
->define String str
->define TRUE True
->define DIR dir
->define NEW break
->define function def
->define SLEEP time.sleep(1)






->define BLOCK :
->define LESS <

include os, sys, time;

function cry() BLOCK
    return "...";

i = 0;
WHILE i LESS 20 BLOCK
    print(i);
    i += 1;

WHILE TRUE BLOCK
    print(cry());
    NEW

SLEEP
