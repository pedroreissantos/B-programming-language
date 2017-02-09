int _div(int a, int b) { return a / b; }
int _mod(int a, int b) { return a % b; }
unsigned int _udiv(unsigned int a, unsigned int b) { return a / b; }
unsigned int _umod(unsigned int a, unsigned int b) { return a % b; }
void __aeabi_idiv0() {}

double _dmul(double a, double b) { return a * b; }
double _ddiv(double b, double a) { return a / b; }
double _dadd(double a, double b) { return a + b; }
double _dsub(double b, double a) { return a - b; }
int _dcmp(double b, double a) { return a == b ? 0 : (a > b ? 1 : -1); }
double _dneg(double a) { return -a; }
double _i2d(int a) { return a; }
int _d2i(double a) { return a; }
double _f2d(float a) { return a; }
float _d2f(double a) { return a; }
