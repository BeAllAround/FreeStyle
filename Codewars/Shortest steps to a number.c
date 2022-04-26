int shortest_steps_to_num(int num) {
  int step = 0;
  while(num > 1){
    if(num%2 == 0)
      num /= 2;
    else
      num -= 1;
    step++;
  }
  return step;
}
