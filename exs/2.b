main()
{
  extrn putstr(), putint(), putchar(), argc(), argv();

  putstr("argc = "); putint(argc()); putchar('*n');
  if (argc() > 1) {
    putstr("argv[1] = "); putstr(argv(1)); putchar('*n');
  }
  return(0);
}
