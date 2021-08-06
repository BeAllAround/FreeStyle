function __searchObjects(obj, name, toFind, arr){
        if(toFind == name)
		arr.push({[`${toFind}`]: obj});
        if(obj instanceof Object)
                for(var i in obj){
                        arr = __searchObjects(obj[i], i, toFind, arr);
		}
        return arr;
}

function __includesObjects(obj, name, toFind, arr){
	if(toFind == name)
		arr.push(true);
	if(obj instanceof Object)
		for(let i in obj)
			arr = __includesObjects(obj[i], i, toFind, arr);
	return arr;
}

function __includesObject(obj, name, toFind){
	if(toFind == name)
		return true;
	if(obj instanceof Object)
		for(let i in obj)
			if(__includesObject(obj[i], i, toFind))
				return true;
	return false;
}

function searchObjects(obj, toFind){
        return __searchObjects(obj, undefined, toFind, []);
}

function includesObjects(obj, toFind){
	return __includesObjects(obj, undefined, toFind, []);
}

function includesObject(obj, toFind){
	return __includesObject(obj, undefined, toFind);
}

(function __main__(){
	var test_1 = {"": 7, ha: 6, s: {ha: [7, 50, 100], s: {h: {ha: "TEA"}}}};
	console.log(searchObjects(test_1, "s")); // [ { s: { ha: [Array], s: [Object] } }, { s: { h: [Object] } } ]
	console.log(searchObjects(test_1, "ha")); // [ { ha: 6 }, { ha: [ 7, 50, 100 ] }, { ha: 'TEA' } ]
	console.log(searchObjects(test_1, "h")); // [ { h: { ha: 'TEA' } } ]
	console.log(searchObjects(test_1, ""));

	console.log(includesObjects(test_1, "s")); // [true, true]
	console.log(includesObjects(test_1, "ha")); // [true, true, true]
	console.log(includesObjects(test_1, "h")); // [true]

	console.log(includesObject(test_1, "s")); // true
	console.log(includesObject(test_1, "n")); // false
	console.log(includesObject(test_1, "ha")); // true
	console.log(includesObject(test_1, "h")); // true

})();
