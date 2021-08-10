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
  for i in xrange(inx+1, end):
    _str += str1[i];
  return _str;

def scramble(str1, str2):
  inx = None;
  for i in xrange(0, len(str1)):
     inx = search(str2, str1[i]);
     if(inx != -1):
            str2 = trim(str2, inx);
  if(len(str2) != 0):
    return False;
  return True;
