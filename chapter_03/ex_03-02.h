/****************************************************
 * Exercise 03.02 from the K&R book.
 * by Foo74 -- May 25, 2016
 *
 * A program that demonstrates a switch statement.
 *****************************************************/

/* Include the standard io library.*/
#include <stdio.h>

/* Define the vars we will use to test so we can
 * easily change them. 
 */
#define MAX 1024

/* Function that takes two string pointers s and t. The t
 * is the destination and the s is the source. The function
 * converts newline and tabs into visible sequences \n and \t.
 * number of elements in the array.
 * s:    the source string.
 * t:    the dest string.
 */
void escape(char s[], char t[]);
