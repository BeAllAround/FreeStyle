class Hex{
  constructor(num){
    this.num = num;
  }
  
  toString(){
    return "0x"+this.num.toString(16).toUpperCase();
  }
  
  toJSON(){
    return this.toString();
    
  }
  
  valueOf(){
    return this.num;
  }
  
  minus(n){
    return new Hex(this.num-n);
  }
  
  plus(n){
    return new Hex(this.num+n);
  }
  
  static parse(value){
     return parseInt(value, 16);
  }
  
};
