/****************************************************
 * Exercise 03.03 from the K&R book.
 * by Foo74 -- June 08, 2016
 *
 * A program that shows the expand() function which
 * that expands shorthand notation like a-z in the
 * string s1 into the equivalent complete list
 * abc...xyz in s2. The function allows for letters
 * of either case and digits and handles cases
 * like a-b-c, a-z0-9 and -a-z.
 *****************************************************/

/* Include the standard io library.*/
#include <stdio.h>

/* Define the vars we will use to test so we can
 * easily change them. 
 */
#define MAX 1024

/* Function that ...
 * s1:    the source string.
 * t2:    the dest string.
 */
void expand(char s1[], char s2[]);
