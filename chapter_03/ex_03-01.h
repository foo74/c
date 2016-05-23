/****************************************************
 * Exercise 03.01 from the K&R book.
 * by Foo74 -- May 20, 2016
 *
 * A program that demonstrates a binary search.
 *****************************************************/

/* Include the standard io library and time for measurements.*/
#include <stdio.h>
#include <time.h>

/* Define the vars we will use to test so we can
 * easily change them. Maybe want to have as input in future
 * or args to command line.
 * Note that anything larger than this overflows the stack.
 * I have tried increasing the stack, see linux_notes in
 * the worth_reading repo, and can increase a bit but maybe
 * I don't have enough RAM on this system so anything more 
 * overflows.
 */
#define MAX 0xfffff

/* Function that takes an int, an array of ints, and the
 * number of elements in the array.
 * x:    the int to find in the array.
 * v[]:  the array of ints.
 * n:    the number of elements in the array v[].
 *
 * The binsearch2() function uses a single test
 * inside the while loop instead of 2 tests.
 */
long int binsearch(long int x, long int v[], long int n);
long int binsearch2(long int x, long int v[], long int n);
