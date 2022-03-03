def if_k(_d, _k):
    for item in _d.keys():
        if item == _k:
            return True
    return False

def delete_nth(order,max_e):
    lst = []
    _d = {}
    for item in order:
        if if_k(_d, item):
            _d[item] += 1
        else:
            _d[item] = 1
        if _d[item] <= max_e:
            lst.append(item)
    return lst
  
'''
    # Codewars
    def delete_nth(order,max_e):
        ans = []
        for o in order:
            if ans.count(o) < max_e: ans.append(o)
        return ans
'''
