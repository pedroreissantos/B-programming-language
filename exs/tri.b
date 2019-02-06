main()
{
  extrn getint(), putstr();
  auto a, b, c;
  a = b = c = 0;
  a = getint();
  b = getint();
  c = getint();
  if (a < 1 | b < 1 | c < 1)
    putstr("As dimensões dos lados do triângulo devem ser todas positivas*n");
  else if (a + b <= c | a + c <= b | c + b <= a)
    putstr("Não é triângulo*n");
  else if (a == b & b == c)
    putstr("O triângulo é equilátero*n");
  else if (a == b | b == c | c == a)
    putstr("O triângulo é isósceles*n");
  else
    putstr("O triângulo é escaleno*n");
  return (0);
}
