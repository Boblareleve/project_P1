
make : board.o input.o logic.o print.o main.o
	gcc board.o input.o logic.o print.o main.o -o game.out

make_test : board.o input.o logic.o print.o tests.o
	gcc board.o input.o logic.o print.o tests.o -o test.out

board.o : board.c board.h
	gcc -c board.c -o board.o
	
logic.o : logic.c logic.h
	gcc -c logic.c -o logic.o
	
input.o : input.c input.h
	gcc -c input.c -o input.o
	
print.o : print.c print.h
	gcc -c print.c -o print.o
	
main.o : main.c main.h
	gcc -c main.c -o main.o
	
tests.o : tests.c main.h
	gcc -c tests.c -o tests.o


clear :
	rm *.o *.out

re : clear make

exe : re
	./game.out
