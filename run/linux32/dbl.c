/* (C)IST 2005 Pedro Reis dos Santos
 * Este código serve apenas para o compilador da disciplina de Compiladores
 * e não substitui as chamadas da biblioteca de C, pois pode introduzir
 * algum erro adicional nos últimos digitos significativos.
 */

#ifdef underscore
#define prints _prints
#define printr _printr
#define printd _printd
#define readr _readr
#define readd _readd
#define readln _readln
#define atoi _atoi
#define atof _atof
#define atod _atod
#define ftoa _ftoa
#define dtoa _dtoa
#endif

double atod(char *s);
char *dtoa(double d, int ndig, char *s);
int atoi(char*);

#ifdef POSTFIX
extern char *readln(char *,int);
extern void prints(char*);
int readr(void) {
  char buf[80];
  float f;
  int ret;

  if (readln(buf, 80) == 0) return 0;
  f = atod(buf);
  ret = *((int*)(&f));
  return ret;
}

void printr(int i)
{
  char buf[80];
  float f;
  *((int*)&f) = i;
  prints(dtoa(f, 7, buf));
}
double readd(void) {
  char buf[80];
  double d;

  if (readln(buf, 80) == 0) return 0;
  d = atod(buf);
  return d;
}

void printd(double d)
{
  char buf[80];
  prints(dtoa(d, 7, buf));
}
#ifdef TEST
static void printf(char*fmt,...){}
#endif
#endif /* POSTFIX */

/* IEEE_ARITHMETIC */
#define FLT_DIG 7
#define DBL_DIG 15
#define DBL_MAX_10_EXP 308
#define DBL_MAX_EXP 1024
#define DBL_MAX 1.7976931348623156e+308
#define LONG_MAX 2147483647

double atod(char *s)
{
  double d = 0;
  int exp = 0, dot = 0, sign = 1;

  while (*s == ' ') s++;
  if (*s == '-') sign = -1, s++;
  while (*s == '0') s++;
  while (*s >= '0' && *s <= '9') d = d * 10 + (*s++ - '0');
  if (*s == '.') {
    s++;
    while (*s >= '0' && *s <= '9') {
      d = d * 10 + (*s++ - '0');
      if (dot <= 0) dot--;
    }
  }
  if (*s == 'E' || *s == 'e') exp = atoi(s+1);
  exp += dot;
  if (exp > 0)
    while (exp-- > 0) d = d * 10;
  else
    while (exp++ < 0) d = d / 10;
  if (sign < 0) d = -d;

#ifdef TEST
  printf("exp=%d dot=%d sign=%d %e %f %g\n", exp, dot, sign, d, d, d);
#endif

  return d;
}

char *dtoa(double d, int ndig, char *s)
{
  static char str[32];
  int i, base, pos = 0;
  double num;

  if (s == 0) s = str;

  if (d == 0.0) { s[0] = '0'; s[1] = 0; return s; }

  if (d < 0) s[pos++] = '-', d = -d;

  if (d >= 1.0) {
    for (num = 1, base = 0; num < DBL_MAX; num *= 10, base++)
      if (num * 10 > d)
	break;
  }
  else
    for (num = 0.1, base = -1; num > 0; num /= 10, base--)
      if (num <= d)
	break;

  d /= num;
#ifdef TEST
  printf("0:10> %gE%d\n", d, base);
#endif

  for (i = 0; i < ndig && d != 0; i++) {
    int x = ((int)d);
    if (x > d) x--; /* truncate */
    s[pos++] = '0' + x;
    if (i == 0) s[pos++] = '.';
    d = (d - x) * 10;
  }
#ifdef TEST
  s[pos] = 0;
  printf("rem=%g (%s)\n", d, s);
#endif
  if (d >= 5) { /* arredondamento simetrico */
    while (s[pos-1] == '9')
      pos--;
    if (s[pos-1] != '.') /* ver se e' '.' ou ultimo digito */
      s[pos-1]++;
    else {
      pos--;
      if (s[pos-1] != '9')
        s[pos-1]++;
      else {
        s[pos-1] = '1';
	base++;
      }
    }
  }
  else
    while (s[pos-1] == '0')
      pos--;

  if (s[pos-1] == '.') pos--;
  if (base != 0) {
    s[pos++] = 'E';
    if (base < 0) s[pos++] = '-', base = -base;
    if (base > 100) {
      s[pos++] = '0' + base / 100; base %= 100;
      s[pos++] = '0' + base / 10; base %= 10;
      s[pos++] = '0' + base;
    }
    else
      if (base > 10) {
	s[pos++] = '0' + base / 10; base %= 10;
	s[pos++] = '0' + base;
      }
      else
	s[pos++] = '0' + base;
  }

  s[pos] = 0;
  return s;
}

float atof(char *s) { return atod(s); }
char *ftoa(float f, int ndig, char *s) { return dtoa(f, ndig, s); }

#ifdef TEST
#include <stdio.h>
int main()
{
  char buf[80];
  double d;

  while (fgets(buf, 80, stdin) != 0) {
    d = atod(buf);
    printf("%s\n", dtoa(d, 15, buf));
  }

  return 0;
}
#endif
