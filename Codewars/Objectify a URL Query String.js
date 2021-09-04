// Converts a URL Query String into an object map
function convertQueryToMap(query) {
  query = ((query)) + '&'; // .split(/\.|&/);;
  let origin = {};
  let str = '', obj = origin;
  let i;
  for(i = 0; i < query.length; i++){
    if(query[i] == '.'){
      if(obj[str] == null){
        obj[str] = {};
        obj = obj[str];
      }else
        obj = obj[str];
      str = '';
      continue;
    }else if(query[i] == '&' && i != query.length-1){
      obj = origin;
      str = '';
      continue;
    }else if(query[i] == '='){
      str_1 = '';
      i++;
      while(query[i] != '&'){
        str_1 += query[i];
        i++;
      }
      i--;
      obj[str] = decodeURIComponent(str_1);
      str_1= '';
      str = '';
      continue;
    }
    str += query[i];
  }
  return origin;
}
