hashmap = []

def isIndex(arr, i):
    if i < len(arr):
        return True
    return False 
    
def fibonacci(n):
    if isIndex(hashmap, n):
        return hashmap[n]
    
    
    i = 0
    
    prev = 0
    next = 1
    s = 0
    
    if len(hashmap) >= 2:
        prev = hashmap[-2]
        next = hashmap[-1]
        i = len(hashmap) - 2
        
    while i < n:
        if not isIndex(hashmap, i):
            hashmap.append(prev)
            # hashmap[i] = prev
        temp = next
        next = prev+next
        prev = temp
        i += 1
    return prev
