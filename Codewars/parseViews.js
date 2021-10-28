function parseViews(str){
	str = str.toString().split('');
	let str_v = '', c = 1;
	for(let i = str.length-1; i >= 0; i--){
		str_v += str[i];
		if(c == 3){
			if(i != 0)
				str_v += ',';
			c = 1;
			continue;
		}
		c++;
	}
	return str_v.split('').reverse().join('');
}


console.log(parseViews(122));
console.log(parseViews(1122));
console.log(parseViews(11122));
console.log(parseViews(111122));
console.log(parseViews(1111122));
console.log(parseViews(11111122));
console.log(parseViews(111111122));
console.log(parseViews(9111111122));
