function change(s, prog, version) {
  let _s = s.split('\n');
  let data = {"Author": "g964", "Date": "2019-01-01", "Program": prog};
  let _list = ['Program title', 'Author', 'Corporation', 'Phone', 'Date', 'Version', 'Level']
  let _v = /^\d+\.\d+$/, _p = /^\+1\-\d{3}\-\d{3}\-\d{4}$/;
  let item;
  for(let i in _s){
    item = (_s[i].replace(_list[i]+':', '').trim())
    if(_list[i] == 'Version'){
      if(!item.match(_v))
        return'ERROR: VERSION or PHONE';
      if(item == '2.0'){
        data['Version'] = '2.0';
        continue;
      }
      data['Version'] = version;
    }
    else if(_list[i] == 'Phone'){
      if(!item.match(_p))
        return'ERROR: VERSION or PHONE';
      data['Phone'] = "+1-503-555-0090";
    }
  }
  return 'Program: ' + data['Program'] + ' ' + 'Author: ' + data['Author'] + ' ' + 'Phone: ' + data['Phone'] + ' ' + 'Date: ' + data['Date'] + ' ' + 'Version: ' + data['Version'];
}

/*
  // Codewars
  function change(s, prog, version) {
    if (/Version: 2.0\n/.test(s))
      version = '2.0';

    if (!/Phone: (\+1-\d{3}-\d{3}-\d{4})\n/.test(s) || !/Version: \d+\.\d+\n/.test(s))
      return 'ERROR: VERSION or PHONE';

    return `Program: ${prog} Author: g964 Phone: +1-503-555-0090 Date: 2019-01-01 Version: ${version}`;
  }
*/
