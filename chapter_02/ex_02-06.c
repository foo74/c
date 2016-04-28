/****************************************************
* Exercise 02.06 from the K&R book.
* by Foo74 -- April 28, 2016
* A program that shows the setbits function. The setbits
* function highlights the bitwise operators.
*****************************************************/

/* Include the standard io library and standard ints.*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */
uint8_t setbits(uint8_t , uint8_t , uint8_t , uint8_t );

/* The main function of our program. */
int main()
{
   uint8_t init_x;
   init_x = 0b11111111;

   printf("init_x: 0x%x\n\n", init_x);

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
   uint8_t y_bits;
   y_bits = 0;

   y_bits = y_bits << n;
   y_bits = y_bits >> n;

   /* If not found return -1. */
   return y_bits;
}
