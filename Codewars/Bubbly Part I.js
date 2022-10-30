const start = function(name){
  if(name === end) {
    let temp = start.stack[0]
    start.stack = []
    return temp
  }
  if([add, sub, mul, div].find(func=>func === name)) {
    return name()
  }
  return name
}
const end = function() {}
const push = function(val){
    start.stack.push(val)
    return start
}
const add = function() {
  start.stack.push(
    start.stack.pop() + start.stack.pop()
  )
  return start
}
const sub = function() {
  start.stack.push(
    start.stack.pop() - start.stack.pop()
  )
  return start
}
const mul = function() {
  start.stack.push(
    start.stack.pop() * start.stack.pop()
  )
  return start
};
const div = function() {
  start.stack.push(
    ~~(start.stack.pop() / start.stack.pop())
  )
  return start
}


start.stack = []
