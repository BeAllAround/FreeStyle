// my solution
Array.prototype.sameStructureAs = function (other) {
        if(this instanceof Array && other instanceof Array){
                for(var i in this){
                  // my API conditional block 
                  if(this[i] instanceof Function && other[i] instanceof Function)
                    continue;
                  if (!(this[i] instanceof Array))
                    if(other[i] instanceof Array)
                       return false;
                  if(this[i] instanceof Array)
                    if(!(other[i] instanceof Array))
                      return false;
                  if(other[i] instanceof Array && this[i] instanceof Array)
                    if(other[i].length != this[i].length)
                      return false;
                  //
                  if(this[i] instanceof Array && other[i] instanceof Array)
                    if(!(this[i].sameStructureAs(other[i])))
                      return false;
                }  
        }else
          if(this instanceof Array && other instanceof Array){
            if(this.length != other.length)
              return false;
          }else
              return false;
        return true;

};

// optimal solution
Array.prototype.sameStructureAs = function (other) {
    return (this.length === other.length) ? this.every(function(el, i){
      return Array.isArray(el) ? el.sameStructureAs(other[i]) : true;
    }) : false;
};
