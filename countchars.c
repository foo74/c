#include <stdio.h>

main()
{
   int c, i, j, nwhite, nother;
   int ndigit[10], nchars[26];

   nwhite = nother = 0;
   for (i = 0; i < 10; i++)
      ndigit[i] = 0;
   for (i = 0; i < 26; i++)
      nchars[i] = 0;

   while ((c = getchar()) != EOF)
      if (c >= '0' && c <= '9')
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
      printf("\n");
   }

   for (i = 0; i < 26; i++)
   {
      printf("%c = ", i + 'a');
      for (j = 0; j < nchars[i]; j++)
         printf("-");
      printf("\n");
   }
}
