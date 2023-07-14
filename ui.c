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
