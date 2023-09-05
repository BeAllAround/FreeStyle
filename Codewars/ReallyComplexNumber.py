
class Imgry:
    def __init__(self, v):
        self.v = v;
        
    def __repr__(self):
        return str("imgry: " + self.v)

class Compx:
    def __init__(self, v):
        self.v = v
    def __repr__(self):
        return str("compx: " + self.v)

def make_num(t): # token
    num = None
    if 'i' in t:
        num = Imgry(t)
    else:
        num = Compx(t)
        
    return num
    
    
def tok(s):
    i = 0;
    t = ''
    arr = []
    
    while i < len(s[0]):
        if(s[0][i].isdigit()):
            t += s[0][i]
            
        if((s[0][i] == '+' or s[0][i] == '-') and i != 0):
            arr.append(make_num(t))
            t = s[0][i]
            
        if((s[0][i] == '+' or s[0][i] == '-') and i == 0):
            t = s[0][i]
            
        if(s[0][i] == 'i'):
            t += s[0][i]
            if i-1 >=0 and s[0][i-1].isdigit():
                t+='*1'
            else:
                t+='1'
            arr.append(make_num(t))
            t = ''
        
        s[1]+=1
        i+=1
        
    if(t != ''):
        arr.append(make_num(t))
        
    return arr
    
    
def complex_sum(arr):
    r = []
    im = []
    
    if(len(arr) == 0):
        return '0'
    
    for line in arr:
        s = [line, 0]
        t = tok(s)
        for num in t:
            if type(num) == Imgry:
                im.append(num.v.replace('i', ''))
            elif type(num) == Compx:
                r.append(num.v)
                
    a = sum([eval(s) for s in r])
    b = sum([eval(s) for s in im])
    
    if(a == 0 and b == 0):
        return '0'
    
    out = ''
    if b == 1:
        b = 'i'
        if a != 0:
            b = '+i'
    else:
        if(b < 0):
            if b != -1:
                b = str(b) + 'i'
            else:
                b = '-i'
        else:
            if b != 0 and a != 0:
                b = '+' + str(b) + 'i'
            elif b != 0 and a == 0:
                b = str(b) + 'i'
            else:
                b = ''
            
    if b == 0:
        b = ''
            
    if a != 0:
        out = str(a) + b
    else:
        return b
    
    return out
