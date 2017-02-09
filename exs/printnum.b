main()
{
  extrn printn(), getint(), putchar();
  auto a, b;

  putchar('a = ');
  a = getint();
  putchar('b = ');
  b = getint();
  printn(a, b);
  putchar('*n');
  return (0);
}
