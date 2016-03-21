#include <stdio.h>

main()
{
   int c;
   c = 0;

   while ((c = getc(stdin)) != EOF)
   {
      if ( c == ' ' || c == '\t')
         printf("\n");
      else
         printf("%c", c);
   }
}
