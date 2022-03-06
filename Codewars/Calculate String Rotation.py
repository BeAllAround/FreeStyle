def shifted_diff(first, second):
    c = 0
    if first == second:
        return 0
    for x in range(len(second)):
        first = first[-1] + first[0:-1]
        c += 1
        if first == second:
            return c
    return -1
  
  '''
    # Codewars
    def shifted_diff(first, second):
        return (second + second).find(first) if len(first) == len(second) else - 1;
    
    from collections import deque

    def shifted_diff(first, second):
        word = deque(second)
        unordered = deque(first)

        for i in range(len(second)):
            copy = word.copy()
            copy.rotate(-i)
            if copy == unordered:
                return i
        return -1
  '''
