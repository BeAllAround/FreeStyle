
function __searchObjects(obj, name, toFind, arr){
	if(toFind == name){
		arr.push({[`${toFind}`]: obj});
		return arr;
	}
	if(obj instanceof Object)
		for(var i in obj)
			arr = __searchObjects(obj[i], i, toFind, arr);
	return arr;
}

function searchObjects(obj, toFind){
	return __searchObjects(obj, "", toFind, []);
}

(function __main__(){
	var test_1 = {ha: 6, s: {ha: [7, 50, 100], s: {h: {ha: "TEA"}}}};
	console.log(searchObjects(test_1, "ha"));
})();
