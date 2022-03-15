function isLower(s){
  return s === s.toLowerCase();
}

function isUpper(s){
  return s === s.toUpperCase();
}

function validate(password) {
  let alph = 'abcdefghijklmnopqrstuvwxyz', checker = {U: 0, L: 0, N: 0};
  if(password.length < 6)
    return false;
  for(let char of password)
    if(!alph.includes(char.toLowerCase()) && isNaN(Number(char)))
      return false;
    else if(char == ' ')
      return false;
    else if(!isNaN(char))
      checker.N++;
    else if(isLower(char))
      checker.L++;
    else if(isUpper(char))
      checker.U++;
  const{U, L, N}=checker;
  return U && L && N;
}

/*
  // Codewars
  function validate(password) {
    return  /^[A-Za-z0-9]{6,}$/.test(password) &&
            /[A-Z]+/           .test(password) &&
            /[a-z]+/           .test(password) &&
            /[0-9]+/           .test(password) ;
  }
  
  function validate(password) {
    return /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])[a-zA-Z0-9]{6,}$/.test(password);
  }
  
  function validate(password) {
    return /^(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])\w{6,}$/.test(password);
  }
*/
