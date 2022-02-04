def solution(n):
    _str = ''
    _dic = {'1': 'I', '4': 'IV', '5': 'V', '9': 'IX', '10': 'X', '40': 'XL', '50': 'L'}
    _dic.update({ '90': 'XC', '100': 'C', '400': 'CD', '500': 'D', '900': 'CM', '1000':'M'})
    _dic1 = {}
    for item in list(reversed([item for item in _dic])):
        _dic1[item] = _dic[item]
    while n > 0:
        for item in _dic1:
            if(n - int(item) >= 0):
                _str += (_dic1[item])
                n -= int(item)
                break
    return _str
