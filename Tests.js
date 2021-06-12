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

// another example of erasing
console.log("---------------------");
var obj2 = {want: 11, ha:{WHERE: 10}, love: {me: "why", you: {me: 401, ha: "DATA", e: {me: "AE"}}, ha: {data: "KEY"},}, me: "WE",};
console.log(obj2);
console.log(return_object(obj2, "e"));
console.log(return_object(obj2, "ha"));
console.log(return_object(obj2, "want"));
console.log(return_object(obj2, "you"));
console.log(return_object(obj2, "me"));
