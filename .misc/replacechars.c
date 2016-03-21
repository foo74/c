/*
   This program takes input and changes the tab to \t,
   the extra spaces trimmed, and the \ to \\.
*/

#include <stdio.h>

int main()
{
   int c;
   c = 0;


   printf("enter some text, I will change the tabs and spaces and backslashes.\n");
   printf("press control-d to exit.\n\n");

   while((c=getc(stdin)) != EOF)
   {
      /* if the character is a tab then replace it with \t. */
      if (  c == 0x9 )
         printf("\\t");
      else if ( c == 0x5C )
         printf("\\\\");
      else
         printf("%c", c);

   }

   printf("\n\nexiting, bye!");
   return(0);
}
