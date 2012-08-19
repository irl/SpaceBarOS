
#include "../headers/term.h"
#include "../headers/kbd.h"
#include "../headers/io.h"
#include "../headers/string.h"

void kmain( void* mbd, unsigned int magic )
{
	if ( magic != 0x2BADB002 )
	{
		sb_tsout("Something terrible has happened. Oh dear.");
		sb_tsout(" The multiboot magic number was incorrect.");
		for (;;);
	}
 
	char * boot_loader_name =(char*) ((long*)mbd)[16];

	sb_term_clear();
	sb_tsout("SpaceBarOS v0.1");
	sb_term_xPos(0);
	sb_term_yPos(1);
	sb_tsout("Loaded by ");
	sb_tsout(boot_loader_name);
	sb_term_xPos(0);
	sb_term_yPos(2);
        sb_tsout("Press the spacebar to login.");

	while ( sb_kbd_read() != 32 );

	spacebar();
}
