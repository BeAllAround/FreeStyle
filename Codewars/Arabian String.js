function cap(str){
  str = str.split('');
  return str[0].toUpperCase() + str.slice(1).join('').toLowerCase();
}

function camelize(str){
  return str.split(/[^\w]|\_/gi).filter(v=>v!='').map(cap).join('');
}

/*
  // Codewars
  function camelize(str) {
    return str.match(/[a-z0-9]+/gi).map(function(s) {
      return s[0].toUpperCase() + s.substr(1).toLowerCase()
    }).join('')
  }
*/
