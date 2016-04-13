#include <stdio.h>

int main()
{
   int year = 0;

   printf("Enter a year: ");
   scanf("%d", &year);

   if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
      printf("\n%d IS a leap year.\n", year);
   else
      printf("\n%d IS NOT a leap year.\n", year);

   return 0;
}
