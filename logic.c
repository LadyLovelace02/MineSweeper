#include "defs.h"

void game() {
    char **grid = malloc(GRID_LEN * sizeof(*grid));//malloc grid
    for (int i = 0; i < GRID_LEN; i++) {
        grid[i] = malloc(GRID_LEN * sizeof(*grid[i]));
    }
    setUpGame(grid);
    //game goes here
    
    freeGrid(grid);
}

void setUpGame(char** grid) {
    time_t t;
    srand((unsigned) time(&t));//generate random seed off of the current time
    //less random than I would have liked but should work
    //may improve in future
    int mineLocations[NUM_MINES][2];
    int x, y;
    for (int i = 0; i > NUM_MINES; i++) {
        //generate position of mine
        x = rand() % GRID_LEN;
        y = rand() % GRID_LEN;
        //check if it is not a duplicate
        if (!isMine(grid, x, y)) {
            makeMine(grid, x, y);
            mineLocations[i][0] = x;
            mineLocations[i][1] = y;
        }
        else i--;//decrement i to redo the mine location because it was a douplicate
    }
}

int isMine(char* grid[], int x, int y) {
    return ((grid[x][y] & 0x01000000) >> 6);
}

int isRevealed(char* grid[], int x, int y) {
    return ((grid[x][y] & 0x10000000) >> 7);
}

int isFlagged(char* grid[], int x, int y) {
    return ((grid[x][y] & 0x00100000) >> 5);
}

int numAdjMines(char* grid[], int x, int y) {
    return ((grid[x][y] & 0x00011110) >> 1);//return the 4 bits that represent adjMines
}

void makeMine(char* grid[], int x, int y) {
    grid[x][y] |= 0x01000000;//sets the 7th bit if not already set
}

void reveal(char* grid[], int x, int y) {
    grid[x][y] |= 0x10000000;//sets the 8th bit if not already set
    //need to reveal adj squares if numAdjMines is 0
    if (numAdjMines(grid, x, y) == 0) {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i != 0 && j != 0) {//do not call on original x and y cords
                    reveal(grid, x+i, y+j);
                }
            }
        }
    }
}

void flag(char* grid[], int x, int y) {
    grid[x][y] ^= 0x00100000;//using xor operator as user can flag and unflag positions
                             //this way this function can do both
}

int winCondition(char* grid[]) {
    //if all locations that are not mines are revealed
    for (int x = 0; x < GRID_LEN; x++) {
        for (int y = 0; y < GRID_LEN; y++) {
            if (!isMine(grid, x, y) && !isRevealed(grid, x, y)) return FALSE;
            //there are still remaining hidden spaces if if statement is met
        }
    }
    return TRUE;
}

void freeGrid(char** grid) {
    for (int i = 0; i < GRID_LEN; i++) {
        free(grid[i]);
    }
    free(grid);
}
