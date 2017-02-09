bubble(v, n)
{
  auto i, j;
  extrn bubbleCompare();

  i = 0;
  while (i < n - 1) {
    j = 0;
    while (j < n - 1 - i) {
      if (bubbleCompare(v[j+1], v[j]) > 0) {
        auto tmp;
	tmp = v[j];
	v[j] = v[j+1];
	v[j+1] = tmp;
      }
      j = j + 1;
    }
    i = i + 1;
  }
  return(0);
}
