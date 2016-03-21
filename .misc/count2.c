#include <stdio.h>

main()
{
   double nc;

   for ( nc = 0; getc(stdin) != EOF; ++nc )
      ;
   printf("%.0f\n", nc);
}
