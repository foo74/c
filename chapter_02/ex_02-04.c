/****************************************************
* Exercise 02.04 from the K&R book.
* by Foo74 -- April 25, 2016
* A program that will remove any chars contained in
* a string, s2, from the string s1.
*****************************************************/

/* Include the standard io library.*/
#include <stdio.h>

/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */
void squeeze(char [], char[]);

/* The main function of our program. */
int main()
{
   /* 2 arrays for testing. First array has some chars. The second
    * array has the chars that we want to delete from the first array.
    */
   char a[6] = {'a', 'b', 'c', 'c', 'd', 0};
   char b[3] = {'c', 'b', 0};

   /* Print some info, call the squeeze() function, then show the result. */
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
   /* The iterators we will use to loop through both arrays. */
   int i;
   int j;

   /* The place holders we will use to delete elements. */
   int place1;
   int place2;

   /* Set everything to 0 so no surprises. */
   i = 0;
   j = 0;
   place1 = 0;
   place2 = 0;

   /* For each element in the s1 array, as long as we don't get to 0. */
   for (i=0; s1[i] != 0; i++)
   {
      /* For each element in the s2 array, as long as we don't get to 0. */
      for (j=0; s2[j] != 0; j++)
      {
         /* If there is a char in s1 that matches the delete char in s2. */
         if (s1[i] == s2[j])
         {
            /* If there is only one char and it should be deleted. */
            if (s1[i+1] == 0)
            {
               s1[i] = 0;
            }
            /* Else delete the char and move all the elements to fill in. */
            else
            {
               /* Remove s1[i] and copy s[i+1] to the left until hit 0. */
               place1 = i;
               place2 = i+1;
               while (s1[place2] != 0)
                  s1[place1++] = s1[place2++];
               s1[place1] = 0;

               /*reset i to start at beginning of string*/
               i = -1;
            }
         }
      }
   }
}
