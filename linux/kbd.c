
#include <ncurses.h>
#include "../headers/kbd.h"

char sb_kbd_read()
{
  initscr();
  timeout(-1);
  char c = getch();
  endwin();
  return c;
}
