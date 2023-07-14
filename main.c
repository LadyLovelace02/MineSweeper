#include "defs.h"


int main(int argc, char **argv) {
    int play;
    intro();
    do {
        game();
        printf("Would you like to keep playing?\n");
        play = yOrN();
    } while (play == 1);
    printf("Thank you for playing! :)\n");
    return 0;
}

void intro() {
    system("clear");//clear the screen
    printf("MINESWEEPER\n");
    printf("Created by Melissa Rand\n\n");
    printf("Press any key to continue: ");
    getchar();
    system("clear");
}
