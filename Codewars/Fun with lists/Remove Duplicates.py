class Node(object):
    def __init__(self, data, next = None):
        self.data = data
        self.next = next;

def clone(arr):
    b = True;
    a = [None];
    n = None;
    while len(arr) != 0:
        if b:
            a[0] = (Node(arr.pop(0)))
            b = False;
            n = a[-1];
            continue;
        n.next = Node(arr.pop(0));
        n = n.next;
    return a.pop(0);

    
def remove_duplicates(head):
    a = [None];
    n = None;
    b = True;
    dup = None;
    if head != None:
        dup = head.data;
        a[0] = (Node(dup));
        n = a[-1];
        head = head.next;
    else:
        return None;
    while(head != None):
        if dup != head.data:
            n.next = Node(head.data);
            n = n.next;
        dup = head.data; 
        head = head.next;
    return a.pop(0);
