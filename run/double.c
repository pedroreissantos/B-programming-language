int d2i(double *d) { return d; }
double *i2d(int i, double *res) { *res = i; return res; }
double *dadd(double *a, double *b, double *res) { *res = *a + *b; return res; }
double *dsub(double *a, double *b, double *res) { *res = *a - *b; return res; }
double *dmul(double *a, double *b, double *res) { *res = *a * *b; return res; }
double *ddiv(double *a, double *b, double *res) { *res = *a / *b; return res; }
int dcmp(double *a, double *b, double *res) { *res = *a - *b; return res; }

