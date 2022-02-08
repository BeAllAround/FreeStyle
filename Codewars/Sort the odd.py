def sort_array(source_array):
    arr_even = []
    _l = list(sorted(list(filter(lambda x: x%2 == 1, source_array))))
    for x in range(len(source_array)):
        item = source_array[x]
        if item % 2 == 0:
            arr_even.append([x, item])
    for item in arr_even:
        _l.insert(*item) # (item[0], item[1])
    return _l
