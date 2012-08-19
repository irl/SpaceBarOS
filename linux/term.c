
#include "../headers/term.h"
#include <ncurses.h>

void sb_tsout(char* s)
{
	int c = 0;
	while ( s[c] != '\0' )
	{
		sb_tout(s[c]);
		++c;
	}
}

void sb_tout(char c)
{
	if ( c == '\xC9' || c == '\xBB' || c == '\xBA' || c == '\xC8' || c == '\xCD' )
		c = '*';
	mvprintw(sb_term_yPos(-1), sb_term_xPos(-1), "%c", c);
	sb_term_xPos(sb_term_xPos(-1));
	refresh();
}

void sb_term_clear()
{
	erase();
}

/* Positioning code */

int sb_term_xPos(int newPos)
{
	static int curPos = 0;

	if ( newPos >= 0 && newPos < TERM_MAX_COLS )
	{
		curPos = newPos;
	}

	return curPos + 1;
}

int sb_term_yPos(int newPos)
{
        static int curPos = 0;

        if ( newPos >= 0 && newPos < TERM_MAX_ROWS )
        {
                curPos = newPos;
        }

	return curPos + 1;
}

