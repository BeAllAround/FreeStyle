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

/* // optimal solution
class Stream{
  constructor(start, op1, op2){
    this._start = start;
    this.op1 = op1;
    this.op2 = op2;
  }
  
  head(){
    return this.op1(this._start);
  }
  
  tail(){
    return new Stream(this.op2(this._start), this.op1, this.op2);
  }
};
// sample tests
describe("Tests", () => {
  it("test", () => {
var increment = function(n) {return n + 1};
var id = function(n) {return n};

var naturalNumbers = new Stream(0, id, increment);
Test.assertEquals(naturalNumbers.head(), 0)
Test.assertEquals(naturalNumbers.tail().head(), 1)
Test.assertEquals(naturalNumbers.tail().tail().head(), 2)

var even = function(n) {return n * 2};
var evenNumbers = new Stream(0, even, increment);
Test.assertEquals(evenNumbers.head(), 0)
Test.assertEquals(evenNumbers.tail().head(), 2)
  });
});
*/
