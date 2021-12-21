function fibonacci(max) {
  back = 0, front = 1;
  s = 0;
  while(front < max){
    if(back % 2 == 0 && back < max)
      s+=back;
    if(front % 2 == 0)
      s+=front;
    front = back + front;
    back = back + front;
  }
  return s;
}
