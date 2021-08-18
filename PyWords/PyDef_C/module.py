->define WHILE while
->define include import
->define String str



->define TRUE True
->define BLOCK :
->define CLOSE break
->define SHOW print

include os, sys;

WHILE TRUE BLOCK
    SHOW(String(40) == '40');
    CLOSE;

