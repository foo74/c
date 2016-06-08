/****************************************************
* Exercise 02.08 from the K&R book.
* by Foo74 -- May 16, 2016
* A program that shows the rightrot() function. The
* rightrot() function is a bitwise function that takes
* in a series of bits and rotates them to the right them.
* For example, if 00011100 is the input and we want to
* rotate this 3 bits, the result will be 10000011.
*****************************************************/

/* Include the standard io library and standard ints.*/
#include <stdio.h>
#include "../foolib/print.h"

/* Define the vars we will use to test so we can
 * easily change them. Maybe want to have as input in future
 * or args to command line.
 */
#define X_BITS 0b00011100
#define N 3

/* Function that performs bitwise operations. It takes in x and n. 
 * It takes x and does a bitwise operation to rotate x number of bits.
 * For example, if 00011100 is the input and we want to
 * rotate this 3 bits, the result will be 10000011.
 *
 * We will use only 8 bits and unsigned to make it very easy to follow
 * how the function works. The function could be scaled up to a larger
 * bit variable.
 */
uint8_t rightrot(uint8_t , uint8_t);
