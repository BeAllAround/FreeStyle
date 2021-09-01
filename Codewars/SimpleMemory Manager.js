/**
 * @constructor Creates a new memory manager for the provided array.
 * @param {memory} An array to use as the backing memory.
 */
class MemoryManager{
  constructor(data){
    this.data = data;
    this.max = data.length;
    this.counter = 0;
  }

  allocate(size){
   if(this.counter + size <= this.max){
     var swap = this.counter;
     this.counter += size;
     return swap;
   }
   throw 1;
  }

  release(pointer){
    if(this.counter > 0)
      this.counter -= pointer == 0 ? this.counter : pointer;
 
  }
  write(pointer, value){
    if(this.counter == 0)
      throw 1;
    if(pointer < this.counter)
      this.data[pointer] = value;
    else
      throw 1;
  }
  read(pointer){
    if(pointer <= this.counter)
      return this.data[pointer];
    throw 1;
  }
}

/**
 * Allocates a block of memory of requested size.
 * @param {number} size - The size of the block to allocate.
 * @returns {number} A pointer which is the index of the first location in the allocated block.
 * @throws If it is not possible to allocate a block of the requested size.
 */

/**
 * Releases a previously allocated block of memory.
 * @param {number} pointer - The pointer to the block to release.
 * @throws If the pointer does not point to an allocated block.
 */

/**
 * Reads the value at the location identified by pointer
 * @param {number} pointer - The location to read.
 * @returns {number} The value at that location.
 * @throws If pointer is in unallocated memory.
 */

/**
 * Writes a value to the location identified by pointer
 * @param {number} pointer - The location to write to.
 * @param {number} value - The value to write.
 * @throws If pointer is in unallocated memory.
 */
  var mem = new MemoryManager(new Array(64));
  var pointer1 = mem.allocate(16);
  var pointer2 = mem.allocate(16);
  var pointer3 = mem.allocate(16);
  var pointer4 = mem.allocate(16);
  mem.release(pointer2);
  mem.release(pointer3);
  mem.allocate(16);
  mem.allocate(16);
  mem.allocate(16);

/*
 describe('Allocate is constrained by memory size', function(){
  var mem = new MemoryManager(new Array(256));
  Test.expectError('cannot allocate more memory than exists', function(){ mem.allocate(512); });
  var pointer1 = mem.allocate(128);
  Test.expect(pointer1 >= 0, 'alloc should return pointer');
  Test.expectError('cannot allocate more memory than available', function(){ mem.allocate(129); });
});

describe('Allocate does not have a memory overhead', function(){
  var mem = new MemoryManager(new Array(256));
  Test.expectNoError('should be able to allocate 256 blocks of size 1', function(){
    for(var i = 0; i < 256; i++){
      mem.allocate(1);
    }
  });
});

describe('Released memory may be re-allocated', function(){
  var mem = new MemoryManager(new Array(64));
  var pointer1 = mem.allocate(32);
  var pointer2 = mem.allocate(32);
  mem.release(pointer1);
  Test.expectNoError('should be able to allocate 32 bits', function(){ mem.allocate(32); });

});

describe('Released memory is merged when free blocks are adjacent', function(){
  var mem = new MemoryManager(new Array(64));
  var pointer1 = mem.allocate(16);
  var pointer2 = mem.allocate(16);
  var pointer3 = mem.allocate(16);
  var pointer4 = mem.allocate(16);
  mem.release(pointer2);
  mem.release(pointer3);
  Test.expectNoError('deallocated memory should be merged', function(){ mem.allocate(32); });

});

describe('May not write to unallocated blocks', function(){
  var mem = new MemoryManager(new Array(64));
  Test.expectError('no memory has been allocated', function(){ mem.write(1,1); });
});

describe('May write to allocated blocks', function(){
  var array = new Array(64),
      a = 0,
      b = 1,
      c = 31,
      d = 32,
      mem = new MemoryManager(array),
      pointer1 = mem.allocate(32);
  Test.expectNoError('should be able to write to allocated pointer', function(){ mem.write(pointer1, a); });
  Test.expectNoError('should be able to write to allocated pointer + 1', function(){ mem.write(pointer1 + b, b); });
  Test.expectNoError('should be able to write to allocated pointer + 31', function(){ mem.write(pointer1 + c, c); });
  Test.expectError('should throw on write to allocated pointer + 32', function(){ mem.write(pointer1 + d, d); });
  Test.assertEquals(array[pointer1 + a], a, 'value at pointer + ' + a);
  Test.assertEquals(array[pointer1 + b], b, 'value at pointer + ' + b);
  Test.assertEquals(array[pointer1 + c], c, 'value at pointer + ' + c);
  Test.assertNotEquals(array[pointer1 + d], d, 'value at pointer + ' + d);
});

describe('May not read from unallocated blocks', function(){
  var mem = new MemoryManager(new Array(64));
  Test.expectError('no memory has been allocated', function(){ mem.read(1); });
});

describe('May read from allocated blocks', function(undefined){
  var mem = new MemoryManager(new Array(64));
  var pointer1 = mem.allocate(32);
  mem.write(pointer1,1);
  Test.expectNoError('should be able to read at allocated pointer', function(){ mem.read(pointer1); });
  Test.assertEquals(mem.read(pointer1), 1, 'correct value should be returned');
  Test.assertEquals(mem.read(pointer1 + 1), undefined, 'unwritten location should be undefined');
});
 */
