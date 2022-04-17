int digits(int n){
  int pow = 1, d = 0;
  while(n >= pow)
    d += n/pow % 10, pow *= 10;
  return d;
}

/*
int digits(int num){
  int s, pow;
  for(s = 0, pow = 1; pow <= num; s += (num/pow)%10, pow*= 10);
  return s;
}
*/

int compute_sum(int n) {
  int i, s = 0;
  for(i = 0; i <= n; i++)
    s += digits(i);
  return s;
}
