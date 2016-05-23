/****************************************************
* Exercise 03.01 from the K&R book.
* by Foo74 -- May 20, 2016
*****************************************************/

/* Include our main header file.*/
#include "ex_03-01.h"

/* The main function of our program. */
int main()
{
   long int i = 0;
   long int result = 0;
   long int x = 5;
   long int v[MAX];
   clock_t start, end;
   double cpu_time_used;

   /* Build the array with ascending integers. */
   for (i = 0; i < MAX; i++)
      v[i] = (long int)i;

   /* Print the header info. */
   printf("\n---------------------------------------------------------");
   printf("\n- Exercise 03.01 from, The C Programming Language,      -");
   printf("\n- by Brian W. Kernighan and Dennis M. Ritchie, 2nd Ed., -");
   printf("\n- AT&T Bell Laboratories (Prentice Hall - 1988).        -");   
   printf("\n---------------------------------------------------------\n\n");

   /* Print the info about this program. */
   printf("This program finds a value, x, in a sorted array, v[],\n");
   printf("with, n, elements. Array sorted in ascending order.\n\n");
   printf("x = %ld\n", x);
   printf("n = %d\n\n", MAX);
   printf("\n\n");

   /* binsearch() */
   /* Grab the clock. */
   start = clock();

   /* Run the search function. */
   result = binsearch(x, v, MAX);

   /* Grab the clock again. */
   end = clock();

   /* Subtract the end from the start to get the elapsed time.
    * then divide by the number of clocks per second on this
    * system to get the time in seconds.
    */
   cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

   /* Print out the results. */
   printf("Elapsed time: %f\n", cpu_time_used);
   if ( result != -1 )
      printf("Integer %ld found! Location is position %ld in array.\n\n", x, result);

   /* binsearch2() - see comments above*/
   start = clock();
   result = binsearch2(x, v, MAX);
   end = clock();
   cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
   printf("Elapsed time: %f\n", cpu_time_used);
   if ( result != -1 )
      printf("Integer %ld found! Location is position %ld in array.\n\n", x, result);

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* See header ex_03-01.h for description. */
long int binsearch(long int x, long int v[], long int n)
{
   long int low, high, mid;

   low = 0;
   high = n-1;
   while (low <= high)
   {
      mid = (low+high) / 2;
      if (x < v[mid])
         high = mid-1;
      else if (x > v[mid])
         low = mid+1;
      else
         return mid; /* found a match */
   }

   return -1; /* no match found */
}

/* See header ex_03-01.h for description. */
long int binsearch2(long int x, long int v[], long int n)
{
   long int low, high, mid;

   low = 0;
   high = n-1;
   mid = high / 2;

   while (low <= high && v[mid] != x)
   {
      mid = (low+high) / 2;
      if (x < v[mid])
         high = mid-1;
      else
         low = mid+1;
   }

   if ( v[mid] == x )
      return mid; /* match found */
   else
      return -1; /* no match found */
}
