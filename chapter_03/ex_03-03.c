/****************************************************
* Exercise 03.03 from the K&R book.
* by Foo74 -- June 08, 2016
*****************************************************/

/* Include our main header file.*/
#include "ex_03-03.h"

/* The main function of our program. */
int main(int argc, char *argv[])
{
   char input_str[] = "-a-zA-Ga-b-c0-9";
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
	/* Iterators i and j, amount is the amount to expand, place
	 * is a place holder to keep track of where we are in the
	 * first string. Character is used to store a character.
	 */
   int i = 0;
   int j = 0;
   int amount = 0;
   int place = 0;
   int character = 0;

	/* For each character in string s1, and as long as we
	 * don't overflow our MAX buffer, process the character.
	 */
   for (i=0; i<MAX && s1[i] != 0; i++)
   {
		/* If we find a -, we need to expand. */
      if (s1[i] == '-')
      {
			/* As long as we are not at the first or last character.
			 * If we are then ignore since we don't know what to expand.
			 */
			if (i != 0 && s1[i+1] != 0)
			{		
				/* Find the 'from' expansion. */
				character = s1[i-1];
				/* Start the expansion with the 'from' char. */
				//s2[i] = s1[i-1];

				/* Figure out if upper case, lower case, or integer. */
				/* TODO */

				/* Figure out how much we need to expand. */
				amount = s1[i+1]-s1[i-1];
				/* Loop and expand to s2. */
				for (j=1; j<amount; j++)
					s2[place++] = character+j;

				/* Save our place in s2 so we can expand again. */
				//place = j;
				j = 0;
			}
      }
		/* If we don't find a '-' character then just copy the char. */
      else
      {
         s2[place] = s1[i];
         place++;
      }
   }

   s2[place] = 0;
}
