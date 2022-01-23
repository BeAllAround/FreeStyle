function phone(string, num) {
  let list = [], number = "+" + num;
  string = string.split("\n");
  for(let item of string)
    if(item.indexOf(number)!=-1)
      list.push(item);
  
  if(list.length == 1){
    let data, name, address;
    data = list[0];
    name = (data.match(/\<.+\>/gi))[0];
    data = data.replace(name, "");
    address = data.replace(number, "").trim();
    name = name.replace(/[<|>]/gi, '');
    address = address.replace(/[;|:|/|_|$|*|?|, |,|\!+]/gi, ' ');
    address = address.split(' ').filter(v=>v!='').join(' '); // filter out the unnecessary white space 
    return "Phone => " + num + ", " + "Name => " + name + ", " + "Address => " + address;
  }else if(list.length > 1)
    return 'Error => Too many people: ' + num;
  else
    return 'Error => Not found: ' + num;
 };
