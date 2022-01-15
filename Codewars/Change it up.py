def changer(s):
    consonants, vowels = "bcdfghjklmnpqrstvwxyz", "aeiou";
    letters = [item for item in 'abcdefghijklmnopqrstuvwxyz'];
    _s, s_ = '', '';
    for item in s:
        if item.isalpha():
            if item.lower() == 'z':
                _s += 'a';
                continue;
            _s += letters[letters.index(item.lower())+1]
        else:
            _s += item;
    for item in _s:
        if item in vowels:
            s_ += item.upper();
        else:
            s_ += item;
    return s_;

'''
  #Codewars
  def changer(s):
    return s.lower().translate(str.maketrans('abcdefghijklmnopqrstuvwxyz', 'bcdEfghIjklmnOpqrstUvwxyzA'))
  #################
  FOLLOWING_LETTER_VOWELS_UP_CONSONANTS_LO = str.maketrans('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ',
                                                         'bcdEfghIjklmnOpqrstUvwxyzAbcdEfghIjklmnOpqrstUvwxyzA')


  def changer(string_):
      return string_.translate(FOLLOWING_LETTER_VOWELS_UP_CONSONANTS_LO)
  ##################
  from string import ascii_lowercase as al

  xs = ''.join(c.upper() if c in 'aeiou' else c for c in al) * 2
  tbl = str.maketrans(al + al.upper(), xs[1:] + xs[0])
  def changer(s):
      return s.translate(tbl)
'''
