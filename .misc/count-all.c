#include <stdio.h>

int main()
{
   int blanks_count, tabs_count, newlines_count, c;

   blanks_count = tabs_count = newlines_count = c = 0;

   printf("Enter some text: ");

   while ( (c = getc(stdin)) != EOF )
   {
      if ( c == 0x20 )
         blanks_count++;
      else if ( c == 0x9 )
         tabs_count++;
      else if ( c == 0xa )
         newlines_count++;
   }

   printf("\nREPORT SUMMARY\nblanks = %d\ntabs = %d\nnewlines = %d\n\n", blanks_count, tabs_count, newlines_count);

   return(0);
}
