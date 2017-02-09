main()
{
  extrn putstr(), lower(), putchar(), argc(), argv();

  if (argc() > 1) {
    putstr(lower(argv(1))); putchar('*n');
  }
  return(0);
}
