extern void prints(const char*);
extern int readb();

#ifdef _64bits_
#define underscore
#define int long long
#endif

#ifdef underscore
#define env _env
#define argc _argc
#define argv _argv
#define envp _envp
#define strlen _strlen
#define prints _prints
#define println _println
#define printsp _printsp
#define printi _printi
#define readb _readb
#define readi _readi
#define readln _readln
#define atoi _atoi
#define itoa _itoa
#define debug _debug
#endif

char **env = 0;

static char nl[] = "\n";
static char sp[] = " ";
#define BUFsiz 32
static char buffer[BUFsiz];
int argc() { return (int)*env; }
char *argv(int i) { return env[i+1]; }
char *envp(int i) { return env[((int)*env)+i+2]; }
int strlen(const char *s) {
  int i = 0;
  while (s[i]) i++;
  return i;
}
void println() { prints(nl); }
void printsp() { prints(sp); }
void debug() { }

int atoi(char *s) {
  int i = 0;
  short sign = 1;
  if (*s == '-') { s++; sign = -1; }
  while (*s) {
    if (*s < '0' || *s > '9') break;
    i = i * 10 + *s++ - '0';
  }
  return sign * i;
}

char *itoa(int val) {
  int i = BUFsiz -1, neg = 0;
  buffer[i--] = 0; /* trailing NULL */
  if (val < 0) { neg = 1; val = -val; }
  do {
    buffer[i--] = val % 10 + '0';
  } while (val /= 10);
  if (neg) buffer[i--] = '-';
  return buffer + i + 1;
}

void printi(const int i) { prints(itoa(i)); }

char *readln(char *buf, int siz) {
  int ch, i = 0;

  while ((ch = readb()) > 0) {
    if (ch == '\n' || siz - i == 1) {
      buf[i] = 0;
      return buf;
    }
    buf[i++] = ch;
  }
  return buf;
}

int readi() {
  if (readln(buffer, BUFsiz))
      return atoi(buffer);
// .Lerr:	mov	eax, 0x80000000
  return -1;
}
