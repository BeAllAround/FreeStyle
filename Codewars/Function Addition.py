b1 = [];
class FuncAdd:
    def __init__(self, val):
        global b1;
        b1.append([val.__name__, val]);
        self.val = val;
        self.node = None;
    def __call__(self, *args, **kwargs):
        global b1;
        if (self.val.__name__) not in [item[0] for item in b1]:
            raise NameError(self.val.__name__ + " should be deleted");
        b1 = list(filter(lambda x: x[0]==(self.val.__name__), b1));
        arr = [];
        for item in b1:
            arr.append(item[1](*args, **kwargs))
        self.node = (b1);
        return tuple(arr);
    @classmethod
    def delete(self, func):
        global b1;
        arr = [];
        for x in range(len(b1)):
            if(b1[x][0] != func.val.__name__):
                arr.append([b1[x][0], b1[x][1]])
        b1 = arr;
        del func;
        return;
    @classmethod
    def clear(self):
        global b1;
        b1 = [];
