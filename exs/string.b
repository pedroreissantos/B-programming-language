x[1];

strcmp(a, b)
{
  extrn char();
  auto i;
  i = 0;
  while (char(a,i) == char(b,i) & char(a,i) != 0) i++;
  return (char(b,i) - char(a,i));
}

strcpy(a, b)
{
  extrn char(), lchar();
  auto i;
  i = 0;
  while (char(b,i) != 0) {
    lchar(a, i, char(b,i));
    i = i + 1;
  };
  lchar(a,i,0);
  return (a);
}

strdup(a)
{
  extrn new(), strlen();
  auto b;
  b = new(strlen(a) + 1);
  return (strcpy(b, a));
}

strchr(a,b)
{
  extrn char();
  auto s, i;
  i = 0;
  while (char(a,i) != 0)
    if (char(a,i) == b) return (a+i);
    else i++;
  return (0);
}
