var seneca = require('seneca')()

seneca.add({role: 'math', cmd: 'sum'}, function (msg, respond) {
  var sum = msg.left + msg.right
  respond(null, {answer: sum})
})

// both these messages match role: math, cmd: sum


seneca.act({role: 'math', cmd: 'sum', left: 1.5, right: 2.5}, (err, result)=>console.log(result))
seneca.act({role: 'math', cmd: 'sum', left: 1.5, right: 2.5, integer: true}, (err, result)=>console.log(result))

seneca.add({role: 'math', cmd: 'sum', integer: true}, function (msg, respond) {
  var sum = Math.floor(msg.left) + Math.floor(msg.right)
  respond(null, { answer: sum })
})

// this still matches role: math, cmd: sum
seneca.act({role: 'math', cmd: 'sum', left: 1.5, right: 2.5}, (err, result)=>console.log(result))

// BUT this matches role:math,cmd:sum,integer:true
// because it's more specific - more properties match
seneca.act({role: 'math', cmd: 'sum', left: 1.5, right: 2.5, integer: true}, (err, result)=>console.log(result))
/*
 * Getting:
 { answer: 4 }
 { answer: 3 }
 { answer: 4 }
 { answer: 3 }
 * According to the docs, Supposed to get:
 { answer: 4 }
 { answer: 4 }
 { answer: 4 }
 { answer: 3 }
*/
