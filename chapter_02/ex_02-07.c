/****************************************************
* Exercise 02.07 from the K&R book.
* by Ken Withee -- May 10, 2016
* A program that shows the invert() function. The
* invert() function is a bitwise function that takes
* in a series of bits and inverts them.
*****************************************************/

/* Include our main header file.*/
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

   /* Call our invert() function and save the result
    * in the post_x var. Remember that the second input
    * var to invert() is the position and the third is
    * the number of bits. See invert() for more details.
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
   uint8_t result1;
   uint8_t result2;
   uint8_t x_mask_left;
   uint8_t x_mask_right;
   uint8_t x_mask;
   uint8_t inverted_mask;
   uint8_t x_inverted;

   /* Initialize our variables so no surprises. */
   result = 0;
   result1 = 0;
   result2 = 0;
   x_mask_left = 0xff;
   x_mask_right = 0xff;
   x_mask = 0;
   x_inverted = 0;
   inverted_mask = 0;

   /* Get the mask for the left bits of x and also the mask for the
    * right bits of x. This is because we don't want to disturbe the
    * bits on the left side and right side of x that we are not inverting 
    * with the n bits starting at position p of
    * the x bits. So we need a mask for the left and right bits of x
    * from the original x input so we can put them back.
    */
   x_mask_left = x_mask_left >> p;
   x_mask_left = ~x_mask_left;
   x_mask_right = x_mask_right >> (n+p);
   x_mask = x_mask_left | x_mask_right;
   inverted_mask = ~x_mask;
   x_inverted = ~x;

   /* Build our result. First get the inverted of the entire x.
    * Then use the mask to get the bits we don't want to touch.
    * These are the bits to the left and the right. Then get the
    * inner bits which are inverted. Use the mask to pull from the
    * inverted of the entire x. Then do an OR to get any 1's in
    * both the bits we don't touch and the bits that are inverted.
    */
   result1 = x_mask & x;
   result2 = inverted_mask & x_inverted;
   result = result1 | result2;

   /* Return the bits. */
   return result;
}
