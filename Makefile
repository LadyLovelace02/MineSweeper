MineSweeper: main.o logic.o ui.o ; gcc main.o logic.o ui.o
OPT = -g

main.o: main.c ; gcc $(OPT) -c main.c
logic.o: logic.c ; gcc $(OPT) -c logic.c 
ui.o: ui.c ; gcc $(OPT) -c ui.c 

clean: ; rm -f MineSweeper *.o
