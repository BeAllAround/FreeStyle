int* parse(char*program)
{
  int data[100];
  int c = 0, p = 0;
  char c_;
  while((c_ = *program) != 0){
    if(c_ == 'o')
      data[p++] = c;
    else if(c_ == 's')
      c *= c;
    else if(c_ == 'i')
      c++;
    else if(c_ == 'd')
      c--;
    program++;
  }
  return data;
}
