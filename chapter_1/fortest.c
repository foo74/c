#include <stdio.h>

int main()
{
   int i;

   for(i=0;i<5;i++)
      printf("in for, i=%d\n", i);

   for(i=0;i<5;++i)
      printf("in for, i=%d\n", i);

   return 0;
}
