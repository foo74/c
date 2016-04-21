/****************************************************
* Exercise 02.03 from the K&R book.
* by Foo74 -- April 19, 2016
* A program that converts a string of hex to integer.
*****************************************************/

/* Include the standard io library and math for pow(). 
 * I also am a fan of clearly defined bit lengths for
 * vars so I like to use stdint.h (which is a subset
 * of the inttypes.h). uint32_t is always 32 bits
 * regardless of platform. 
 */
#include <stdio.h>
#include <math.h>
#include <stdint.h>

/* The max chars we will convert is an array of 8. */
#define MAX_STRING 8

/* Declare functions:
 * 
 * Note: no need to declare a name here, the declare only needs data types of args.
 */

/* Takes in a char array of hex characters and returns the value in
 * hex. The function can accomodate 0x and 0X at the beginning or
 * the lack thereof. Valid hex is 0-9, a-f, and A-F.
 */
uint32_t htoi(char []);

/* The main function of our program. */
int main()
{
   /* Declare local variables to the main function. */
   int i;
   char a[MAX_STRING];

   /* Init variables. */
   for (i=0; i<MAX_STRING; i++)
      a[i] = 0; 

   /* Define the string of hex. Can start with 0x or 0X. */
   a[0] = '0';
   a[1] = 'x';
   a[2] = '5';
   a[3] = 'b';
   a[4] = 'f';
   a[5] = 'c';
   a[6] = 'd';
   a[7] = 'a';

   /* Print some instructions for our users. */
   printf("\nConvert a hex string to integer (8 characters max).\n\n");
   for (i=0; i<MAX_STRING && a[i] != 0; i++)
      printf("%c", a[i]);
   printf(" in hex is %u in decimal.\n\n", htoi(a));

   /* Be a good main function and return 0 because all went fine. */
   return 0;
}


/* Our functions are defined below here. We could also put them 
 * in their own files and link them together or #include them.
 */

/* Function to convert a string of hex to integers.
 * Note that C passes args in by value. Except in the
 * case of arrays in which case a pointer to the start
 * of the array is passed. We can accept the hex in the
 * form of 0x<value> or 0X<value> or <value>  where <value> 
 * is a char between '0' to '9' and 'a' to 'f' or 'A' and
 * 'F'. For example. these are valid: a A 0xa 0Xa 0xA 0XA, etc
 * A valid string example is 0xA5aBa9, or 0Xa5aBa9, or a5aBa9.
 */
uint32_t htoi(char s[])
{
   /* Declare i as iterator, power as the power for each significance
    * of digit, total as the running decimal total, last_digit as the
    * last digit in the string (least significant digit). 
    */
   int i;
   int power;
   uint32_t total;
   int last_digit;
   i = 0;
   total = 0;
   power = 0;

   /* Check if starts with 0x or 0X. */
   if (s[1] == 'x' || s[1] == 'X')
      last_digit = 2;
   else
      last_digit = 0;

   /* Loop through each character starting from the right so
    * we can find the least significant digit and then increment
    * our power variable as we go to the next significant digit
    * which is a power of 16 since we are using base 16 hexidecimal.
    */
   for (i=MAX_STRING-1; i>=last_digit; i--)
   {
      /* If a value is 0 then it is not part of the number. 
       * Only process non zero values. 
       */
      if (s[i] != 0)
      {
         /* If the char value is between the ascii value for the
          * '0' chararacter and the ascii value for the '9' character
          * then process it here, otherwise the same for A-F and a-f 
          * below in else/if's.
          */
         if (s[i] >= '0' && s[i] <= '9')
         {
            /* If we are greater than power of 0 then process it. 
             * Power of 0 is a special case because anything to the
             * power of 0 is 0. 
             */
            if (power > 0)
               total = total + ((s[i] - 48) * pow(16, power++));
            else
            {
               total = total + (s[i] - 48);
               power++;
            }
         }
         else if (s[i] >= 'A' && s[i] <= 'F')
         {
            if (power > 0)
               total = total + ((s[i] - 55) * pow(16, power++));
            else
            {
               total = total + (s[i] - 55);
               power++;
            }
         }
         else if (s[i] >= 'a' && s[i] <= 'f')
         {
            if (power > 0)
               total = total + ((s[i] - 87) * pow(16, power++));
            else
            {
               total = total + (s[i] - 87);
               power++;
            }
         }
      }
   }

   /* Return the total in decimal. Unsigned. */
   return total;
}
