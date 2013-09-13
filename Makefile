GPP = g++

all: boardGame

boardGame: checkBoard.o tools.o
	$(GPP) tic-tac-toe3.cpp checkBoard.o tools.o -o tic-tac-toe
addins: checkBoard.cpp tools.cpp
	$(GPP) -c checkBoard.cpp
tools.o: tools.cpp
	$(GPP) -c tools.cpp

clean:
		rm -rf *.o a.out
