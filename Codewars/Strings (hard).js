function shortCut(array, str){
  if(array instanceof Array){
    str += '[';
    for(let i in array){
      str = shortCut(array[i], str);
      if(i != array.length-1)
        str+=',';
    }
    str += ']';
  }else{
    if(array.length !== undefined)
      str+= "'"+ array.toString() + "'";
    else
      str += array.toString();
  }
  return str;
}

Array.prototype.toString = function(){
  return shortCut(this, '');
}
