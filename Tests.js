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

removeElement(obj, "me");
console.log(obj);

console.log(removeElement(obj, "me"));
console.log(obj.love);


// another example of erasing

var list = [0, 1, 0, 1];
delete list[0]; // null
delete list[1]; // null
list = list.filter(n=>n!=null);
console.log(list);
