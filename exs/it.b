factorial(n) {
  auto i, f;
extrn putint(), putchar();
putint(n); putchar('*n');

  f = 1;
  i = n;

  while (i > 0) {
    f = f * i;
    i = i - 1;
putint(f); putchar('*n');
putint(i); putchar('*n');
  }

  return (f);
}
