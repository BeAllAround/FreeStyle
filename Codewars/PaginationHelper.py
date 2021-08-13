def ISO(arr, n):
    _arr = [];
    _n = n;
    if n > len(arr):
        return -1;
    if n == 1:
        return arr;
    start = 0;
    while n < len(arr):
        _arr.append([arr[item] for item in range(start, n)]);
        start = n;
        n += _n;
    if(start != len(arr)):
        _arr.append([arr[item] for item in range(start, len(arr))]);
    return _arr;

class PaginationHelper:
  # The constructor takes in an array of items and a integer indicating
  # how many items fit within a single page
  def __init__(self, collection, items_per_page):
      self.iso = ISO(collection, items_per_page);
      self.collection = collection;
      
  # returns the number of items within the entire collection
  def item_count(self):
      return len(self.collection);
  
  # returns the number of pages
  def page_count(self):
      return self.iso.__len__();
  # returns the number of items on the current page. page_index is zero based
  # this method should return -1 for page_index values that are out of range
  def page_item_count(self, page_index):
      if(not page_index >= len(self.iso)):
          return len(self.iso[page_index]);
      return -1;
  # determines what page an item is on. Zero based indexes.
  # this method should return -1 for item_index values that are out of range
  def page_index(self, item_index):
      if self.collection.__len__() == 0:
          return -1;
      _x, c = 0, 0;
      for item in self.iso:
          for item2 in item:
              c+=1;
      if(not item_index >= c):
          for i in range(len(self.iso)):
              for x in self.iso[i]:
                  if(_x == item_index):
                      return i;
                  _x += 1;
      return -1;

if __name__ == '__main__':
    n = PaginationHelper(['a', 'b', 'c', 'd', 'e', 'f'], 4);
    print(n.iso);
    print(n.page_count());
    print(n.item_count());

    print(n.page_item_count(0));
    print(n.page_item_count(1));
    print(n.page_item_count(2));

    print(n.page_index(5));
    print(n.page_index(2));
    print(n.page_index(20));
    print(n.page_index(-10));
