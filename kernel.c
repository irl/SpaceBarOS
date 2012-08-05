
#include "term.h"
#include "kbd.h"
#include "io.h"
#include "string.h"

void kmain( void* mbd, unsigned int magic )
{
	if ( magic != 0x2BADB002 )
	{
		tsout("Something terrible has happened. Oh dear.");
		tsout(" The multiboot magic number was incorrect.");
		for (;;);
	}
 
	char * boot_loader_name =(char*) ((long*)mbd)[16];

	term_clear();
	tsout("SpaceBarOS v0.1");
	term_xPos(0);
	term_yPos(1);
	tsout("Loaded by ");
	tsout(boot_loader_name);
	term_xPos(0);
	term_yPos(2);
        tsout("Press the spacebar to login.");

	while ( kbd_read() != 32 );

        term_clear();

	int c,d;

	tout('\xC9');
	for ( c = 1 ; c < ( TERM_MAX_COLS - 1 ) ; ++c ) { tout('\xCD'); }
	tout('\xBB');

	for ( d = 1 ; d < ( TERM_MAX_ROWS - 3 ) ; ++d )
	{
		tout('\xBA');
		for ( c = 1 ; c < ( TERM_MAX_COLS - 1 ) ; ++c ) { tout(' '); }
		tout('\xBA');
	}

	tout('\xCC');
	for ( c = 1 ; c < ( TERM_MAX_COLS - 1 ) ; ++c ) { tout('\xCD'); }
	tout('\xB9');

	tout('\xBA');
	tsout("Monitoring...");
	for ( c = 1 ; c < ( TERM_MAX_COLS - 14 ) ; ++c ) { tout(' '); }
	tout('\xBA');

        tout('\xC8');
        for ( c = 1 ; c < ( TERM_MAX_COLS - 1 ) ; ++c ) { tout('\xCD'); }
        
	term_xPos( ( TERM_MAX_COLS - 10 ) / 2 );
	term_yPos(1);

	tsout("SpaceBarOS");

	while ( kbd_read() == 32 ); /* Do not count from login */

	for (;;)
	{
		unsigned int sbcount;


		term_xPos(4);
		term_yPos(4);
 		if ( kbd_read() == 32 )
		{
			tsout("Spacebar is: [ DOWN ]");
			while ( kbd_read() == 32 ); /* wait for release */
			++sbcount;
		}
		else
		{
			tsout("Spacebar is: [  UP  ]");
		}

		term_xPos(4);
		term_yPos(6);

		char* sbcounts = "          "; /* allocate 10 bytes */

		itoa(sbcounts, 'd', sbcount);
		tsout("Spacebar has been used ");
		tsout(sbcounts);
		tsout(" times in this session.");
	}
}
