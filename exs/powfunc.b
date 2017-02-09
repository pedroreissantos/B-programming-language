main()
{
  extrn power(), putstr(), putint(), getint(), putchar();
  auto a, b;

  putstr("calculo de potencias inteiras*nintroduza a base: ");
  a = getint();
  putstr("introduza o expoente: ");
  b = getint();
  putint(a); putchar('^'); putint(b);
  putchar(' = '); putint(power(a, b)); putchar('*n');
  return (0);
}
