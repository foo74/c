/*
   This program takes input and changes the tab to \t,
   the backspace to \b, and each \ to \\ so that tabs
   and backspace are visible in an unambiguous way.
*/

#include <stdio.h>

int main()
{
   int c;
   c = 0;


   printf("enter some text, I will change the tabs and spaces and backslashes.\n");
   printf("press . to exit\n\n");
   printf("setting /bin/stty to raw...");
   system("/bin/stty raw");
   printf("\ndone.");

   while((c=getc(stdin)) != '.')
   {
      /* if the character is a tab then replace it with \t. */
      if (  c == 0x9 )
         printf("\\t");
      else if ( c == 0x7F || c == 0x8 )
         printf("\\bbackspace");
      else if ( c == 0x5C )
         printf("\\\\");
      else
         printf("%c", c);

   }

   printf("\n\nsetting /bin/stty to cooked...");
   system("/bin/stty cooked");
   printf("\ndone.");

   printf("\n\nexiting, bye!");
   return(0);
}
