main()
{
  extrn new(), free(), dump(), atoi(), argc(), argv(), putstr(), putint();
  auto zero, i, val;
  zero=0;
  i = 0;
  while (++i < argc()) {
    auto ptr;
    val = atoi(argv(i));
    putint(val); putstr("*n");
    ptr = -val;
    if (val < 0) {
      putstr("<"); putint(free(ptr)); putstr("*n"); }
    else if (val > 0) {
      val = new(val);
      putstr(">"); putint(val); putstr("*n"); }
    else val = dump();
  }
  return (0);
}
