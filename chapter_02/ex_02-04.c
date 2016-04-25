/****************************************************
* Exercise 02.04 from the K&R book.
* by Foo74 -- April 25, 2016
* A program that will remove any chars contained in
* a string, s2, from the string s1.
*****************************************************/

/* Include the standard io library and limit definitions.
   We can find all these limits in /usr/include/limits.h */
#include <stdio.h>
#include <limits.h>

/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */
void squeeze(char [], char[]);

/* The main function of our program. */
int main()
{
   char a[6] = {'a', 'b', 'c', 'c', 'd', 0};
   char b[3] = {'c', 'b',  0};

   printf("Before function call...\n");
   printf("a = %s\n", a);
   printf("b = %s\n", b);
   squeeze(a, b);
   printf("After function call...\n");
   printf("a = %s\n", a);
   printf("b = %s\n", b);


   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* Function to remove any chars contained in s2 from s1.
 */
void squeeze(char s1[], char s2[])
{
   int i;
   int j;
   int place1;
   int place2;
   i = 0;
   j = 0;
   place1 = 0;
   place2 = 0;

   for (i=0; s1[i] != 0; i++)
   {
      for (j=0; s2[j] != 0; j++)
      {
         if (s1[i] == s2[j])
         {
            /* If there is only one char and it should be deleted. */
            if (s1[i+1] == 0)
            {
               s1[i] = 0;
            }
            else
            {
               /* Remove s1[i] and copy s[i+1] to the left until hit 0. */
               place1 = i;
               place2 = i+1;
               while (s1[place2] != 0)
                  s1[place1++] = s1[place2++];
               s1[place1] = 0;
               i = -1; /*reset i to start at beginning of string*/
            }
         }
      }
   }
}
