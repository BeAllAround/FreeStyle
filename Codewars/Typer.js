var typer = (function(TO_BE_DEFINED_BY_YOU) {
  return {
    isNumber: (n)=>{
      if(isNaN(n.valueOf()))
        return false;
      return n.valueOf().constructor ===Number;
    },
    isString: (n)=>{
      return n.valueOf().constructor === String;
    },
    isArray: (n)=>n instanceof Array,
    isFunction: (n)=>n instanceof Function,
    isDate: (n)=>n instanceof Date,
    isRegExp: (n)=>n instanceof RegExp,
    isBoolean: (n)=>{
      if(n===true)
        return true;
      if(n===false)
        return true;
      return n.constructor == Boolean
    },
    isError: (n)=>n instanceof Error,
    isNull: (n)=>n===null,
    isUndefined: (n)=>n===undefined,
  };
}(null));
