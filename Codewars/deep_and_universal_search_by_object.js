function findItems(obj, ...arguments) {
  let coll = {}
  let path = 'tree'

  // avoid using spread operator with recursion
  function inner_findItems(obj, path, arguments) {
    let is_arr = Array.isArray(obj)
    for(let key in obj) {
      if(typeof obj[key] != 'object' || obj[key] == null) {
        for(let i = 0; i < arguments.length; i++) {
          let arg = arguments[i]
          let eq = false
          if(typeof arg == 'function') {
            eq = !!arg(obj[key])
          } else {
            eq = arg == obj[key] && typeof arg == typeof obj[key]
          }
          if(eq) {
            if(!is_arr) {
              coll[(path ? path : '')  + '.' + key] = obj[key]
            } else {
              coll[(path ? path : '')  + '[' + key + ']'] = obj[key]
            }
          }
        }

      } else {
        if(!is_arr) {
          inner_findItems(obj[key], (path ? path : '') + '.' + key, arguments)
        } else {
          inner_findItems(obj[key], (path ? path : '') + '[' + key + ']', arguments)
        }

      }
    }
  }

  inner_findItems(obj, path, arguments)

  return coll
}
