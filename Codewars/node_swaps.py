def swap_pairs(head):
    if head == None:
        return None
    
    prev = None
    n = 0
    heado = head
    a = []
    while head != None:
        a.append(head)
        head = head.next
        
    for x in range(0, len(a)):
        if x%2 == 0 and x+1 < len(a):
            a[x+1].next = a[x]
            if x+2 < len(a):
                a[x].next = a[x+2]

            else:
                a[x].next = None
            if prev != None:
                prev.next = a[x+1]
                a[x+1].next = a[x]
                if x+2 < len(a):
                    a[x].next = a[x+2]
                else:
                    a[x].next = None
            prev = a[x]
            if x == 0:
                heado = a[x+1]
        
    return heado
