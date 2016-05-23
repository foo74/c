/****************************************************
 * Exercise 03.01 from the K&R book.
 * by Foo74 -- May 20, 2016
 *
 * A program that demonstrates a binary search.
 *****************************************************/

/* Include the standard io library and time for measurements.*/
#include <stdio.h>
#include <time.h>
/*
#include "../kenlib/print.h"
*/

/* Define the vars we will use to test so we can
 * easily change them. Maybe want to have as input in future
 * or args to command line.
#define X_BITS 0b11010100
 */

/* Function that takes an int, an array of ints, and the
 * number of elements in the array.
 * x:    the int to find in the array.
 * v[]:  the array of ints.
 * n:    the number of elements in the array v[].
 *
 * The binsearch2() function uses a single test
 * inside the while loop instead of 2 tests.
 */
int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
