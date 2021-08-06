function __searchObjects(obj, name, toFind, arr){
        if(name == new String(toFind)) // (Object.keys({undefined: 4, null: 10})) => ["undefined", "null"];
		arr.push({[`${toFind}`]: obj});
        if(obj instanceof Object)
                for(var i in obj)
                        arr = __searchObjects(obj[i], i, toFind, arr);
        return arr;
}

function __includesObjects(obj, name, toFind, arr){
	if(name == new String(toFind))
		arr.push(true);
	if(obj instanceof Object)
		for(let i in obj)
			arr = __includesObjects(obj[i], i, toFind, arr);
	return arr;
}

function __includesObject(obj, name, toFind){
	if(name == new String(toFind))
		return true;
	if(obj instanceof Object)
		for(let i in obj)
			if(__includesObject(obj[i], i, toFind))
				return true;
	return false;
}

class dummy{};

const _dummy = ()=>{
	return new dummy();
}

function searchObjects(obj, toFind){
        return __searchObjects(obj, _dummy(), toFind, []);
}

function includesObjects(obj, toFind){
	return __includesObjects(obj, _dummy(), toFind, []);
}

function includesObject(obj, toFind){
	return __includesObject(obj, _dummy(), toFind);
}

(function __main__(){
	var test_1 = {null: 0, "": 7, ha: 6, undefined: 8, s: {ha: [7, 50, 100, undefined, null], s: {h: {ha: "TEA", null: 4}}}};
	console.log(searchObjects(test_1, "s")); // [ { s: { ha: [Array], s: [Object] } }, { s: { h: [Object] } } ]
	console.log(searchObjects(test_1, "ha")); // [ { ha: 6 }, { ha: [ 7, 50, 100 ] }, { ha: 'TEA' } ]
	console.log(searchObjects(test_1, "h")); // [ { h: { ha: 'TEA' } } ]
	console.log(searchObjects(test_1, ""));
	console.log(searchObjects(test_1, null));
	console.log(searchObjects(test_1, undefined));

	console.log(includesObjects(test_1, "ha")); // [true, true, true]
	console.log(includesObjects(test_1, "s")); // [true, true]
	console.log(includesObjects(test_1, "h")); // [true]

	console.log(includesObject(test_1, "s")); // true
	console.log(includesObject(test_1, "n")); // false
	console.log(includesObject(test_1, "ha")); // true
	console.log(includesObject(test_1, "h")); // true

})();
