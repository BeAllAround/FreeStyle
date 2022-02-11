function checkF(func){
  func = func.toString().replace(/\/\*[\s\S]*?\*\/|([^:]|^)\/\/.*$/gm, '');
  func = func.slice(func.indexOf('(')+1, func.indexOf(')')).split(',').map(v=>v.trim());
  return (func);
}

let l;
function defaultArguments(func, params) {
  if(checkF(func)[0] != '...args')
    l = checkF(func); 
  return (...args)=>{
    let list = [];
    for(let item of l)
      if(params[item])
        list.push(params[item]);
    if(args.length < list.length)
      for(let _ = 0; _ < args.length; _++)
        list.shift();
    args = (args.concat(list));
    return func(...args);
  }
}
