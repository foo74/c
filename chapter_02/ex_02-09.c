/****************************************************
* Exercise 02.09 from the K&R book.
* by Foo74 -- May 17, 2016
*****************************************************/

/* Include our main header file.*/
#include "ex_02-09.h"

/* The main function of our program. */
int main()
{
   /* Our variables we store the result in. */
   int8_t post_x;

   /* Initialize to 0 so we are sure there is no garbage. */
   post_x = 0;

   /* Print out the bits before we call our function. */
   printf("\n\nx:\t\t");
   print_binary(X_BITS);

   /* Call our rightrot() function and save the result
    * in the post_x var.
    */
   post_x = bitcount(X_BITS);

   /* Print out the bits after we call our function. */
   printf("\n\nresult:\t\t");
   print_binary(post_x);
   printf("\n\n");

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* Function that performs bitwise operations. It takes in x and n. 
 * It takes x and does a bitwise operation to rotate x number of bits.
 * For example, if 00011100 is the input and we want to
 * rotate this 3 bits, the result will be 10000011.
 *
 * We will use only 8 bits and unsigned to make it very easy to follow
 * how the function works. The function could be scaled up to a larger
 * bit variable.
 */
int8_t bitcount(int8_t x)
{
   return x &= (x-1);
}
