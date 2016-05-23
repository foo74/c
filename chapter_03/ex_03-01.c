/****************************************************
* Exercise 03.01 from the K&R book.
* by Foo74 -- May 20, 2016
*****************************************************/

/* Include our main header file.*/
#include "ex_03-01.h"

/* The main function of our program. */
int main()
{
   int i = 0;
   int result = 0;
   int x = 5;
   int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int n = 10;
   clock_t start, end;
   double cpu_time_used;

   printf("\n---------------------------------------------------------");
   printf("\n- Exercise 03.01 from, The C Programming Language,      -");
   printf("\n- by Brian W. Kernighan and Dennis M. Ritchie, 2nd Ed., -");
   printf("\n- AT&T Bell Laboratories (Prentice Hall - 1988).        -");   
   printf("\n---------------------------------------------------------\n\n");

   printf("This program finds a value, x, in a sorted array, v[],\n");
   printf("with, n, elements. Array sorted in ascending order.\n\n");

   printf("x = %d\n", x);
   printf("n = %d\n\n", n);
   for( i=0; i<n; i++)
      printf("v[%d] = %d\n", i, v[i]); 
   printf("\n\n");

   /* binsearch() */
   start = clock();
   result = binsearch(x, v, n);
   end = clock();
   cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
   printf("Elapsed time: %f\n", cpu_time_used);
   if ( result != -1 )
      printf("Integer %d found! Location is position %d in array.\n\n", x, result);

   /* binsearch2() */
   start = clock();
   result = binsearch2(x, v, n);
   end = clock();
   cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
   printf("Elapsed time: %f\n", cpu_time_used);
   if ( result != -1 )
      printf("Integer %d found! Location is position %d in array.\n\n", x, result);

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* See header ex_03-01.h for description. */
int binsearch(int x, int v[], int n)
{
   int low, high, mid;

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
int binsearch2(int x, int v[], int n)
{
   int low, high, mid;

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
