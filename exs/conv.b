vec[10];
main()
{
  extrn putint(), convert(), putchar(), argc(), argv();
  auto i, j;

  if (argc() > 1) {
    j = convert(argv(1), vec);
    i = 0;
    while (i < j) {
      putint(vec[i]);
      putchar('*n');
      i++;
    }
  }
  return(0);
}
