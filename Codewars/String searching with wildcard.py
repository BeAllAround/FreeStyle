def find(needle, haystack):
    for x in range(len(haystack)):
        b = True
        if x+len(needle) > len(haystack):
            return -1
        for j in range(0, len(needle)):
            if(needle[j] == haystack[x+j] or needle[j] == '_'):
                pass
            else:
                b = False 
                break
        if b:
            return x
    return -1

'''
#Codewars
import re

def find(needle, haystack):
    matched = re.search(re.escape(needle).replace('_', '.'), haystack)
    if matched:
        return matched.start()
    return -1
'''
