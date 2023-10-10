def splito(arr, x):
    if isinstance(arr, list) or isinstance(arr, tuple):
        for i in range(x, len(arr)):
            yield arr[i]
    else:
        for x, elem in enumerate(arr, x):
            yield elem

def flatten(*arr):
    z = []
    s = [arr]

    while len(s) != 0:

        a = s.pop()

        for x, elem in enumerate(a):
            if isinstance(elem, list):
                s.append(splito(a, x+1))
                s.append(elem)
                break
            else:
                z.append(elem)

    return z
