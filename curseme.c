#include <stdio.h>
#include <ncurses.h>

main()
{
   initscr();
   printw("Hello world!\n\nHello\n\n\n\n\find me\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tover here!");
   refresh();
   getch();
   endwin();
}
