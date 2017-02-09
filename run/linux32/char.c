#ifdef underscore
#define Char _char
#define lchar _lchar
#define putchar _putchar
#define prints _prints
#endif

int Char(int *vec, int pos)
{
  return (vec[pos/4] >> (pos % 4 * 8)) & 255;
}

int lchar(int *vec, int pos, int val)
{
  return vec[pos/4] = (vec[pos/4] & ~(255 << (pos % 4 * 8))) | ((val & 255) << (pos % 4 * 8)), val;
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
