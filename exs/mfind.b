v [] 0, 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29;

main()
{
  extrn getint(), putchar(), putint(), find();
  auto i;

  i = getint();
  putchar('v['); putint(find(v, 12, i));
  putchar('] = '); putint(i); putchar('*n');
  return (0);
}
