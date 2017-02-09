getstring(s){
   auto c,i;
   i=0;
   extrn getchar(), lchar();
   while ((c=getchar()) != '*n') lchar(s,i++,c);
   lchar(s,i,'*0');
   return(s) ;
   }
