from time import time
from random import randint


def queue_time(customers, n):
    queue_sub = []
    total = 0
    
    if n == 1:
        return sum(customers)
    
    elif len(customers) <= n:
        return max(customers);
    
    
    for i in range(0, n):
        queue_sub.append(customers[i])
        
    queue_sub.sort(reverse = True)
    n1 = n
    subtractor = min(queue_sub)
    
    while n < len(customers):
        for i in range(0, n1):
            queue_sub[i] -= subtractor
            
        queue_sub.sort(reverse = True)
        i = n1-1
        while i >= 0:
            if queue_sub[i] == 0:
                if n < len(customers):
                    queue_sub[i] = customers[n]
                n += 1
            else:
                break
            i -= 1

        total += subtractor
        subtractor = min(queue_sub)
        
    total += max(queue_sub)
    
    return total

def queue_time1(customers, n):
    total = 0

    if n == 1:
        return sum(customers)

    elif len(customers) <= n:
        return max(customers);


    while len(customers) != 0:
        l = customers[0:n]

        m = min(l)
        c = 0
        for item in l:
            customers[c] = customers[c] - m
            c+=1
        total+=m
        customers = list(filter(lambda x: x != 0, customers))

    return total

if __name__ == '__main__':
    d = []

    for i in range(0, 1000):
        d.append(randint(0, 40))

    start = time()

    queue_time(d, 20)

    print(time() - start)
