/*
   This program takes input and removes the extra spaces and then
   spits it back out.
*/

#include <stdio.h>

int main()
{
   int c, space_count;
   c = space_count = 0;

   printf("enter some text, I will remove the extra spaces\n");

   while((c=getc(stdin)) != EOF)
   {
      /* if the character is a space then count it, else reset the space counter */
      if (  c == 0x20 )
         space_count++;
      else
         space_count = 0;

      /* print the character as long as it isn't more than one space */
      if ( space_count < 2 )
         printf("%c", c);
   }

   return(0);
}
