function commas(str){
        let negative = str < 0 ? true : false;
        let b1 = false;
        str = Math.abs(str);
        str = str.toFixed(3);
        str = str.toString().split('');
        let str_v = '', c = 1;
        let j = str.length-1;
        if(str.includes('.')){
                b1 = true;
                for(j = str.length-1; str[j] != '.'; j--){
                        str_v += str[j];
                }
          
        }
        if(str_v == '000'){
                b1 = false;
                j--;
                str_v = '';
        }
        for(let i = j; i >= 0; i--){
                str_v += str[i];
                if(c == 3){
                        if(i != 0)
                                str_v += ',';
                        c = 1;
                        continue;
                }
                if(str[i] != '.')
                        c++;
        }
        
        str_v = str_v.split('').reverse();
        if(b1)
		while(str_v[str_v.length-1] === '0')
			str_v.pop();
        str_v = str_v.join('');
        return negative ? '-' + str_v : str_v;
}

console.log(commas(122));
console.log(commas(1122));
console.log(commas(11122));
console.log(commas(111122));
console.log(commas(1111122));
console.log(commas(11111122));
console.log(commas(111111122));
console.log(commas(-19111111122.111));
console.log(commas(100.2346));
console.log(commas(9123.312));
console.log(commas(55.28117324485859));
console.log(commas(-888528.4795944451));
console.log(commas(490615.10));
