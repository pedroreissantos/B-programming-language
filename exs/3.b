x[] 1, 2, 3, 5, 7, 9;
main()
{
  extrn putchar(), putint(), getint();
  auto i;
  i=getint();
  putchar('x[');
  putint(i);
  putchar('] = ');
  putint(x[i]);
  putchar('*n');
  return(0);
}
