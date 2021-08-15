class Meta(int):
    def __init__(self, n):
        self.s = n;
    def __call__(self, b):
        self.s += b;
        return Meta(self.s);
    
def add(n):
    return Meta(n);

if __name__ == "__main__":
    print(add(3)); # 3
    print(add(3)(4)); # 7
    print(add(2)(8)(400)); # 410
