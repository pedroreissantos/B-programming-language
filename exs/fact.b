FACTORIAL 5;

main()
{
  auto f, n;
  extrn argc(), argv(), atoi(), factorial(), putint(), putchar();

  if (argc() > 1) {
    n = atoi(argv(1));
  }
  else {
    n = FACTORIAL;
  }

  putint(n); putchar('! = '); putint(factorial(n)); putchar('*n');

  return(0);
}
