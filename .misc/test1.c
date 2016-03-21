#include <stdio.h>

main()
{
   int c;

   c = getchar() != EOF;

   if ( c == 0 )
      printf("It's 0 fool!");
   else
      printf("It's 1 fool!");

   putchar('\n');
}
