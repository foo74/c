/****************************************************
* Exercise 02.07 from the K&R book.
* by Foo74 -- May 10, 2016
* A program that shows the invert() function. The
* invert() function is a bitwise function that takes
* in a series of bits and inverts them.
*****************************************************/

/* Include the standard io library and standard ints.*/
#include <stdio.h>
#include "../foolib/print.h"

/* Define the vars we will use to test setbits() so we can
 * easily change them. Maybe want to have as input in future
 * or args to command line.
 */
#define X_BITS 0b00000000
#define P 2
#define N 3

/* Function that performs bitwise operations. It takes in x, p, and n. 
 * It takes x and does a bitwise operation to set the n number of bits
 * that begin at position p to an inverted state. In other words, all
 * 0's become 1's and vice versa.
 * We will use only 8 bits and unsigned to make it very easy to follow
 * how the function works. The function could be scaled up to a larger
 * bit variable.
 */
uint8_t invert(uint8_t , uint8_t , uint8_t);
