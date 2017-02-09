/* maior divisor comum entre dois numeros inteiros positivos */
main()
{
  extrn getint(), putstr(), putint(), putchar();
  auto a, b;
  a = b = 0;
  a = getint();
  b = getint();
  if (a <= 0 | b <= 0)
    putstr("Os numeros devem ser inteiros positivos*n");
  else {
    auto m, d, i;
    m = a; d = 1;
    if (a > b) m = b;
    i = 2;
    while (i <= m) {
      if (a % i == 0) if (b % i == 0) d = i;
      i = i + 1;
    }
    putint(d); putstr(" e' o maior divisor comum entre ");
    putint(a); putchar(' e '); putint(b); putchar('*n');
  }
  return (0);
}
