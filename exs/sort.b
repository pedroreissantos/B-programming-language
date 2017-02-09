bubbleCompare(a, b)
{
  extrn strcmp();
  return (strcmp(a, b));
}

main()
{
  extrn bubble(), strcmp(), strdup(), new(), free(), dump(), putchar(), getstr(), putstr();
  auto base, aux;
  auto linha;
  auto max, i, n, ret;

  linha = new(100);
  base = new(max = 100);

  i= 0;
  ret = getstr(linha, 100);
  while (ret != 0) {
    if (i == max/4) {
      auto novo, n;

      novo = new(max * 2);
      n = 0;
      while (n < max/4) {
        novo[n] = base[n];
	n++;
      }
      free(base);
      base = novo;
      max = max * 2;
    }
    base[i] = strdup(linha);
    i++;
    ret = getstr(linha, 100);
  }
  aux = linha; free(aux);
  bubble(base, i);
  n = 0;
  while (n < i) {
    linha = base[n];
    putstr(linha); putchar('*n');
    aux = linha; free(aux);
    n = n + 1;
  }
  aux = linha; free(aux); free(base);
  return (0);
}
