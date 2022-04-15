int solution(int number) {
  int c = 0, n;
  number -=1;
  while((n = number--) > 0) // love the trick!
    if(n % 3 == 0 || n % 5 == 0)
      c += n;
  return c;
}
