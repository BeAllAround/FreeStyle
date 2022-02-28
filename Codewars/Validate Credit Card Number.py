def validate(n):
    arr_n = list(map(int, [*str(n)]))
    b = len(arr_n) % 2 == 0
    _start = 0
    if b:
        arr_n[0] = arr_n[0] * 2
        _start = 1
    for x in range(_start, len(arr_n)):
        if x%2 == 0 and x != 0:
            arr_n[x] = arr_n[x] * 2
    for x in range(len(arr_n)):
        if arr_n[x] > 9:
            arr_n[x] = sum(list(map(int, [*str(arr_n[x])])))
    if sum(arr_n) % 10 == 0:
        return True
    return False
  
'''
  # Codewars
  def validate(n):
    digits = [int(x) for x in str(n)]
    for x in xrange(len(digits)-2, -1, -2):
        digits[x] = sum(map(int, str(digits[x] * 2)))
    return sum(digits) % 10 == 0
'''
