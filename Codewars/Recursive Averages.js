_list = [];
function loop(arr){
  if(arr instanceof Array){
    _list.push([]);
    for(let i in arr){
      loop(arr[i]);
    }
  }else
    if(!(arr instanceof Function))
      _list[_list.length-1].push(parseFloat(arr));
}

Array.prototype.average = function(){
  _list = [];
  (loop(this));
  let i = _list.length-1;
  item = _list[i];
  i--;
  for(; i>=0; i--){
          sum = item.reduce((a, b)=>a+b, 0)/item.length;
          _list[i].push(sum);
          item = _list[i];
  }
 return (item.reduce((a,b)=>a+b, 0) / item.length); // finally compute the last item and return!
};
