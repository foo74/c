/****************************************************
* Exercise 02.01 from the K&R book.
* by Foo74 -- April 12, 2016
* A program to show the max and min integer values
* for signed and unsigned variable types. For this
* program we will only outline char and int. We 
* will use the 'easy' way for char and the 'hard'
* way for int.
*****************************************************/

/* Include the standard io library and limit definitions.
   We can find all these limits in /usr/include/limits.h */
#include <stdio.h>
#include <limits.h>

/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */
void myfunc(char [], char []);

/* The main function of our program. */
int main()
{
   /* Declare local variables to the main function. */
   int an_int;
   unsigned int an_unsigned_int;

   /* Init variables. */
   an_int = an_unsigned_int = 0x0;

   /* Print some instructions for our users. */
   printf("\nThese are the ranges for this computer:\n\n");

   printf("max for char is: %d\n", CHAR_MAX);
   printf("min for char is: %d\n", CHAR_MIN);
   printf("max for unsigned char is: %u\n\n", UCHAR_MAX);

   an_int = 0b01111111111111111111111111111111;
   printf("max for int is: %d\n", an_int);
   an_int = 0b10000000000000000000000000000000;
   printf("min for int is: %d\n", an_int);
   an_unsigned_int = 0b11111111111111111111111111111111;
   printf("max for unsigned int is: %u\n", an_unsigned_int);

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* Function to copy one array to another.
 * Note that we need to name the args here because C passes
 * args in by value. Except in the case of arrays in which
 * case a pointer to the start of the array is passed in.
 */
void myfunc(char to[], char from[])
{
   int i;

   i = 0;

   /* While we are not at the null terminator, keep going! */
   while ((to[i] = from[i]) != '\0')
      ++i;
}
