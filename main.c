#include "defs.h"


int main(int argc, char **argv) {
    int play;
    do {
        intro();
        setUpGame();
        printf("Would you like to keep playing?\n");
        play = yOrN();
    } while (play == 1);
    printf("Thank you for playing! :)\n");
    return 0;
}

void intro() {
    unsigned int seed = 0;
    system("clear");//clear the screen
    printf("MINESWEEPER\n");
    printf("Created by Melissa Rand\n\n");
    printf("Press any key to continue: ");
    while (!getch()) {//doesn't wait for input properly fix later
        seed++;
    }
    printf("DEBUG, seed: %d\n", seed);
    srand(seed);
    //system("clear");
}
