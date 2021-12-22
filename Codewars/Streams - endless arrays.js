class Stream{
  constructor(start, op1, op2){
    this._start = start;
    this.op1 = op1;
    this.op2 = op2;
    this.copy = [start, op1, op2];
  }
  
  head(){
    let __ = this.op1(this._start)
    this._start = this.copy[0];
    return __;
  }
  
  tail(){
    return new Stream(this.op2(this._start), this.op1, this.op2);
  }
  
};
