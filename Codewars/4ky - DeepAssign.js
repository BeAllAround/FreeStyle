// given a keyPath as a string assign the value
// to the given keyPath
const CHARS = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
const DIGITS = '0123456789'

function char(ch) {
  return ch[1][ch[0]]
}

function next(ch){
    ch[0]++
}

function scan_int(ch, get = 0) {
  let v = ''
  if(get)
    next(ch)
  
  while(DIGITS.includes(char(ch))) {
    v += char(ch)
    next(ch)
  }
  return parseInt(v)
}

function scan_tem(ch, get = 0){
  let tem = ''
  if(get)
    next(ch)
  
  while(CHARS.includes(char(ch))) {
    tem += char(ch)
    next(ch)
  }
  return tem
}

function deepAssignment(obj, keyPath, value) {
  let ch = [0, keyPath]
  let key
  let _obj = obj
  let pre = {}
  while(1) {
    if(CHARS.includes(char(ch))) {
      key = scan_tem(ch)
      pre = _obj
      _obj = _obj[key] = typeof _obj[key] == 'object' ? _obj[key] : {} // prev: _obj }
      
      
    }
    else if(char(ch) == '.') {
      next(ch)
      key = scan_tem(ch)
      pre = _obj
      _obj = _obj[key] = typeof _obj[key] == 'object' ? _obj[key] : {} // prev: _obj }
    }
    else if(char(ch) == '[') {
      next(ch)
      let index = scan_int(ch)
      if(char(ch) != ']') {
        throw new Error('invalid')
      }
      next(ch)
      // _obj = Array.from(_obj)
      pre[key] = Array.from(pre[key])
      _obj = pre[key]
      pre = _obj
      _obj = _obj[index] = typeof _obj[index] == 'object' && _obj[index] != null ? _obj[index] : {}
      key = index
      
    }
    else if(char(ch) === undefined) {
      // let keys = Object.keys(pre)
      // let last = keys[keys.length-1]
      pre[key] = value
      return
    }
    else {
      return
    }
    
  }
}
