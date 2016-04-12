/****************************************************
* Exercise 01.20 from the K&R book.
* by Foo74 -- Date 01, 2016
* Goal is to replace tabs with 3 spaces.
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
int checkline(char []);


/* The main function of our program. */
int main()
{
   /* Declare local variables to the main function. */
   int len;
   char line[MAXLINE];

   /* Print some instructions for our users. */
   printf("\nType in some lines, I will show you the longest. Enter a '$' character to end.\n\n");

   while ((len = mygetline(line)) > 0)
   {
      printf("%s", line);

      /* A simple check to see if the tabs turn to spaces.
       * example:  
       * before: aaaaaaaaa<tab>aaaaaaaa
       * after : aaaaaaaaatttaaaaaaaa
       *
      *check_line(line);
      *printf("%s", line);
       */
   }

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.

/* Function to get a new line.
 */
int mygetline(char line[])
{
   int c, i;

   for (i=0;i<MAXLINE-1 && (c=getchar()) != EOF && c!= '\n' && c != '$'; ++i)
   {
      /* Turn a tab into 3 spaces. */
      if (c == '\t')
      {
         line[i] = ' ';
         i++;
         line[i] = ' ';
         i++;
         line[i] = ' ';
      }
      else
         line[i] = c;
   }

   if (c == '\n')
   {
      line[i] = c;
      ++i;
   }

   line[i] = '\0';

   if (c == '$')
      return 0;
   else
      return i;
}

/* A simple funtion that replaces a space with
 * the letter t. This is so we can see if the
 * spaces are inserted correctly.
 */
int check_line(char line[])
{
   int i;

   for (i=0; i<MAXLINE && line[i] != '\0'; i++)
      if (line[i] == ' ')
         line[i] = 't';
}
