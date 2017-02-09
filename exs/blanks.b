main( ) {
  extrn getchar(), putchar(), exit();
  auto c;
  while (1) {
    while ( (c=getchar()) != ' ') {
      putchar(c);
      if (c == '*n') exit(0);
    }
    putchar( '*n' );
    while ( (c=getchar()) == ' '); /* skip blanks */
    if (c!='*n') putchar(c); else exit(0); /* done when newline */
    }
}
