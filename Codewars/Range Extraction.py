def solution(args):
    s = '';
    arr = [];
    c = 0;
    for x in range(len(args)-1):
        if(args[x]+1 == args[x+1]):
            arr.append(args[x])
            c += 1;
        elif(args[x]+1 != args[x+1]):
            arr.append(args[x])
            if(len(arr)>=3):
                s += str(arr[0]) + '-' + str(arr[len(arr)-1]) + ',';
            else:
                if(len(arr)!=1):
                    s += ','.join(list(map(str, arr))) + ',';
                else:
                    s += str(arr[0]) + ',';
            c = 0;
            arr = [];
    b = True;
    if(len(arr) > 0):
        if(arr[len(arr)-1]+1 == args[len(args)-1]):
            b = False;
            arr.append(args[len(args)-1]);
    if(b):
        arr.append(args[len(args)-1]);
    if(len(arr)>=3):
        s += str(arr[0]) + '-' + str(arr[len(arr)-1]);
    else:
        if(len(arr)!=1):
            s += ','.join(list(map(str, arr)));
        else:
            s += str(arr[0]);
    return (s);
  
  '''
    #CodeWars
def solution(args):
    out = []
    beg = end = args[0]
    
    for n in args[1:] + [""]:        
        if n != end + 1:
            if end == beg:
                out.append( str(beg) )
            elif end == beg + 1:
                out.extend( [str(beg), str(end)] )
            else:
                out.append( str(beg) + "-" + str(end) )
            beg = n
        end = n
    
    return ",".join(out)

def solution(arr):
    ranges = []
    a = b = arr[0]
    for n in arr[1:] + [None]:
        if n != b+1:
            ranges.append(str(a) if a == b else "{}{}{}".format(a, "," if a+1 == b else "-", b))
            a = n
        b = n
    return ",".join(ranges)

def solution(args):
    result = ""
    i = 0
    while i<len(args):
        val = args[i]
        while i+1<len(args) and args[i]+1==args[i+1]:
            i+=1
        if val == args[i]:
            result += ",%s"%val
        elif val+1 == args[i]:
            result += ",%s,%s"%(val, args[i])
        else:
            result += ",%s-%s"%(val, args[i])
        i+=1
    return result.lstrip(",")
  '''
