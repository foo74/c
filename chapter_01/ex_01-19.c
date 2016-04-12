/****************************************************
* Exercise 1.19 from the K&R book.
* by Foo74 -- March 24, 2016
*****************************************************/

/* Include the standard io library and define MAXLINE at 1000. */
#include <stdio.h>
#define MAXLINE 1000

/* Declare the functions, note don't need a variable name here,
 *  just the type. char arrays and int. 
 */
int mygetline(char [], int );
void copy(char [], char []);
void reverse_string(char []);
int sizeofstring(char s[]);

/* The main function of our program. */
int main()
{
   /* Declare length, max, and a couple of char arrays we will use. */
   int len, i;
   char line[MAXLINE];
 
   len = 0;
   for(i = 0; i < MAXLINE; i++)
      line[i] = '\0';

   /* Print some instructions for our users. */
   printf("\nType in some lines, I will reverse the order. Enter a '$' character to end.\n\n");

   /* While there is a line to get, if control-d then we will be 0. */
   while ((len = mygetline(line, MAXLINE)) > 0)
   {
      if (len >= MAXLINE-1)
         printf("\nThe line is too long! Max length is %d characters.\n", MAXLINE);

      reverse_string(line);
      printf("%s\n", line);
   }

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}

/* A function that takes in a char array and a limit and fills it. */
int mygetline(char s[], int lim)
{
   int c, i;

   /* For loop, while we are not end of file, while we are not end of line, and
    * while we are not the & character, push on. */
   for (i=0; (c=getchar()) != EOF && c!='\n' && c!='$'; ++i)
   {
      /* If I is less than 1000, which is size of our array, then set the char array. */
      if ( i < lim-1)
         s[i] = c;
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

/* Function to reverse a string. */
void reverse_string(char s[])
{
   /* Iterators and local array we will use to make the reverse. */
   int i, j;
   char s2[MAXLINE];

   /* Make a local copy that we will reverse. */
   copy(s2, s);

   /* Set j as the downward index. Subtract 2 because of the
    * ending \0 character and the \n character and the start
    * index of 0. Set i as upward index at 0. */
   for(i=0, j=sizeofstring(s)-2; j >= 0; j--, i++)
      s[i] = s2[j];
}


/* A simple function to return the number of chars in a char array. */
int sizeofstring(char s[])
{
   int i;

   /* Just loop through until we find the \0, which is the end. */
   for(i=0; s[i] != '\0'; i++);

   /* Return the number of chars we found before the \0. */
   return i;
}
