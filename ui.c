#include "defs.h"

int yOrN() {
    printf("(y/n): ");
    char input;
    int repeat = 0;
    while (TRUE) {
        fflush(stdin);//flush any /n's that may be left behind
        if (repeat == 1) printf("INVALID please type y or n\n");
        input = tolower(getchar());
        if (input == 'y') return TRUE;
        if (input == 'n') return FALSE;
        repeat = 1;
    }
}

void drawGrid(char* grid[]) {
    //draw border
    //loop over every position and draw it
    for (int x = 0; x < GRID_LEN; x++) {
        for(int y = 0; y < GRID_LEN; y++) {
            if (isRevealed(grid, x, y)) {
                //print contents
                if (isMine(grid, x, y)) {
                    //print mine at x,y
                }
                else {
                    //print number at x,y
                }
            }
            else {
                if (isFlagged(grid, x, y)) {
                    //print flag at x,y
                }
                else {
                    //print hidden at x,y
                }
            }
        }
    }
}
