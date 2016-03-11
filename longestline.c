#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
int linelength(char line[]);

int main()
{
   int len, max;
   char line[MAXLINE];
   char longest[MAXLINE];
   int charsinline;

   max = charsinline = 0;

   while ((len = mygetline(line, MAXLINE)) > 0)
   {
      /*charsinline = linelength(line);*/
      printf("length is: %d", linelength(line));
      if (len > max)
      {
         max = len;
         copy(longest, line);
      }
   }
   if (max > 0)
      printf("%s", longest);
   return 0;
}

int mygetline(char s[], int lim)
{
   int c, i;

   for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
      s[i] = c;
   if (c == '\n')
   {
      s[i] = c;
      ++i;
   }
   s[i] = '\0';
   return i;
}

void copy(char to[], char from[])
{
   int i;
   i = 0;

   while ((to[i] = from[i]) != '\0')
      ++i;
}

int linelength(char s[])
{
   int length, c;
   length = c = 0;

   while (c=getchar() != EOF && c!='\n')
      ++length;

   return length;
}
