function Event() {
  let arr = [];
  Event.prototype.subscribe = function(f){
    arr.push(f);
  }
  
  Event.prototype.emit = function(...args){
    for(let f of arr)
      f(...args);
  }
  
  Event.prototype.unsubscribe = function(f){
    let i;
    if( (i = arr.indexOf(f)) != -1)
      arr[i] = function(){};
  }
}
