/* This function replaces each upper case character in the input
   string s by its lower case equivalent.   It uses the fact that
   the ascii alphabetic characters are contiguous. */

lower(s) {
   extrn char(), lchar();
   auto c,i;
   i = -1 ;
   while( (c=char(s,++i)) != '*0'  )
   if( c >= 'A' & c <= 'Z' ) lchar(s, i, char(s,i)-'A'+'a');
   return(s);
   }

