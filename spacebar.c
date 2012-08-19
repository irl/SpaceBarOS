
#include "headers/term.h"
#include "headers/kbd.h"
#include "headers/io.h"
#include "headers/string.h"

void spacebar()
{
	unsigned int sbcount = 0;
	int sbpaused = 0;	

	sb_term_clear();

	int c,d;

	sb_tout('\xC9');
	for ( c = 1 ; c < ( TERM_MAX_COLS - 1 ) ; ++c ) { sb_tout('\xCD'); }
	sb_tout('\xBB');

	for ( d = 1 ; d < ( TERM_MAX_ROWS - 3 ) ; ++d )
	{
		sb_tout('\xBA');
		for ( c = 1 ; c < ( TERM_MAX_COLS - 1 ) ; ++c ) { sb_tout(' '); }
		sb_tout('\xBA');
	}

	sb_tout('\xCC');
	for ( c = 1 ; c < ( TERM_MAX_COLS - 1 ) ; ++c ) { sb_tout('\xCD'); }
	sb_tout('\xB9');

	sb_tout('\xBA');
	sb_tsout("Monitoring...");
	for ( c = 1 ; c < ( TERM_MAX_COLS - 14 ) ; ++c ) { sb_tout(' '); }
	sb_tout('\xBA');

        sb_tout('\xC8');
        for ( c = 1 ; c < ( TERM_MAX_COLS - 1 ) ; ++c ) { sb_tout('\xCD'); }
        
	sb_term_xPos( ( TERM_MAX_COLS - 10 ) / 2 );
	sb_term_yPos(1);

	sb_tsout("SpaceBarOS");

	while ( sb_kbd_read() == 32 ); /* Do not count from login */

	for (;;)
	{

		if ( sb_kbd_read() == 'p' ||
                      sb_kbd_read() == 'P' )
		{
			while ( sb_kbd_read() == 'p' ||
				sb_kbd_read() == 'P' ); /* wait for release */

			sbpaused ^= 1;
		}


		sb_term_xPos(4);
		sb_term_yPos(4);
 		if ( sb_kbd_read() == 32 )
		{
			sb_tsout("Spacebar is: [ DOWN ]");
			while ( sb_kbd_read() == 32 ); /* wait for release */
			if ( ! sbpaused )
				++sbcount;
		}
		else
		{
			sb_tsout("Spacebar is: [  UP  ]");
		}

		sb_term_xPos(4);
		sb_term_yPos(6);

		char sbcounts[255]; /* allocate 255 bytes */

		sb_itoa(sbcounts, 'd', sbcount);
		sb_tsout("Spacebar has been used ");
		sb_tsout(sbcounts);
		sb_tsout(" times in this session.");

		sb_term_xPos(1);
		sb_term_yPos(23);

		if ( sbpaused )
			sb_tsout("Paused.      ");
		else
			sb_tsout("Monitoring...");
	}
	
}
