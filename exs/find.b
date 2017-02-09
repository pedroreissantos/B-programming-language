find(v, sz, n)
{
  auto i;

  i = 0;
  while (i < sz - 1) {
    if (v[i] == n) {
        return (i);
    }
    i = i + 1;
  }
  return (-1);
}
