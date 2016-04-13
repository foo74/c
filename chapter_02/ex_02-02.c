#include <stdio.h>

#define lim 100

int main()
{

   int i;
   char s[lim];
   char c;
   void print_string(char *s);

   for (i=0; i<lim; i++)
      s[i] = 0;

   printf("\nEnter a string, I will repeat it.\n\n");

   /* turn for loop into a while loop without && and || */
   for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
      s[i] = c;

   printf("\nYou entered: ");
   print_string(s);

   printf("\n\nNow enter it again and I will use a different loop...\n\n");
   
   for (i=0; i<lim; i++)
      s[i] = 0;

   for (i=0; i<lim-1; i++)
   {
      c=getchar();
      if (c == '\n')
         i = lim;
      else if (c == EOF)
         i = lim;
      else
         s[i] = c;
   }

   printf("\nYou entered: ");
   print_string(s);

   return 0;
}


void print_string(char *s)
{
   int i;
   for (i=0; s[i] != 0; i++)
      printf("%c", s[i]);
   printf("\n\n");
}
