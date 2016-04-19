/****************************************************
* Exercise 02.03 from the K&R book.
* by Foo74 -- April 19, 2016
* A program that converts a string of hex to integer.
*****************************************************/

/* Include the standard io library. */
#include <stdio.h>

#define MAX_STRING 8

/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */
unsigned int htoi(char []);

/* The main function of our program. */
int main()
{
   /* Declare local variables to the main function. */
   int i;
   char a[MAX_STRING];

   /* Init variables. */
   for (i=0; i<MAX_STRING; i++)
      a[i] = 0; 

   a[0] = 'F';

   /* Print some instructions for our users. */
   printf("\nConvert a hex string to integer (8 bits max).\n\n");
   for (i=0; i<MAX_STRING && a[i] != 0; i++)
      printf("%c", a[i]);
   printf(" in hex is %d in decimal.\n\n", htoi(a));

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
unsigned int htoi(char s[])
{
/* TODO ACCOUNT FOR 0x or 0X at start */
   int i;
   int total;
   i = 0;
   total = 0;

   for (i=0; i<MAX_STRING && s[i] != 0; i++)
   {
      if (s[i] >= '0' && s[i] <= '9')
      {
         total = total + s[i] - 48;
      }
      else if (s[i] >= 'A' && s[i] <= 'F')
      {
         total = total + s[i] - 55;
      }
      else if (s[i] >= 'a' && s[i] <= 'f')
      {
         total = total + s[i] - 87;
      }
   }

   return total;
}
