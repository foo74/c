#include <stdio.h>

int main()
{
   int c, nl;

   nl = 0;

   while ((c = getc(stdin)) != EOF)
   {
      printf("c is: %#08x\n", c);
      if (c == 0xA)
         ++nl;
   }

   printf("%d\n", nl);

   return(0);
}
