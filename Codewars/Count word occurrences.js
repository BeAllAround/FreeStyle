function search(arr, _item){
  for(let i in arr)
    if(arr[i][0] == _item)
      return i;
  return -1;
}

class word_Counter{
  constructor(str){
    this.str = str.split(/(\s|\,|\.)/ig);
    this.cache = [['', 0]];
  }
  
  count(word){
    if(word.match(/^(\.|\,|\s)+$/gi))
      return 0
    let c = 0, index;
    if((index = search(this.cache, word)) == -1){
      for(let item of this.str)
        if(item == word)
          c++;
      this.cache.push([word, c]);
      return c;
    }else
      return this.cache[index][1];
  }
};

function wordCounter(str){
  return new word_Counter(str);
}
