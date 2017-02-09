flip(x,y){
   auto t;
    t = *x;
    *x = *y;
    *y = t;
    }

main() {
    extrn printn(), putchar();
    auto a, b;
    a = 3;
    b = 7;
    printn(a, 10); printn(b, 10); putchar('*n');
    flip(&a, &b);
    printn(a, 10); printn(b, 10); putchar('*n');
    }
