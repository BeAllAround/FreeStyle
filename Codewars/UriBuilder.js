function parse(string){
  var s = '';
  if(string.indexOf('?')== -1)
    return string;
  for(let i = string.indexOf('?') + 1; i < string.length; i++){
    s += string[i];
    }
  return s;
}

function clear(string){
  var s = '';
  if(string.indexOf('?') != -1)
    for(let i = 0; i < string.indexOf('?'); i++)
      s += string[i];
  else
    return string;
  return s;
}

class UriBuilder{
  constructor(str){
    this.params = {};
    this.link = str;
    this.default = clear(str);
    this.str = parse(str);
    this.modify();
  }
  modify(){
    if(this.str == '')
	  throw "ERROR";
    if(this.link != this.default){
      for(let s of (this.str.split("&"))){
        s = s.split('=');
        this.params[s[0]] = encodeURIComponent(String(s[1]));
      }
    }

  }
  build(){
    this.link = this.default;
    var keys = Object.keys(this.params);
    this.link += '?';
    for(let i in keys){
      this.link += (keys[i] + '=' + encodeURIComponent(this.params[keys[i]].toString()));
      if(i != keys.length-1){
        this.link += '&';
      }
    }
    return this.link;
  }
}
var u = new UriBuilder("http://www.codewars.com?b=1");
u.params.javascript = "JS";
u.params.java = "Java";
u.params.page = 2;
console.log(u.build());
