Object.defineProperty( String.prototype, "eqAll", { value: function eqAll() {
  let e = this[0];
  for(let i = 1; i < this.length; i++)
    if(this[i] != e)
      return false;
  return true;
} } );

Object.defineProperty( Array.prototype, "eqAll", { value: function eqAll() {
  let list = Object.assign([], this), e = list.shift();
  for(let item of list)
    if(item !== e)
      return false;
  return true;
} } );
