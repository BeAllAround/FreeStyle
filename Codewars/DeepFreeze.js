Object.deepFreeze = function (object) {
  if(object instanceof Object){
    Object.freeze(object);
    for(let item in object)
      Object.deepFreeze(object[item]);
  }
}
