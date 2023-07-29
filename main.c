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
    printf("Welcome to MineSweeper!\n");
    printf("The goal is to flag all the mines and reveal all the safe spaces on the grid\n");
    printf("Controls:\n");
    printf("\t(f) flag/unflag\n");
    printf("\t(r) reveal\n");
    printf("\t(k) up\n");
    printf("\t(j) down\n");
    printf("\t(h) left\n");
    printf("\t(l) right\n");
    printf("the arrow keys also work for navigation\n\n");
    printf("Press enter to continue: ");
    getchar();
    system("clear");
}
