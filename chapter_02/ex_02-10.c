/****************************************************
* Exercise 02.10 from the K&R book.
* by Foo74 -- May 18, 2016
*****************************************************/

/* Include our main header file.*/
#include "ex_02-10.h"

/* The main function of our program. */
int main()
{
   char a = 'a';
   char A = 'A';
   char z = 'z';
   char Z = 'Z';

   printf("\n\nInput = %c\nOutput = %c\n\n", a, lower(a));
   printf("Input = %c\nOutput = %c\n\n", A, lower(A));
   printf("Input = %c\nOutput = %c\n\n", z, lower(z));
   printf("Input = %c\nOutput = %c\n\n", Z, lower(Z));

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* See header ex_02-10.h for description. */
char lower(char input)
{
   char output;
   output = -1;

   output = (input >= 'A' && input <= 'Z') ? (input+32) : (input);

   return output;
}
