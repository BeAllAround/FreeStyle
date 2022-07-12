const util = require('util');

function forward(s, start, l, toMatch){
        for(let i = start, j = 0; i < start+l && i < s.length && j < toMatch.length; i++, j++)
                if(s[i] != toMatch[j])
                        return false;
        return true
}

function _format(s, ...args){
        let _s = '';
        let i, j = 0;
        for(i = 0; i < s.length; i++){
                if(forward(s, i, 2, '%d') && j < args.length){
                        _s += args[j++].toString();
                        i += 2-1; // (length-1);
                }else{
                        _s += s[i];
                }
        }
        return _s;
}

util.log(_format("((%d super %d %d %d %%d))", 1, 44, 11, 101, 88));
