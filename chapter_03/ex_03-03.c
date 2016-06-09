/****************************************************
* Exercise 03.03 from the K&R book.
* by Foo74 -- June 08, 2016
*****************************************************/

/* Include our main header file.*/
#include "ex_03-03.h"

/* The main function of our program. */
int main()
{
   char input_str[] = "a-z";
   char output_str[MAX];

   /* Print the header info. */
   printf("\n---------------------------------------------------------");
   printf("\n- Exercise 03.03 from, The C Programming Language,      -");
   printf("\n- by Brian W. Kernighan and Dennis M. Ritchie, 2nd Ed., -");
   printf("\n- AT&T Bell Laboratories (Prentice Hall - 1988).        -");   
   printf("\n---------------------------------------------------------\n\n");

   /* Print the info about this program. */
   printf("This program takes a string that contains\n");
   printf("shorthand and expands it. The function that\n");
   printf("demonstrates this is expand(). The function\n");
   printf("allows for letters of either case and digits\n");
   printf("and handles cases like a-b-c, a-z0-9, and -a-z.\n\n");

   printf("Input String is:\n%s\n\n", input_str);
   expand(input_str, output_str);
   printf("Processed String is:\n%s\n\n", output_str);

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* See header ex_03-03.h for description. */
void expand(char s1[], char s2[])
{
   int i;
   int j;
   int amount;
   int place;
   int character;

   for (i=0; i<MAX && s1[i] != 0; i++)
   {
      if (s1[i] == '-')
      {
         character = s1[i-1];
         s2[i] = 'x';
         amount = s1[i+1]-s1[i-1];
         for (j=i; j<amount; j++)
            s2[j] = character+j;

         place = j;
      }
      else
      {
         s2[place] = s1[i];
         place++;
      }
   }

   s2[place] = 0;
}
