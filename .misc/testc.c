#include <stdio.h>

int main()
{
   char c;

   printf("Enter a char: ");
   c = getc(stdin);
   printf("char entered: ");
   putc(c, stdout);
   printf("\n\n");

   return (0);
}
