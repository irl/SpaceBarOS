
#ifndef _TERM_H
#define _TERM_H

#define TERM_MAX_ROWS 25
#define TERM_MAX_COLS 80

#define TERM_VIDEORAM_ADDRESS 0xb8000

/* More complex IO */

void tsout(char* s);

/* Basic IO */

void tout(char c);
void term_clear();

/* Positioning */

int term_xPos(int newPos);
int term_yPos(int newPos);

#endif

