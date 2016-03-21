#include <stdio.h>

int convertCtoF(int);
int convertFtoC(int);

int main()
{
   float fahr, celsius;
   int lower, upper, step;

   lower = 0;
   upper = 300;
   step = 20;

   fahr = lower;

   printf("Fahrenheit\tCelcius\n");
   while ( fahr <= upper )
   {
      celsius = convertFtoC(fahr);
      printf("%10.0f\t%7.1f\n", fahr, celsius);
      fahr = fahr + step;
   }

   celsius = lower;

   printf("   Celsius   Fahrenheit\n");
   while ( celsius <= upper )
   {
      fahr = convertCtoF(celsius);
      printf("%10.0f\t%7.0f\n", celsius, fahr);
      celsius = celsius + step;
   }

   return 0;
}

int convertCtoF(int c)
{
   int f;
   f = 0;

   f = c * (9.0/5.0) + 32;
   return f;
}

int convertFtoC(int f)
{
   int c;
   c = 0;

   c = (5.0/9.0) * (f-32.0);
   return c;
}
