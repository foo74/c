#include <stdio.h>

#define START 0
#define MAX 100

main()
{
   int a;

   for ( a = START; a <= MAX; a++)
      printf("a: %2d--", a);

   printf("\n");
}
