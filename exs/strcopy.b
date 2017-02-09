 strcopy(sl ,s2){
   auto i;
   i = 0;
   extrn char(), lchar();
   while (lchar(sl,i,char(s2,i)) != '*0') i++;
   return (s2);
  }
