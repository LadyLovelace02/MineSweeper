#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

//predefined values, may change to global constant that can be specified by user later on
#define NUM_MINES       40
#define GRID_LEN        16
#define TRUE            1
#define FALSE           0

#define FLAG            "F"
#define BOMB            "B"
#define HIDDEN          "-"

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
int isMine(char*[], int, int);
int isRevealed(char*[], int, int);
int isFlagged(char*[], int, int);
int numAdjMines(char*[], int, int);
void makeMine(char*[], int, int);
void reveal(char*[], int, int);
void flag(char*[], int, int);
int winCondition(char*[]);
void setUpGame(char**);
void freeGrid(char**);
void game();

//ui
int yOrN();
