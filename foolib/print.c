/****************************************************
* Simple util functions for the K&R book project.
* by Foo74 -- May 10, 2016
*****************************************************/

/* Include the standard io library and standard ints.*/
#include "print.h" 

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
