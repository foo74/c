/****************************************************
* Exercise 02.05 from the K&R book.
* by Foo74 -- April 26, 2016
* A program that will demonstrate the any() function
* which takes two char arrays and and returns the
* first location of any char in s1 that is in s2.
*****************************************************/

/* Include the standard io library and limit definitions.*/
#include <stdio.h>

/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */
int any(char [], char[]);

/* The main function of our program. */
int main()
{
   /* 2 arrays for testing. First array has some chars. The second
    * array has the chars that we want to find from the first array.
    */
   char a[6] = {'a', 'x', 'c', 'c', 'r', 0};
   char b[3] = {'d', 'x', 0};
   int result;
   result = 0;

   /* Print some info, call the any() function, then show the result. */
   printf("Here are the chars I am searching:\t\t%s\n", a);
   printf("I am looking for any occurance of these:\t%s\n\n", b);

   /* Store the result. If a char is found print the position. Otherwise
    * print that we didn't find any matches.
    */
   result = any(a, b);
   if (result != -1)
      printf("Found char in element %d.\n\n", result+1);
   else
      printf("No matching chars found.\n\n");

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* Function that returns the first occurance of any char in
 * s2 that appears in s1. Returns -1 if nothing found.
 */
int any(char s1[], char s2[])
{
   /* The iterators we will use to loop through both arrays. */
   int i;
   int j;

   /* Set everything to 0 so no surprises. */
   i = 0;
   j = 0;

   /* For each element in the s1 array, as long as we don't get to 0. */
   for (i=0; s1[i] != 0; i++)
      /* For each element in the s2 array, as long as we don't get to 0. */
      for (j=0; s2[j] != 0; j++)
         /* If there is a char in s1 that matches the delete char in s2. */
         if (s1[i] == s2[j])
            return i;

   /* If not found return -1. */
   return -1;
}
