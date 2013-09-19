GPP = g++
OUTPUTNAME = "tic-tac-toe"
all: boardGame

boardGame: checkBoard.o tools.o
	$(GPP) tic-tac-toe_main.cpp checkBoard.o tools.o -o $(OUTPUTNAME)
addins: checkBoard.cpp tools.cpp
	$(GPP) -c checkBoard.cpp
tools.o: tools.cpp
	$(GPP) -c tools.cpp

clean:
		rm -rf *.o $(OUTPUTNAME)
