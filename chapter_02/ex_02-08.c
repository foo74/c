/****************************************************
* Exercise 02.08 from the K&R book.
* by Foo74 -- May 16, 2016
* A program that shows the rightrot() function. The
* rightrot() function is a bitwise function that takes
* in a series of bits and rotates them to the right them.
* For example, if 00011100 is the input and we want to
* rotate this 3 bits, the result will be 10000011.
*****************************************************/

/* Include our main header file.*/
#include "ex_02-08.h"

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
   printf("\nn: %d\n\n", N);

   /* Call our rightrot() function and save the result
    * in the post_x var.
    */
   post_x = rightrot(X_BITS, N);

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

/* Function that performs bitwise operations. It takes in x and n. 
 * It takes x and does a bitwise operation to rotate x number of bits.
 * For example, if 00011100 is the input and we want to
 * rotate this 3 bits, the result will be 10000011.
 *
 * We will use only 8 bits and unsigned to make it very easy to follow
 * how the function works. The function could be scaled up to a larger
 * bit variable.
 */
uint8_t rightrot(uint8_t x, uint8_t n)
{
   /* Variables to use for manipulation of bits in our function. */
   uint8_t result;
   uint8_t shifted_bit;
   int i;

   /* Initialize our variables so no surprises. */
   result = x;
   shifted_bit = 0;
   i = 0;

   /* For as many times as we need to shift, save the right most
    * bit and then shift, then add the saved bit to the left most
    * because the shift adds a 0 but we want instead the right
    * most bit that was shifted off the right. In other words,
    * we want to 'rotate' like the bits are on a circle.
    */
   for (i = 0; i < n; i++)
   {
      /* Save the right most bit first. */
      shifted_bit = 0b00000001 & result;

      /* Shift 1 to the right which will pull in 0 into the left. */
      result = result >> 1;

      /* If the saved bit is a 1, add it back, if it was a 0 we are done. */
      if ( shifted_bit == 1 )
         result = result | 0b10000000;
   }

   /* Return the bits. */
   return result;
}

