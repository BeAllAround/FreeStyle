typedef struct{
  int a;
  int b;
}data;

data len(n){
  int c = 0, _m = 1;
  while(n > 0)
    _m *= n%10, n /= 10, c++;
  return (data){c==0 ? 1 : c, _m};
}

int persistence(int n) {
  int c = 0;
  data counter = len(n);
  while(counter.a != 1)
    counter = len(counter.b), c++;
  return c;
}
