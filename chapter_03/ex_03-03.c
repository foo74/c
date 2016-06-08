/****************************************************
* Exercise 03.03 from the K&R book.
* by Foo74 -- June 08, 2016
*****************************************************/

/* Include our main header file.*/
#include "ex_03-03.h"

/* The main function of our program. */
int main()
{
   char init_string[MAX] = "This is a string	with some 	tabs	and some \nnewline\n.";
   char result_string[MAX] = "";

   /* Print the header info. */
   printf("\n---------------------------------------------------------");
   printf("\n- Exercise 03.02 from, The C Programming Language,      -");
   printf("\n- by Brian W. Kernighan and Dennis M. Ritchie, 2nd Ed., -");
   printf("\n- AT&T Bell Laboratories (Prentice Hall - 1988).        -");   
   printf("\n---------------------------------------------------------\n\n");

   /* Print the info about this program. */
   printf("This program takes a string and converts the tabs and\n");
   printf("newline to escape sequences \\t and \\n.\n\n");
   printf("Starting String is:\n%s\n\n", init_string);

   escape(init_string, result_string);

   printf("Processed String is:\n%s\n\n", result_string);

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* See header ex_03-03.h for description. */
void escape(char s[], char t[])
{
   /* i is indexer, and dest_index to keep track of dest array. */
   int i;
   int dest_index;
   i = 0;
   dest_index = 0;

   /* For each char in the array, while we are not yet at 0. */
   for (i=0; s[i] != 0 && i < MAX; i++)
   {
      /* Test the char. */
      switch (s[i])
      {
         /* The ascii value 9 is a tab. */
         case 9:
            t[dest_index++] = '\\';
            t[dest_index++] = 't';
            break;
         /* The ascii value 10 is a newline. */
         case 10:
            t[dest_index++] = '\\';
            t[dest_index++] = 'n';
            break;
         /* If not a tab or newline then just copy char. */
         default:
            t[dest_index++] = s[i];
            break;
      }
   }
}
