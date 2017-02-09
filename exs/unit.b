unit;
main()
{
  extrn atoi(), putchar(), snide(), argc(), argv();

  if (argc() > 1) {
    snide(atoi(argv(1))); putchar('*n');
  }
  return(0);
}
