function __searchObjects(obj, name, toFind, arr){
        if(toFind == name)
                arr.push({[`${toFind}`]: obj});
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
	console.log(searchObjects(test_1, "s")); // [ { s: { ha: [Array], s: [Object] } }, { s: { h: [Object] } } ]
	console.log(searchObjects(test_1, "ha")); // [ { ha: 6 }, { ha: [ 7, 50, 100 ] }, { ha: 'TEA' } ]
	console.log(searchObjects(test_1, "h")); // [ { h: { ha: 'TEA' } } ]
})();
