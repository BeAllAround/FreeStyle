// JAVASCRIPT BEHAVIORS
function removeElement(obj, elem){
	var s = {};
	if(obj instanceof Object){
		for(var o of Object.keys(obj)){
			if(o==elem){
				delete obj[o]; // ((&Node)n = null);
				return 1; // terminate further recursion
			}
			if(removeElement(obj[o], elem)==1)return 1;
		}
	}
	return 0;
}
var obj = {want: "10", love: {me: "why", you: {e: {me: "AE"}}, ha: "HA",},};

removeElement(obj, "me"); // or just -> while(removeElement(obj, "me"));
console.log(obj);

console.log(removeElement(obj, "me"));
console.log(obj.love);


// another example of erasing

var list = [0, 1, 0, 1];
delete list[0]; // null
delete list[1]; // null
list = list.filter(n=>n!=null);
console.log(list);

function findObject(obj, item, name){
        if(name==item){
                return 1;
        }
        if(obj instanceof Object){
                for(var o in obj){
                        if(findObject(obj[o], item, o)==1)return 1;
                }
        }
        return 0;
}

function returnObject(obj, item, name, list){
        if(name==item){
                list.push(obj);
                return list;
        }
        if(obj instanceof Object){
                for(var o in obj){
                        if(findObject(obj[o], item, o)==1){
                                list = returnObject(obj[o], item, o, list);
                        }
                }
                return list;
        }
}

function return_object(obj, item){
        return returnObject(obj, item, "", []); // starting point...
}

/*
 // if looking for an extension, there it is!
 
function return__object(obj, item){
        return returnObject(obj, item, "", []); // starting point...
}

function return_object(obj, item){
        var list, _obj={};
        _obj[`${item}`] = (list = return__object(obj, item)).length == 1 ? list[0] : list;
        return _obj;
}
*/

// another example of erasing
console.log("---------------------");
var obj2 = {want: 11, ha:{WHERE: 10}, love: {me: "why", you: {me: 401, ha: "DATA", e: {me: "AE"}}, ha: {data: "KEY"},}, me: "WE",};
console.log(obj2);
console.log(return_object(obj2, "e")); // [ { me: 'AE' } ]
console.log(return_object(obj2, "ha")); // [ { WHERE: 10 }, 'DATA', { data: 'KEY' } ]
console.log(return_object(obj2, "want")); // [ 11 ]
console.log(return_object(obj2, "you")); // [ { me: 401, ha: 'DATA', e: { me: 'AE' } } ]
console.log(return_object(obj2, "me")); // [ 'why', 401, 'AE', 'WE' ]
