#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <curses.h>

//predefined values, may change to global constant that can be specified by user later on
#define NUM_MINES       40
#define GRID_LEN        16
#define TRUE            1
#define FALSE           0

/* grid byte meaning key
 * 11111111
 * ^            is revealed
 *  ^           is mine
 *   ^          is flagged
 *    ^^^^      num adj mines
 *        ^     spare bit
 */

// main
void intro();
//logic
void setUpGame();

//ui
int yOrN();
