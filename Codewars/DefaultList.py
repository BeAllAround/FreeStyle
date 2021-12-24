class DefaultList(list):
  
    def __init__(self, arr, delf):
        self.v = delf;
        super().__init__(arr);
        
    def __getitem__(self, key):
        try:
            return super().__getitem__(key); # reuse to customize your class effectively - that's to say "without rewriting every single method." This is a great use of the "super" keyword.
        except IndexError:
            return self.v;
