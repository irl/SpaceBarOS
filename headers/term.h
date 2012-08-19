
#ifndef _TERM_H
#define _TERM_H

#define TERM_MAX_ROWS 25
#define TERM_MAX_COLS 80

#define TERM_VIDEORAM_ADDRESS 0xb8000

/* More complex IO */

void sb_tsout(char* s);

/* Basic IO */

void sb_tout(char c);
void sb_term_clear();

/* Positioning */

int sb_term_xPos(int newPos);
int sb_term_yPos(int newPos);

#endif

