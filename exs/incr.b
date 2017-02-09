main()
{
  extrn putint(), putchar();
  auto x, y, z;
  x = 12; y = 7; z = 1;
  putint(x+++ ++y); putchar('*n');
  putint(y--- --z); putchar('*n');
  return (z);
}
