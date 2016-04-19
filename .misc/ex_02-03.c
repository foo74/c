/****************************************************
* Exercise 02.03 from the K&R book.
* by Foo74 -- April 19, 2016
* A program that converts a string of hex to integer.
*****************************************************/

/* Include the standard io library. */
#include <stdio.h>

#define MAX_STRING 10

/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */
void htoi(char []);

/* The main function of our program. */
int main()
{
   /* Declare local variables to the main function. */
   int i;
   char a[MAX_STRING];

   /* Init variables. */
   for (i=0; i<MAX_STRING; i++)
      a[i] = 0; 

   a[0] = 'a';
   a[1] = '0';
   a[2] = 'x';
   a[3] = '5';
   a[4] = '0';
   a[5] = 'X';
   a[6] = 'F';
   a[7] = '0';
   a[8] = 'B';

   /* Print some instructions for our users. */
   printf("\nThe initial string is: %s:\n\n", a);


   printf("\nConverting to integers...\n\n");
   htoi(a);


   printf("\nThe converted array contains the following:\n");
   for (i = 0; i<MAX_STRING; i++)
      printf("a[%d]: %d\n", i, a[i]);

   printf("\n\n");

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* Function to convert a string of hex to integers.
 * Note that C passes args in by value. Except in the
 * case of arrays in which case a pointer to the start
 * of the array is passed. We can accept the hex in the
 * form of 0x<value> or 0X<value> or <value>  where <value> 
 * is a char between '0' to '9' and 'a' to 'f' or 'A' and
 * 'F'. For example. these are valid: a A 0xa 0Xa 0xA 0XA.
 */
void htoi(char s[])
{
   int i;
   int j;
   i = 0;
   j = 0;

   for (i=0; i<MAX_STRING && s[i] != 0; i++)
   {
      /* Only process chars of 0 to a-f or 0 to A-F. */
      if (s[i] >= '0' && s[i] <= '9')
      {
         if (s[i] == '0')
         {
         /* Look ahead to see if this is not 0x or 0X . */
            if (s[i+1] != 'x' && s[i+1] != 'X')
               s[j++] = s[i] - 48;
         }
         else
            s[j++] = s[i] - 48;
      }
      else if (s[i] >= 'A' && s[i] <= 'F')
      {
         s[j++] = s[i] - 55;
      }
      else if (s[i] >= 'a' && s[i] <= 'f')
      {
         s[j++] = s[i] - 87;
      }
   }
   /* Set the rest of the array to 0's. */
   for ( ; j<=i; j++)
      s[j] = 0;

}
