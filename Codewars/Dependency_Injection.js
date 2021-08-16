/**
 * Constructor DependencyInjector
 * @param {Object} - object with dependencies
 */
function _trim(string){
        string = (string.replace(/function/, ''));
        let _s = '';
        let __s = [];
        for(var item of string){
                if(item == "(" || item == ' ')
                        continue;
                else if(item == ')'){
                        __s.push(_s);
                        break;
                }else if(item == ','){
                        __s.push(_s);
                        _s = '';
                }else
                        _s+=item;
        }
        return __s;
}

function returnNew(obj, string){
        var arr_2 = [];
        var arr_1 = (_trim(string));
        for(var item of arr_1){
                if(obj[item] instanceof Function)
                  arr_2.push(obj[item]);
        }
        return arr_2;

}

var DI = function (dependency) {
  this.dependency = dependency;
};

// Should return new function with resolved dependencies
DI.prototype.inject = function (func) {
  return () => func(...returnNew(this.dependency, func.toString()));
}
