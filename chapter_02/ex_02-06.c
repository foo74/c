/****************************************************
* Exercise 02.06 from the K&R book.
* by Foo74 -- May 03, 2016
* A program that shows the setbits function. The setbits
* function highlights the bitwise operators.
*****************************************************/

/* Include the standard io library and standard ints.*/
#include <stdio.h>
#include <stdint.h>

/* Define the vars we will use to test setbits() so we can
 * easily change them. Maybe want to have as input in future
 * or args to command line.
 */
#define X_BITS 0b10000010
#define Y_BITS 0b01100101
#define P 2
#define N 3

/* Function that performs bitwise operations. It takes in x, p, n, and y.
 * It takes x and does a bitwise operation to set the n number of bits
 * that begin at position p to the rightmost n number of bits from y.
 * We will use only 8 bits and unsigned to make it very easy to follow
 * how the function works. The function could be scaled up to a larger
 * bit variable.
 */
uint8_t setbits(uint8_t , uint8_t , uint8_t , uint8_t );

/* A simple function to print in binary. */
void print_binary(uint8_t );

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
   printf("\ny:\t\t");
   print_binary(Y_BITS);
   printf("\np: %d\nn: %d\n\n", P, N);

   /* Call our setbits() function and save the result
    * in the post_x var. Remember that the second input
    * var to setbits() is the position and the third is
    * the number of bits. See setbits() for more details.
    */
   post_x = setbits(X_BITS, P, N, Y_BITS);

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

/* Function that performs bitwise operations. It takes in x, p, n, and y.
 * It takes x and does a bitwise operation to set the n number of bits
 * that begin at position p to the rightmost n number of bits from y.
 * We will use only 8 bits and unsigned to make it very easy to follow
 * how the function works. The function could be scaled up to a larger
 * bit variable.
 */
uint8_t setbits(uint8_t x, uint8_t p, uint8_t n, uint8_t y)
{
   /* Variables to use for manipulation of bits in our function. */
   uint8_t y_bits;
   uint8_t result;
   uint8_t x_mask_left;
   uint8_t x_mask_right;
   uint8_t x_mask;

   /* Initialize our variables so no surprises. */
   y_bits = 0;
   result = 0;
   x_mask_left = 0xff;
   x_mask_right = 0xff;
   x_mask = 0;

   /* Get the mask for the left bits of x and also the mask for the
    * right bits of x. This is because we don't want to disturbe the
    * bits on the left side and right side of x that we are not replacing
    * with the n bits from the right hand side of y and at position p of
    * the x bits. So we need a mask for the left and right bits of x
    * from the original x input so we can put them back.
    */
   x_mask_left = x_mask_left >> p;
   x_mask_left = ~x_mask_left;      /* turn to 1's left bits we keep */
   x_mask_right = x_mask_right >> (8-p);
   x_mask = x_mask_left | x_mask_right;

   /* Get the y bits from the right side of y. We only want to get
    * the n number of bits and we want all the bits to the left
    * to just be 0's.
    */
   y_bits = y << (8-n);
   y_bits = y_bits >> p;

   /* Build our result. First get the left and right bits of the 
    * original x bits. These are the ones we are not replacing
    * so we don't want to disturb the left and right originals.
    * Then do an OR to get the 1's in the middle. The left and
    * right sides of the y_bits will be zero since we did bit
    * shifting above. So we can do an OR to get the y_bits in
    * the middle and combine it with the result that we already 
    * built which has the original left and right sides of x.
    */
   result = x_mask & x;
   result = result | y_bits;

   /* Return the bits. */
   return result;
}

/* A simple function to print in binary. */
void print_binary(uint8_t print_me)
{
   /* i our iterator, max the size of the var, 
    * tracker used to reset for each bit printed.
    */
   int i;
   int max;
   uint8_t tracker;
   
   /* Initialize our variables. */
   i = 0;
   max = 0;
   tracker = 0;

   /* Set max to the number of bits total -1 since we start
    * from a position of 0.
    */
   max = ((sizeof(print_me) * 8) - 1);

   /* Prefix with 0b so it is clear it is binary. */
   printf("0b");

   /* For however many bits this var has, loop through
    * and shift the bits left to get one bit, then back
    * to the right to set it at the right most position.
    * Then print it.
    */
   for (i=0; i<=max; i++)
   {
      tracker = print_me;
      tracker = tracker << i;
      tracker = tracker >> max;
      printf("%x", tracker);
   }
}
