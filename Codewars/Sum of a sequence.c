unsigned sequence_sum(unsigned start, unsigned end, unsigned step)
{
  unsigned s = 0, i;
  for(i = start; i <= end; i += step)
    s += i;
  return s;
}
