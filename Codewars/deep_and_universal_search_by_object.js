function findItems(obj, ...args) {
  let coll = {}
  let path = 'tree'

  // avoid using spread operator with recursion
  function inner_findItems(obj, path) {
    let is_arr = Array.isArray(obj)
    for(let key in obj) {
      if(typeof obj[key] != 'object' || obj[key] == null) {
        for(let i = 0; i < args.length; i++) {
          let arg = args[i]
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
          inner_findItems(obj[key], (path ? path : '') + '.' + key)
        } else {
          inner_findItems(obj[key], (path ? path : '') + '[' + key + ']')
        }

      }
    }
  }

  inner_findItems(obj, path)

  return coll
}
