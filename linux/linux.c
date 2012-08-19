
#include <ncurses.h>

int main(int argc, char** argv)
{
	initscr();					/* Start curses mode 		*/
	raw();						/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();					/* Don't echo() while we do getch */
	timeout(10);				/* Don't block on getch */

	spacebar();
}

