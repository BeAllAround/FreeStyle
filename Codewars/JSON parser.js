const CHARS = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+,-./:;<=>?@[\]^_`{|}~"
const DIGS = "0123456789"
const CONSTS = "abcdefghijklmnopqrstuvwxyz"

function _check(arr){
  if(arr[0] >= arr[1].length){
    throw Error('')
  }
}
function skip_space(arr){
  while(arr[0] < arr[1].length && (token(arr) == ' ' || token(arr) == '\n')) {
    arr[0]++
  }
}

function token(arr){
  return arr[1][arr[0]]
}

function _parse(arr, get, flags){
  if(get){
    arr[0]++
  }
  skip_space(arr)
  if(token(arr) == '"'){
    let s = ''
    arr[0]++
    while(token(arr) != '"'){
      s += token(arr)
      _check(arr)
      arr[0]++
    }
    arr[0]++
    skip_space(arr)
    return s
  }
  else if(token(arr) == 't'){
    let s = ''
    while(CONSTS.includes(token(arr))) {
      s += token(arr) 
      _check(arr)
      arr[0]++
    }
    if(s == 'true') {
      return true
    }else {
      throw Error('')
    }
  }
  else if(token(arr) == 'f'){
    let s = ''
    while(CONSTS.includes(token(arr))) {
      s += token(arr) 
      _check(arr)
      arr[0]++
    }
    if(s == 'false') {
      return false
    }else {
      throw Error('')
    }
  }
  else if(token(arr) == 'n'){
    let s = ''
    while(CONSTS.includes(token(arr))) {
      s += token(arr) 
      _check(arr)
      arr[0]++
    }
    if(s == 'null') {
      return null
    }else {
      throw Error('')
    }
  }
  else if(DIGS.includes(token(arr)) || token(arr) == '-') {
    let s = ''
    if(arr[1][arr[0]] == '-') {
      arr[0]++
      s += '-'
    }
    let dot = 0
    while(DIGS.includes(token(arr)) || token(arr) == '.') {
      if(arr[1][arr[0]] == '.') dot++
      s += arr[1][arr[0]++]
    }
    if(dot > 1) {
      throw Error('')
    }
    if(isNaN(parseFloat(s))) {
      throw Error('')
    }
    if(s[0] == '0' && s.length > 1 && s[1] != '.'){
      throw Error('')
    }else if(s[s.length-1] == '.') {
      throw Error('')
    }
    skip_space(arr)
    return parseFloat(s)
  }
  else if(token(arr) == '[') {
    let _list = []
    t = arr[0]
    arr[0]++
    skip_space(arr)
    if(token(arr) == ']') {
      arr[0]++ // eat ']'
      skip_space(arr)
      return _list
    }else {
      arr[0] = t // reset
    }
    while(true) {
      item = _parse(arr, true, flags) 
      _list.push(item)
      if(token(arr) == ','){
        continue
      }else if(token(arr) == ']') {
        arr[0]++ // eat ']'
        skip_space(arr)
        return _list
      }else {
        throw Error('')
      }
      
    }
  }
  else if(token(arr) == '{') {
    let obj = {}
    t = arr[0]
    arr[0]++
    skip_space(arr)
    if(token(arr) == '}') {
      arr[0]++ // eat '}'
      skip_space(arr)
      return obj
    }else {
      arr[0] = t // reset
    }
    while(true){
      let key = _parse(arr, true, flags)
      if(typeof key == 'number') { // numeric key error
        throw Error('')
      }
      if(token(arr) == ':') {
        let value = _parse(arr, true, flags)
        obj[key] = value
        if(token(arr) == ','){
          continue
        }else if(token(arr) == '}'){
          arr[0]++ // eat '}'
          skip_space(arr)
          return obj
        }else {
          throw Error('')
        }
      }else{
       throw Error('') 
      }
    }
    
  }else {
    throw Error('')
  }
}

function parse(s){
  let arr = [0, s]
  let _obj = _parse(arr, false, {})
  if(arr[0] != arr[1].length) {
    throw Error('')
  }
  return _obj
}

/*

// CODEWARS
  
const LOOKUP = { null: null, true: true, false: false }
const PATTERNS = [
  [ /^([:,\[\]\{\}])/,           (x) => ({kind: x, value: null}) ],
  [ /^(-?(0|[1-9]\d*)(\.\d+)?)/, (x) => ({kind: 'number', value: Number(x)}) ],
  [ /^"([^"]*)"/,                (x) => ({kind: 'string', value: x}) ],
  [ /^(null|true|false)/,        (x) => ({kind: 'keyword', value: LOOKUP[x]}) ],
]

function tokenize(source) {
  const tokens = []
  let pos = 0
  
  parse: while (pos < source.length) {
    const ch = source[pos]
    if (ch === ' ' || ch === '\t' || ch === '\r' || ch === '\n') {
      pos++
    } else {
      const slice = source.slice(pos)
      for (let i = 0; i < PATTERNS.length; i++) {
        const [pattern, createToken] = PATTERNS[i]
        const match = slice.match(pattern)
        if (match) {
          tokens.push(createToken(match[1]))
          pos += match[0].length
          continue parse
        }
      }
      
      throw new Error(`Unexpected character "${ch}"`)
    }
  }
  
  return tokens
}

function parse(source) {
  const tokens = tokenize(source)
  
  const peek = () => tokens[0]
  const next = () => tokens.shift()
  const unexpected = () => new Error(`Unexpected token "${peek().kind}"`)
  
  function expect(kind) {
    if (peek().kind === kind) return next()
    throw unexpected()
  }
  
  function any(open, separator, close, ctx, fn) {
    expect(open)
    let first = true
    while (peek().kind !== close) {
      if (first) {
        first = false
      } else {
        expect(separator)
      }
      
      fn(ctx)
    }
    expect(close)
    return ctx
  }
  
  function parseValue() {
    switch (peek().kind) {
      case '[': return parseArray()
      case '{': return parseObject()
      case 'keyword':
      case 'number':
      case 'string':
        return next().value
    }
    throw unexpected()
  }
  
  function parseArray() {
    return any('[', ',', ']', [], (a) => {
      a.push(parseValue())
    })
  }
  
  function parseObject() {
    return any('{', ',', '}', {}, (o) => {
      o[expect('string').value] = expect(':') && parseValue()
    })
  }
  
  const result = parseValue()
  if (tokens.length > 0) throw unexpected()
  
  return result
}
*/
