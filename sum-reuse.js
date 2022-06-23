var seneca = require('seneca')()

setTimeout(()=>{
seneca.add({role: 'math', cmd: 'sum'}, function (msg, respond) {
  var sum = msg.left + msg.right
  respond(null, {answer: sum})
})
}, 0);

// both these messages match role: math, cmd: sum

setTimeout(()=>{
seneca.act({role: 'math', cmd: 'sum', left: 1.5, right: 2.5}, console.log)
seneca.act({role: 'math', cmd: 'sum', left: 1.5, right: 2.5, integer: true}, console.log)
}, 100);

setTimeout(()=>{
	seneca.add({role: 'math', cmd: 'sum', integer: true}, function (msg, respond) {
  	var sum = Math.floor(msg.left) + Math.floor(msg.right)
  	respond(null, { answer: sum })
	});
}, 200);

setTimeout(()=>{
// this still matches role: math, cmd: sum
seneca.act({role: 'math', cmd: 'sum', left: 1.5, right: 2.5}, console.log)

// BUT this matches role:math,cmd:sum,integer:true
// because it's more specific - more properties match
seneca.act({role: 'math', cmd: 'sum', left: 1.5, right: 2.5, integer: true}, console.log)
}, 300);
