main()
{
  extrn getstr(), putchar(), putint();
  auto x, v, i;
  v # 2;
  v[0] # 100;
  v[1] # 100;
  i = 0;
  x = v[i];
  getstr(x, 400);
  while (x[0] != 0) {
    i = 1 - i;
    x = v[i];
    getstr(x, 400);
    x = v[0]; putint(x); putchar('*n');
    x = v[1]; putint(x); putchar('*n');
    x = v[i];
  }
  return (0);
}
