/****************************************************
* Exercise 01.13 from the K&R book.
* by Foo74 -- April 11, 2016
*****************************************************/

#include <stdio.h>

int main()
{
   int c, i, j, k, nwhite, nother;
   int ndigit[10], nchars[26];

   nwhite = nother = 0;

   /* Set the arrays to all 0. */
   for (i = 0; i < 10; i++)
      ndigit[i] = 0;
   for (i = 0; i < 26; i++)
      nchars[i] = 0;

   printf("Enter some lines of text, I will tally the results. Enter $ to break. \n\n");

   /* while we are not at EOF, tally. */
   while ((c = getchar()) != EOF)
      if (c == '$')
         break;
      else if (c >= '0' && c <= '9')
         ++ndigit[c-'0'];
      else if (c >= 'a' && c <= 'z')
         ++nchars[c-'a'];
      else if (c == ' ' || c == '\n' || c == '\t')
         ++nwhite;
      else
         ++nother;

   printf("digits = ");
   for (i = 0; i < 10; i++)
      printf(" %d", ndigit[i]);
   printf(", white space = %d, other = %d\n", nwhite, nother);

   printf("\n\n and now here is a histogram of it...\n\n");

   for (i = 0; i < 10; i++)
   {
      printf("%d = ", i);

      for (j = 0; j < ndigit[i]; j++)
         printf("-");
      if (i % 2 == 0)
      {
         /* Pad with spaces so everything lines up. */
         for (k = 0; k < 50-ndigit[i]; k++)
            printf(" "); 
      }
      else
         printf("\n");
   }

   printf("\n\n");

   for (i = 0; i < 26; i++)
   {
      printf("%c = ", i + 'a');

      for (j = 0; j < nchars[i]; j++)
         printf("-");
      if (i % 2 == 0)
      {
         /* Pad with spaces so everything lines up. */
         for (k = 0; k < 50-nchars[i]; k++)
            printf(" "); 
      }
      else
         printf("\n");
   }

   return 0;
}
