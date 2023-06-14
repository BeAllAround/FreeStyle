var listComprehension = function(str) {
  str = str.slice(1, str.length-1) // eliminate '[' .* ']'
  let reg = str.match(/(for)\s+(\w+)\s+(in)\s+(.+)/)
  if(!reg) {
    throw new Error('Invalid Syntax')
  }
  let _var = reg[2]
  let { index } = reg
  let body = str.slice(0, index).trim()
  let list = eval(reg[4])
  let arr = []
  
  for(let x of list) {
    this[_var] = x
    arr.push(eval(body))
  }
  
  return arr
}
