/* Lista ligada sequencial com um inteiro de controlo:
   size < 0: bloco livre de dimensao -size
   size > 0: bloco ocupado de dimensao size
   size == 0: bloco de terminacao (NULL)
*/

PAGSIZ 1024;
base[1];

abs(v) { if (v >= 0) return (v); return (-v); }

first(x, size)
{
  auto base;
  while (x[0] != 0) {
    if (x[0] < size) {
      return (x);
    }
    base = x;
    x = base + abs(x[0]);
  }
  return (x);
}

new(size)
{
  extrn brk();
  auto x, zero, aux;
  zero = 0;

  if (size <= 0) return (zero);
  size = ((size - 1) / 4 + 1) * 4;

  if (base[0] == 0) { /* bootstrapping */
    base = brk(zero);
    aux = base;
    x = aux + PAGSIZ*4;
    aux = brk(x);
    if (aux < 0) { base = 0; return (base); }
    base[0] = -(PAGSIZ*4-4);
    base[PAGSIZ-4] = 0;
  }

  x = first(base, -size);

  if (x[0] == 0) { /* more core */
    auto n, old, tmp, end;

    n = PAGSIZ*4;
    if (size >= PAGSIZ*4) n = size+4;
    old = brk(zero);
    end = old + n;
    aux = brk(end);
    if (aux < 0) return (zero);
    x[0] = -(aux - old - 4);
    end[-1] = 0;
  }

  /* now x[0] contains a switable space */
  if (x[0] < -(size+4)) {
    x[size/4+1] = x[0] + size + 4;
  }
  x[0] = size+4;
  return (&x[1]);
}

free(ptr)
{
  auto x, seg, old, aux;

  x = base; old = 0;

  if (base[0] == 0) return (-1);
  while (x[0] != 0) {
    if (&x[1] == ptr) {
      aux = old;
      if (aux != 0 && old[0] < 0) {
	aux = x;
	seg = aux + abs(x[0]);
	if (seg[0] < 0) {
	  old[0] = old[0] - x[0] + seg[0];
	}
	else {
	  old[0] = old[0] - x[0];
	}
      }
      else {
	aux = x;
        seg = aux + abs(x[0]);
	if (seg[0] < 0) {
	  x[0] = -x[0] + seg[0];
	}
	else {
	  x[0] = -x[0];
	}
      }
      return (1);
    }
    aux = old = x;
    x = aux + abs(x[0]);
  }
  return (0);
}

dump()
{
  extrn putstr(), putint();
  auto x, aux;
  x = base;

  if (base[0] == 0) return (0);
  while (x[0] != 0) {
    aux = x;
    putstr(" "); putint(x[0]); putstr("@"); putint(aux);
    x = aux + abs(x[0]);
  }
  aux = x;
  putstr(" "); putint(x[0]); putstr("@"); putint(aux); putstr("*n");
  return (1);
}
