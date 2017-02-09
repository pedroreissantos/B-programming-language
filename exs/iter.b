factorial(n) {
  auto i, f;

  f = 1;
  i = n;

  while (i > 0) {
    f = f * i;
    i = i - 1;
  }

  return (f);
}
