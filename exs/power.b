power(a, b)
{
  auto res;

  if (b < 0) return (0);
  if (b == 0) return (1);
  res = a;
  while (b > 1) {
    res = res * a;
    b = b - 1;
  }
  return (res);
}
