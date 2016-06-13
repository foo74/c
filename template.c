/****************************************************
* Exercise x.xx from the K&R book.
* by Foo74 -- Date xx, xxxx
*****************************************************/

/* Include the standard io library and  constant definitions. */
#include <stdio.h>
#define MAXLINE 1000

/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */
void myfunc(char [], char []);

/* The main function of our program. */
int main(int argc, char *argv[])
{
   /* Declare local variables to the main function. */
   int myint;
   char myline[MAXLINE];

   /* Init variables. */
   max = 0;

   /* Print some instructions for our users. */
   printf("\nType in some lines, I will show you the longest. Enter a '$' character to end.\n\n");


   /* code goes here
    *
    *
    */


   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.

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
