import math;
def find_remove(arr, copy):
    item = None;
    for i in range(len(arr)):
        item = arr[i];
        if item == copy:
            del arr[i];
            return True;
    return False;

def comp(array1, array2):
    c = 0;
    if(array2==None):
        return False;
    if(array2==[] and array1==[]):
        return True;
    if(array2==[]):
        return False;
    array1 = [abs(item) for item in array1];
    arr_copy = list(array1);
    # print(array1, array2);
    for item in array2:
        if abs(math.sqrt(item)) in array1:
            find_remove(array1, abs(math.sqrt(item)));
            c+=1;
    if(array1 == array2):
        return False;
    if(c==0):
        return False;
    return c == len(arr_copy);

a1 = [121, 144, 19, 161, 19, 144, 19, 11]
a2 = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]
print(comp(a1, a2));
print(comp([42, 42], [42, 42]));
print(comp([-121, -144, -161, -144, -11], [121, 14641, 20736, 361, 25921, 361, 20736, 361]));
