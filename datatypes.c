/************************************************************************
 * A simple program to show the size of the 4 basic data types in C as
 * they are on the architecture where the program is run and compiled.
 * by Foo74, March 22, 2016
 ************************************************************************/
#include <stdio.h>

int main()
{

   /**********************************************************************
    * There are only 4 basic data types in C. These are:
    * char - a single byte to hold one character.
    * int - an integer reflecting the natural size on this architecture.
    * float - single-precision floating point.
    * double - double-precision floating point.
    **********************************************************************/
   printf("\n\n********************************************************************\n");
   printf("There are only 4 basic data types in C. These are:\n");
   printf("char - a single byte to hold on character.\n");
   printf("int - an integer reflecting the natural size on this architecture.\n");
   printf("float - single-precision floating point.\n");
   printf("double - double-precision floating point.\n");
   printf("*********************************************************************\n\n");
   char a;
   int b;
   float c;
   double d;

   printf("On this computer, the size of these data types is:\n");
   printf("char:\t%zu bytes\n", sizeof(a));
   printf("int:\t%zu bytes\n", sizeof(b));
   printf("float:\t%zu bytes\n", sizeof(c));
   printf("double:\t%zu bytes\n\n", sizeof(d));

   /**********************************************************************
    * In addition, there are two qualifiers, short and long. These can
    * be both be applied to int and long can be applied to double.
    * short - Half the size of an int. If int is 4 bytes, short int is 2.
    * long - Twice the size of an int. If int is 4 bytes, long int is 8.
    **********************************************************************/
   printf("\n\n********************************************************************\n");
   printf("In addition, there are two qualifiers, short and long. These can\n");
   printf("be both be applied to int and long can be applied to double.\n");
   printf("short - Half the size of an int. If int is 4 bytes, short int is 2.\n");
   printf("long - Twice the size of an int. If int is 4 bytes, long int is 8.\n");
   printf("*********************************************************************\n\n");
   short int e;
   long int f;
   long double g;

   printf("On this computer, the size of these modified types is:\n");
   printf("int:\t\t%zu bytes\n", sizeof(b));
   printf("short int:\t%zu bytes\n", sizeof(e));
   printf("long int:\t%zu bytes\n\n", sizeof(f));
   printf("double:\t\t%zu bytes\n", sizeof(d));
   printf("long double:\t%zu bytes\n\n", sizeof(g));

   return 0;
}
