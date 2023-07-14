MineSweeper: main.o logic.o ui.o ; clang -o MineSweeper main.o logic.o ui.o -I/Library/Developer/CommandLineTools/usr/include -I/opt/homebrew/include -lncurses
OPT = -g

main.o: main.c ; clang $(OPT) -c main.c
logic.o: logic.c ; clang $(OPT) -c logic.c 
ui.o: ui.c ; clang $(OPT) -c ui.c 

clean: ; rm -f MineSweeper *.o
