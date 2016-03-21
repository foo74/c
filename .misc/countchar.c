#include <stdio.h>

main()
{
   long nc;
   int max;
   int tmpc;

   nc = 0;
   max = 10;
   tmpc = 0;

   while ( nc <= max )
   {
      tmpc = getchar();
      nc++;
      printf("nc = %ld", nc);
   }

   if ( nc > max )
      printf("Exceeded input limit!!!!");
   else
      printf("%ld\n", nc); 
}
