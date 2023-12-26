function skip_space(arr) {
  while (arr[0][arr[1]] == ' ') {
    arr[1]++
  }
}

function isAlpha(arr) {
  return (arr[0][arr[1]] >= 'a' && arr[0][arr[1]] <= 'z') || (arr[0][arr[1]] >= 'A' && arr[0][arr[1]] <= 'Z' )
}

function isNumber(arr) {
  return arr[0][arr[1]] >= '0' && arr[0][arr[1]] <= '9'
}

function tokenizeLiteral(arr) {
  let s = ''
  // if(!isAlpha(arr)) return s
  while( isAlpha(arr) || isNumber(arr)) {
    s += arr[0][arr[1]++]
  }
  skip_space(arr)
  if(s==='') return s
  if(!isNaN(s)) return parseFloat(s)
  return s
}

function _solve(arr) {
  
  if(arr[0][arr[1]] == '(') {
    let d = {}
    arr[1]++
    skip_space(arr)
    let prev = null
    while( true ) {
      let key = tokenizeLiteral(arr)
      if(arr[0][arr[1]] == '(') {
        let obj = _solve(arr)
        if(key == '') {
          Object.assign(prev, obj)
          skip_space(arr)
          continue
        }
        d[key] = obj
        prev = d[key]
        skip_space(arr)
        
      } else if (isAlpha(arr) || isNumber(arr)){
        let literal = tokenizeLiteral(arr)
        d[key] = literal
      } else if (arr[0][arr[1]] == ')') {
        arr[1]++
        return d
      } else {
        throw new Error('')
      }
      
    }
    
  } else {
    throw new Error('')
  }
  
}

function solve(cursed) {
  return _solve([cursed, 0])
}
