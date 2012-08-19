
#include <ncurses.h>
#include "../headers/kbd.h"

char sb_kbd_read()
{
  return getch();
}
