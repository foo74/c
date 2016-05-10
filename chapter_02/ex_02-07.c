/****************************************************
* Exercise 02.07 from the K&R book.
* by Foo74 -- May 10, 2016
* A program that shows the invert() function. The
* invert() function is a bitwise function that takes
* in a series of bits and inverts them.
*****************************************************/

/* Include the standard io library and standard ints.*/
#include "ex_02-07.h"

/* The main function of our program. */
int main()
{
   /* Our variables we store the result in. */
   uint8_t post_x;

   /* Initialize to 0 so we are sure there is no garbage. */
   post_x = 0;

   /* Print out the bits before we call our function. */
   printf("\n\nx:\t\t");
   print_binary(X_BITS);
   printf("\np: %d\nn: %d\n\n", P, N);

   /* Call our setbits() function and save the result
    * in the post_x var. Remember that the second input
    * var to setbits() is the position and the third is
    * the number of bits. See setbits() for more details.
    */
   post_x = invert(X_BITS, P, N);

   /* Print out the bits after we call our function. */
   printf("result:\t\t");
   print_binary(post_x);
   printf("\n\n");

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* Function that performs bitwise operations. It takes in x, p, and n. 
 * It takes x and does a bitwise operation to set the n number of bits
 * that begin at position p to an inverted state. In other words, all
 * 0's become 1's and vice versa.
 * We will use only 8 bits and unsigned to make it very easy to follow
 * how the function works. The function could be scaled up to a larger
 * bit variable.
 */
uint8_t invert(uint8_t x, uint8_t p, uint8_t n)
{
   /* Variables to use for manipulation of bits in our function. */
   uint8_t result;
/*
   uint8_t y_bits;
   uint8_t x_mask_left;
   uint8_t x_mask_right;
   uint8_t x_mask;
*/

   /* Initialize our variables so no surprises. */
   result = 0;
/*
   y_bits = 0;
   x_mask_left = 0xff;
   x_mask_right = 0xff;
   x_mask = 0;
*/

   /* Get the mask for the left bits of x and also the mask for the
    * right bits of x. This is because we don't want to disturbe the
    * bits on the left side and right side of x that we are not replacing
    * with the n bits from the right hand side of y and at position p of
    * the x bits. So we need a mask for the left and right bits of x
    * from the original x input so we can put them back.
   x_mask_left = x_mask_left >> p;
   x_mask_left = ~x_mask_left;
   x_mask_right = x_mask_right >> (8-p);
   x_mask = x_mask_left | x_mask_right;
    */

   /* Get the y bits from the right side of y. We only want to get
    * the n number of bits and we want all the bits to the left
    * to just be 0's.
   y_bits = y << (8-n);
   y_bits = y_bits >> p;
    */

   /* Build our result. First get the left and right bits of the 
    * original x bits. These are the ones we are not replacing
    * so we don't want to disturb the left and right originals.
    * Then do an OR to get the 1's in the middle. The left and
    * right sides of the y_bits will be zero since we did bit
    * shifting above. So we can do an OR to get the y_bits in
    * the middle and combine it with the result that we already 
    * built which has the original left and right sides of x.
   result = x_mask & x;
   result = result | y_bits;
    */

   /* Return the bits. */
   return result;
}
