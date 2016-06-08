/****************************************************
* Exercise 02.09 from the K&R book.
* by Foo74 -- May 19, 2016
* In a two's complement number system, x &= (x-1) deletes
* the right most 1 bit in x because of the way the sign
* influences the bits. 
* Example: For a 3 bit variable that uses 2's complement.
* 011 is 3
* 010 is 2
* 001 is 1
* 000 is 0
* 111 is -1
* 110 is -2
* 101 is -3
* 100 is -4
*
* So as you subtract 1 from the number you are counting
* down for positive numbers and then when you get to 0
* the bits switch to all 1's which is -1 and then the bits
* start subtracting 1 as the variable goes negative. So
* as you subtract 1 you are are moving the digits in a 
* way that appears to be counting up for negative numbers.
* The result is that when you do an AND (&) operation with
* x and x-1 you are removing the right most 1 bit.
*
* A program that uses this concept to make a faster bitcount
* function is demonstrated here.
*****************************************************/

/* Include the standard io library and standard ints.*/
#include <stdio.h>
#include "../foolib/print.h"

/* Define the vars we will use to test so we can
 * easily change them. Maybe want to have as input in future
 * or args to command line.
 */
#define X_BITS 0b11010100

/* Function that takes a signed 2's complement 8 bit variable
 * and counts the number of bits that are 1. 
 */
int8_t bitcount(int8_t);
