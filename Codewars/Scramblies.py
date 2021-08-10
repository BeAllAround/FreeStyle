#!/usr/bin/env python3

# stuck on performance
xrange = range;
def search(str1, c):
  for i in xrange(0, len(str1)):
    if(str1[i] == c):
      return i;
  return -1;

def trim(str1, inx):
  end = len(str1);
  _str = "";
  if(inx >= len(str1)):
    return str1;
  for i in xrange(0, inx):
    _str += str1[i];
  for i in xrange(inx + 1, end):
    _str += str1[i];
  return _str;

def scramble(str1, str2):
  inx = None;
  for i in xrange(0, len(str2)):
     inx = search(str1, str2[i]); 
     if(inx != -1):
       str1 = trim(str1, inx);
     else:
       return False;
  return True;

if __name__ == "__main__":
	print(scramble("rkqodlw", "world")); # True
	print(scramble('aabbcamaomsccdd','commas')); # True
	print(scramble('aabbcamaomcdd','commas')); # False
