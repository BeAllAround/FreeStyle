class SecureList(list):
    def __init__(self, arr):
        super().__init__(arr);
        self._arr = list(arr);
    def __getitem__(self, inx):
        item = self._arr[inx]
        del self._arr[inx]
        super().__init__(self._arr);
        return item;
    def __repr__(self):
        arr = list(self._arr)
        self._arr.clear();
        super().__init__(self._arr)
        return arr.__repr__();
