factorial(n)
{
  if (n < 3) return (n);
  return (n * factorial(n - 1));
}
