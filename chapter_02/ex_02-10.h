/****************************************************
* Exercise 02.10 from the K&R book.
* by Foo74 -- May 18, 2016
*
* A program that demonstrates the lower() function
* which demonstrates the ternary operatior "?:". The
* ternary operate <exp1> ? <exp2> : <exp3> is like
* an if/else statement. If expression 1 is true then
* do expression 2. Otherwise do expression 3.
*****************************************************/

/* Include the standard io library and standard ints.*/
#include <stdio.h>
/*
#include "../foolib/print.h"
*/

/* Define the vars we will use to test so we can
 * easily change them. Maybe want to have as input in future
 * or args to command line.
#define X_BITS 0b11010100
 */

/* Function that takes in a char, and if it is upper case, converts
 * it to lower case. If it is already lower then just returns it.
 */
char lower(char);
