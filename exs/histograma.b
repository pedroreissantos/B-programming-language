cruzes(x)
{
  extrn putstr(), putchar();

  if (x > 50)
    putstr("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX...");
  else
    while (x > 0) {
      putchar('X');
      x = x - 1;
    }
  return (0);
}

main()
{
  extrn argc(), argv(), atoi(), putstr(), getint(), putchar(), putint();
  auto tab, lower, upper, step, rand, val;

  if (argc() < 4) {
    putstr("USAGE: histograma lower-limit upper-limit step [random]*n");
    return (1);
  }
  lower = atoi(argv(1));
  upper = atoi(argv(2));
  if (lower >= upper) {
    putstr("invalid argument: lower >= upper*n");
    return (1);
  }
  step = atoi(argv(3));
  if (step <= 0) {
    putstr("invalid argument: step <= 0*n");
    return (1);
  }
  val = (upper-lower+1)/step;
  tab # val;
  while (val > 0) { val = val - 1; tab[val] = 0; }
  if (argc() > 4) {
    auto seed;
    rand = atoi(argv(4));
    if (rand <= 0) {
      putstr("invalid argument: rand <= 0*n");
      return (1);
    }
    seed = 100001;
    while (rand-- > 0) {
      seed = (seed * 125) % 2796203;
      val = seed % (upper-lower+1) + lower;
      tab[(val-lower)/step] = tab[(val-lower)/step] + 1;
      /* putint(rand); putchar(': '); putint(val); putchar('*n'); */
    }
  }
  else {
    val = getint();
    while (val >= lower && val <= upper) {
      tab[(val-lower)/step] = tab[(val-lower)/step] + 1;
      val = getint();
    }
  }
  val = lower;
  while (val <= upper) {
    putint(tab[(val-lower)/step]);
    putchar(' de '); putint(val);
    putchar(' a '); putint(val+step-1); putchar(': ');
    cruzes(tab[(val-lower)/step]);
    putchar('*n');
    val = val + step;
  }
  return (0);
}
