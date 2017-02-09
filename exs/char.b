char(vec, pos)
{
  return ((vec[pos/4] >> (pos % 4 * 8)) & 255);
}

lchar(vec, pos, val)
{
  return (vec[pos/4] = (vec[pos/4] & ~(255 << (pos % 4 * 8))) | ((val & 255) << (pos % 4 * 8)));
}

putchar(ch)
{
  extrn putstr();
  auto i, prt;
  i = -1;
  while ((++i < 4) & ((ch & 255) != 0)) {
    prt = ch & 255;
    putstr(&prt);
    ch = ch >> 8;
  }
  return (i);
}
