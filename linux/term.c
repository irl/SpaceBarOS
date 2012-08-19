
#include "../headers/term.h"
#include <stdio.h>

#define esc 27

#define cls printf("%c[2J",esc)

#define pos(row,col) printf("%c[%d;%dH",esc,row,col)

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
	putchar(c);
}

void sb_term_clear()
{
	cls;
}

/* Positioning code */

int sb_term_xPos(int newPos)
{
	static int curPos = 0;

	if ( newPos >= 0 && newPos < TERM_MAX_COLS )
	{
		curPos = newPos;
		pos(curPos,sb_term_yPos(-1));
	}

	return curPos;
}

int sb_term_yPos(int newPos)
{
        static int curPos = 0;

        if ( newPos >= 0 && newPos < TERM_MAX_ROWS )
        {
                curPos = newPos;
		pos(sb_term_xPos(-1),curPos);
        }

	return curPos;
}

