n 45;
i;
j 1;
seg[1];

main()
{
  extrn putint(), putchar();
  seg = &i;
  while (n-- > 0) {
    putint(seg[0] = i + j); putchar(', ');
    seg = (seg == &i) ? &j : &i;
  }
  putchar('...*n');
  return (0);
}
