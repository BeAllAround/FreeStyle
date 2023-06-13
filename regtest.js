function range(start, end) {
  let arr = []
  for(let i = start; i <= end; i++) {
    arr.push(i)
  }
  return '(' + arr.join('|') + ')'
}
print(range(1, 31))

function generateReg() {
  let pat = []
  let dates = {
    '01': 31,
    '02': 28,
    '03': 31,
    '04': 30,
    '05': 31,
    '06': 30,
    '07': 31,
    '08': 31,
    '09': 30,
    '10': 31,
    '11': 30,
    '12': 31,
  }

  console.log(Object.keys(dates).sort())
  for(let date of Object.keys(dates).sort()) {
    pat.push('(' + date + '\\-' + range(1, dates[date]) + ')')
  }
  print(pat)
  return new RegExp('\\[' + pat.join('|') + '\\]')


}

var validDate = new RegExp(`\\[(01\\-${range(1, 31)})|(02\\-${range(1, 28)})|(03\\-${range(1, 31)})\\]`)
// validDate = generateReg()

function print(...v) {
  console.log(...v)
}

var v
console.log(validDate)
// validDate = (/\[01\-12\]/)
// print(validDate)

v = '[02-29]'.match(validDate)

print(v)
