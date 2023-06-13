function range(start, end) {
  let arr = []
  for(let i = start; i <= end; i++) {
    arr.push(i + '\\]')
  }
  return '(' + arr.reverse().join('|') + ')'
}

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

  for(let date of Object.keys(dates).sort()) {
    pat.push('(' + '\\[' + date + '\\-' + range(1, dates[date]) + ')')
  }
  
  return new RegExp('(' + pat.join('|') + ')')

}

var validDate = generateReg();
