def find(needle, haystack):
    s = ''
    for x in range(len(haystack)):
        for j in range(0, len(needle)):
            if x+j < len(haystack):
                if(needle[j] == haystack[x+j] or needle[j] == '_'):
                    s += needle[j]
            else:
                return -1
        if s == needle:
            return x
        s = ''
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
