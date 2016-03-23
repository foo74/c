/****************************************************
* Exercise 1.18 from the K&R book.
* by Foo74 -- March 22, 2016
*****************************************************/

/* Include the standard io library and define MAXLINE at 1000 which is
 * the max size of our arrays.
 */
#include <stdio.h>
#define MAXLINE 1000

/* Declare the functions, note don't need a variable name here,
 *  just the type. char arrays and int. 
 */
int mygetline(char [], int );
void copy(char [], char []);
int trim_trailing_whitespace(char []);

/* The main function of our program. */
int main()
{
   /* Declare length, max, and a couple of char arrays we will use. */
   int len, max, num_lines;
   char line[MAXLINE];
   char longest[MAXLINE];

   /* Init max to zero. */
   max = len = num_lines = 0;

   /* Print some instructions for our users. */
   printf("\nType in some lines. I will tell you the longest and some data.\n");
   printf("Enter a '$' character to end. Tabs and blanks at the end don't count!\n\n");

   /* While there is a line to get, if control-d then we will be 0. */
   while ((len = mygetline(line, MAXLINE)) > 0)
   {
      /* Check to see if a blank line, only a '\n' char. */
      if (len != 1)
         num_lines++;

      /* Trim out the trailing tabs and spaces. */
      len = trim_trailing_whitespace(line);
      
      /* If the length of the new line is greater than max then save it as new max. */
      if (len > max)
      {
         max = len;

         /* As long as the length is not going to overflow our array, copy it. Otherwise 
          * print that the line is too long but give the length. This is the root of 
          * this exercise. */
         if (len < MAXLINE-1)
            copy(longest, line);
         else
            printf("\nthe line is too long, but its length is: %d\n\n", len);
      }
   }

   /* We are out of the while loop now, print the longest line we found that didn't
    * overflow our buffer. */
   if (max > 0)
   {
      printf("Total lines: %d\n", num_lines);
      printf("Number of chars, including the carriage return, in longest line: %d\n", max);
      printf("Longest line is: %s", longest);
   }

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}

/* A function that takes in a char array and a limit and fills it. */
int mygetline(char s[], int lim)
{
   int c, i;
   c = i = 0;


   /* For loop, while we are not end of file, while we are not end of line, and
    * while we are not the & character, push on. */
   for (i=0; (c=getchar()) != EOF && c!='\n' && c!='$'; ++i)
   {
      /* If I is less than 1000, which is size of our array, then set the char array. */
      /* Also, check if this is a blank line with only return character. If so, ignore it. */
      if (i < lim-1 && !(i==0 && c=='\n'))
      {
         s[i] = c;
      }
   } 

   /* If we find a newline character then set the end of the array with the '\n' and
    * increment i so that we have that value for the length. Newline is a byte of ascii
    * code so we count it as part of the length. Even a line with just hitting Enter
    * gets counted as a 1 in length. In this case '\n' is the character, and then a '\0'
    * to end the line. */
   if (c == '\n')
   {
      s[i] = c;
      ++i;
   }

   /* If we find the '$' character then end the program. */
   if (c == '$')
      return 0;

   /* Don't forget to end our character arrays with a 0 byte 00000000 = 0x0 = 0. */
   s[i] = '\0';


   /* Return back the length of the line. */
   return i;
}

/* Function to copy one array to another. */
void copy(char to[], char from[])
{
   int i;

   i = 0;

   /* While we are not at the null terminator, keep going! */
   while ((to[i] = from[i]) != '\0')
      ++i;
}

/* Function to trim trailing white space (tabs and spaces) from a string. */
int trim_trailing_whitespace(char input[])
{
   int array_size, new_array_size, i;
   array_size = new_array_size = 0;

   for (i=0; input[i] != '\0'; ++i)
      ++array_size;

   new_array_size = array_size +1;

   /* Now we know how many chars the array contains.
    * count from end and if it is a space or tab then overwrite with 0
    * stop when we get to a real character.
    * This function works but needs to be cleaned up. Messy code! */
   for (i = array_size; i > 0; i--)
   {
      if (input[i] == '\0' || input[i] == '\n' || input[i] == '\t' || input[i] == ' ')
      {
         if (input[i] != '\n')
         {
            input[i] = '\0';
            new_array_size--;
         }
      }
      else
      {
         new_array_size = new_array_size + 2; /* add the newline we just put at the end */
         i = 0;
      }
         
   }

   return new_array_size;
}
