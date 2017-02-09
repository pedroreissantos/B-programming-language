/* This function is called with a string s of the form nnn, nnn,
   nnn, . . .  , where the nnn are integers.  The values are placed
   in successive locations in a vector v.  The number of integers
   converted is returned as a function value.  This program
   provides a simple illustration of the switch and case state-
   ments. */

convert(s,v) {
   extrn char(), printf();
   auto m,i,j,c,sign;

   i = 0; /* vector index */
   j =-1; /* character index */

init: /* initialize to convert an integer */
   m = 0; /* the integer value */
   sign = 0; /* sign = 1 if the integer is negative */

loop: /* convert an integer */

   switch (c = char(s,++j)){

   case '-':
      if(sign) goto syntax;
     sign = 1;

   case ' ':
      goto loop;

   case  '*0':
   case ',':  /* delimiter . . . store converted value */

      v[i++] = sign?(-m):m;
      if( c == '*0' ) return(i);
      goto init;
      }

/* none of the above cases . . . if a digit, add to m */

   if ( '0' <= c & c <= '9' ){
      m = 10*m + c- '0';
      goto loop;
      }

/* syntax error . . . print message and return -1 */

syntax:
   printf("bad syntax*n");
   return(-1 );
   }

