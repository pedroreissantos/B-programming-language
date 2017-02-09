/* This function prints out an unsympathetic error message on the
terminal for each integer value of errno from O to 5 */

snide(errno) {
   extrn unit, mess, printf();
   auto u; /* temporary storage for the unit number */

   u = unit ; unit = 1;

   printf("error number %d, %s*n",errno,mess[errno]);

   unit = u;
   }

mess [5] "too bad", "tough luck", "sorry, Charlie", "that's the breaks",
       "what a shame", "some days you can't win";

