
#include "term.h"

void tsout(char* s)
{
	int c = 0;
	while ( s[c] != '\0' )
	{
		tout(s[c]);
		++c;
	}
}

void tout(char c)
{
	unsigned char *videoram = (unsigned char *) TERM_VIDEORAM_ADDRESS;

	int xPos = term_xPos(-1);
	int yPos = term_yPos(-1);

	videoram[((yPos * TERM_MAX_COLS) + xPos) * 2] = c;
	videoram[(((yPos * TERM_MAX_COLS) + xPos) * 2) + 1] = 0x1F;

	/* do we need to scroll? */
 
	if ( xPos < ( TERM_MAX_COLS - 1 ) )
	{
		term_xPos(++xPos);
	}
	else
	{
		term_xPos(0);
		if ( yPos == 24 )
		{
			int x, y;

			for ( x = 0 ; x < TERM_MAX_COLS ; ++x )
			{
				for ( y = 0 ; y < ( TERM_MAX_ROWS - 1 ) ; ++y )
				{
					videoram[((y * TERM_MAX_COLS) + x) * 2] = videoram[(((y + 1) * TERM_MAX_COLS) + x) * 2];
				        videoram[(((y * TERM_MAX_COLS) + x) * 2) + 1] = videoram[((((y + 1) * TERM_MAX_COLS) + x) * 2) + 1];
				}
			}
			for ( x = 0 ; x < TERM_MAX_COLS ; ++x )
			{
				y = ( TERM_MAX_ROWS - 1 );
				videoram[((y * TERM_MAX_COLS) + x) * 2] = ' ';
				videoram[(((y * TERM_MAX_COLS) + x) * 2) + 1] = 0x07;
			}
		}
		else
		{
			term_yPos(++yPos);
		}
	}
}

void term_clear()
{
	unsigned char *videoram = (unsigned char *) TERM_VIDEORAM_ADDRESS;

	term_xPos(0);
	term_yPos(0);

	int x,y;
	
	for ( x = 0 ; x < TERM_MAX_COLS ; ++x )
	{
		for ( y = 0 ; y < ( TERM_MAX_ROWS ) ; ++y )
		{
			videoram[((y * TERM_MAX_COLS) + x) * 2] = ' ';
			videoram[(((y * TERM_MAX_COLS) + x) * 2) + 1] = 0x07;
		}
	}
}

/* Positioning code */

int term_xPos(int newPos)
{
	static int curPos = 0;

	if ( newPos >= 0 && newPos < TERM_MAX_COLS )
	{
		curPos = newPos;
	}

	return curPos;
}

int term_yPos(int newPos)
{
        static int curPos = 0;

        if ( newPos >= 0 && newPos < TERM_MAX_ROWS )
        {
                curPos = newPos;
        }

	return curPos;
}

