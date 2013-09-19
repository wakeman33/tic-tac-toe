/*
 * =====================================================================================
 *
 *       Filename:  checkBoard.cpp
 *
 *    Description:  Fucntion declerations for checking a tic-tac-toe board.
 *
 *        Version:  1.0
 *        Created:  09/08/2013 01:01:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kegan Pankratz (), ridinthewave33@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include "checkBoard.h"
using namespace std;



void printGrid(char pos_array[3][3]) {
	for(int i = 0; i < 3; i++) {
		cout << "\t";
		for(int j = 0; j < 3; j++) {
			
			if(pos_array[i][j] == '\0') {
				cout << "   ";
			} else {
				cout << " " <<  pos_array[i][j] << " "; 
			}
			if(j < 2)
				cout << "|";
		}
		if(i < 2) {
			cout << endl;
			cout << "\t-----------";
		}
		cout << "\n";
	} 
	cout << "\n\n" << endl;
}

bool checkCoords(int x_pos, int y_pos, char pos_array[3][3]) {
	if(!(x_pos >= 0 && x_pos <= 2 && y_pos >= 0 && y_pos <= 2)) {
		cout << "Coordinates entered are invalid. Please re-enter coordinates." << endl;
		cout << "Press enter to continue." << endl;
		return false;
	}	
	
	if(pos_array[y_pos][x_pos] != '\0') {
		cout << "This position is already taken." << endl;
		cout << "Please try again." << endl;
		return false;
	}
	return true;
}

bool checkBoard(char pos_array[3][3]) {
	if(checkVirtical(pos_array)) {
		cout << "VIRTICAL" << endl;
		return true;
	} else if(checkHorizontal(pos_array)) {
		cout << "HORIZONTAL" << endl;
		return true;
	} else if(checkDiagnal(pos_array)) {
		cout << "DIAGNAL" << endl;
		return true;
	} else {
		return false;
	}
}

bool checkVirtical(char pos_array[3][3]) {
	for(int i = 0; i < 3; i++) {
		if(pos_array[i][0] != '\0' &&  pos_array[i][1] != '\0' && pos_array[i][2] != '\0') {
			if(pos_array[i][0] == pos_array[i][1] && pos_array[i][1] == pos_array[i][2]) {
				cout << "Virtical" << endl;
				return true;
			}
		}
	}
	return false;
}

bool checkHorizontal(char pos_array[3][3]) {
	for(int i = 0; i < 3; i++) {
		if(pos_array[0][i] != '\0' &&  pos_array[1][i] != '\0' && pos_array[2][i] != '\0') {
			if(pos_array[i][0] == pos_array[i][1] && pos_array[i][1] == pos_array[i][2]) {
				cout << "Horizontal" << endl;
				return true;
			}
		}
	}
	return false;
}

bool checkDiagnal(char pos_array[3][3]) {
	if(pos_array[0][0] != '\0' &&  pos_array[1][1] != '\0' && pos_array[2][2] != '\0') {
		if(pos_array[0][0] == pos_array[1][1] && pos_array[1][1] == pos_array[2][2]) {
			cout << "left to right" << endl;
			return true;
		}
	} else if (pos_array[0][2] != '\0' &&  pos_array[1][1] != '\0' && pos_array[2][0] != '\0') {
		if(pos_array[0][2] == pos_array[1][1] && pos_array[1][1] == pos_array[2][0]) {
			cout << "right to left" << endl;
			return true;
		}
	}
	return false;
}


bool checkToBlock(char pos_array[3][3], int blocking_array[3][2]) {
	int count = 0;
	// Check rows for blocking oppertunities.
	for(int i = 0; i < 3; i++) {
		if(pos_array[i][1] == 'X') {
			if(pos_array[i][0] == 'X') {
				// Signal to block with an O  at 2, i
				blocking_array[count][0] = 2;
				blocking_array[count][1] = i;
				count++;
			} else if(pos_array[i][2] == 'X'){
				// Signal to block with an O at 0, i
				blocking_array[count][0] = 0;
				blocking_array[count][1] = i;
				count++;
			} 
		}
	}

	// Check collomns for blocking oppertunities.
	for(int i = 0; i < 3; i++) {
		if(pos_array[1][i] == 'X') {
			if(pos_array[0][i] == 'X') {
				// Signal to block with an O at i, 2
				blocking_array[count][0] = i;
				blocking_array[count][1] = 2;
				count++;
			} else if(pos_array[2][i] == 'X') {
				// Signal to block with an O at i, 0
				blocking_array[count][0] = i;
				blocking_array[count][1] = 0;
				count++;
			}
		}
	}

	// Check diagnals for blocking oppertunities.
	if(pos_array[1][1] == 'X') {
		if(pos_array[0][0] == 'X') {
			// Signal to block with an O at 2, 2
			blocking_array[count][0] = 2;
			blocking_array[count][1] = 2;
			count++;
		} else if(pos_array[2][2] == 'X') {
			// Signal to block with an O at 0, 0
			blocking_array[count][0] = 0;
			blocking_array[count][1] = 0;
			count++;
		}
		
		if(pos_array[2][0] == 'X') {
			// Signal to block with an O at 2, 0
			blocking_array[count][0] = 2;
			blocking_array[count][1] = 0;
			count++;
		} else if(pos_array[0][2] == 'X') {
			// Signal to block with an O at 0, 2
			blocking_array[count][0] = 0;
			blocking_array[count][1] = 2;
			count++;
		}
	}
	return blocking_array;
}
