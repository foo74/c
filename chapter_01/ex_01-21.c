/****************************************************
* Exercise 01.21 from the K&R book.
* by Foo74 -- March 04, 2016
* Goal is to replace strings of white space with tabs.
*****************************************************/

/* Include the standard io library and  constant definitions. */
#include <stdio.h>

#define MAXLINE 1000

/* Define external, global, variables. */


/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */
int mygetline(char []);


/* The main function of our program. */
int main()
{
   /* Declare local variables to the main function. */
   int len;
   char line[MAXLINE];

   /* Print some instructions for our users. */
   printf("\nType in some lines, I will turn 3 spaces in a row to a tab. Enter a '$' character to end.\n\n");

   while ((len = mygetline(line)) > 0)
   {
      printf("%s", line);
   }

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 *
 * Function to get a new line. Check if there are 3 spaces in a row though
 * and turn them into tabs.
 */
int mygetline(char line[])
{
   /* We use i to make sure we don't overlfow our 1000 char array. We use
    * write_index to keep track of where we are writing in the array since
    * i and write_index will be out of sync if we have 3 spaces that becomes
    * 1 tab. We use space_counter to keep track of how many spaces in a row
    * we see. We use c to hold the char on input.
    */
   int c, i, space_counter, write_index;
   space_counter = write_index = 0;

   /* Get a char of the input and process it, break out on $. */
   for (i=0;i<MAXLINE-1 && (c=getchar()) != EOF && c!= '\n' && c != '$'; ++i)
   {
      /* If there is a space. */
      if (c == ' ')
      {
         /* Increase space counter. */
         space_counter++;

         /* If we are at 3 spaces, turn it into a tab and reset counter. */
         if (space_counter == 3)
         {
            line[write_index++] = '\t';
            space_counter = 0;
         }
      }
      /* Else if the char is not a space. */
      else
      {
         /* If we had 2 or 1 spaces, not enough for a tab, put them in. */
         if (space_counter == 2)
         {
            line[write_index++] = ' ';
            line[write_index++] = ' ';
            line[write_index++] = c;
         }
         else if (space_counter == 1)
         {
            line[write_index++] = ' ';
            line[write_index++] = c;
         }
         else
            line[write_index++] = c;

         /* Reset space counter since this isn't a space. */
         space_counter = 0;
      }
   }

   /* If we are at the end of the line put it in. */
   if (c == '\n')
   {
      line[write_index++] = c;
   }

   /* End our char array with 0. */
   line[write_index] = '\0';

   /* If we encountered a $ character then break out of program. */
   if (c == '$')
      return 0;
   /* Otherwise return the length of our array. */
   else
      return write_index;
}
