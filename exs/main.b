/* The following complete B program, if compiled 
  will copy stdin to stdout. */
main () {
   extrn putchar(), getchar();
   while( putchar( getchar() ) != '*0' ) ; /* copy contents */
   }
