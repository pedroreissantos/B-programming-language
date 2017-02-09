cnt 0;
ackermann(m, n) {
  cnt = cnt + 1;
  if (m == 0) return (n+1);
  if (n == 0) return (ackermann(m-1, 1));
  return (ackermann(m-1, ackermann(m, n-1)));
}

main() {
  extrn argc(), argv(), atoi(), putchar(), putint();
  if (argc() > 2) {
    putint(ackermann(atoi(argv(1)), atoi(argv(2))));
    putchar(' #');
    putint(cnt);
    putchar('*n');
  }
  return (0);
}
