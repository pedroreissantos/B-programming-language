long Char(long *vec, long pos)
{
  return (vec[pos/8] >> (pos % 8 * 8)) & 255;
}

long lchar(long *vec, long pos, long val)
{
  vec[pos/8] = (vec[pos/8] & ~(255L << (pos % 8 * 8))) | ((val & 255L) << (pos % 8 * 8));
  return val;
}

void prints(char*);
int putchar(int ch)
{
  int i = -1;
  char prt[2];
  prt[1] = 0;
  while ((++i < 4) & ((ch & 255) != 0)) {
    prt[0] = ch;
    prints((char*)&prt);
    ch = ch >> 8;
  }
  return i;
}
