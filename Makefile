GPP = g++

all: boardGame

boardGame: checkBoard.o
	$(GPP) tic-tac-toe3.cpp checkBoard.o -o tic-tac-toe
checkBoard.o: checkBoard.cpp
		$(GPP) -c checkBoard.cpp

clean:
		rm -rf *.o a.out
