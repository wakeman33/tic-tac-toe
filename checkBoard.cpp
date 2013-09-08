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
}

bool checkCoords(int x_pos, int y_pos) {
	if(x_pos >= 0 && x_pos <= 2 && y_pos >= 0 && y_pos <= 2)
		return true;
	else
		return false;
}

bool checkBoard(char pos_array[3][3]) {
	if(checkVirtical(pos_array))
		return true;
	else if(checkHorizontal(pos_array))
		return true;
	else if(checkDiagnal(pos_array))
		return true;
	else
		return false;
}

bool checkVirtical(char pos_array[3][3]) {
	for(int i = 0; i < 3; i++) {
		if(pos_array[i][0] != '\0' &&  pos_array[i][1] != '\0' && pos_array[i][2] != '\0') {
			if(pos_array[i][0] == pos_array[i][1] && pos_array[i][1] == pos_array[i][2])
				return true;
		}
	}
}

bool checkHorizontal(char pos_array[3][3]) {
	for(int i = 0; i < 3; i++) {
		if(pos_array[0][i] != '\0' &&  pos_array[1][i] != '\0' && pos_array[2][i] != '\0') {
			if(pos_array[i][0] == pos_array[i][1] && pos_array[i][1] == pos_array[i][2])
				return true;
		}
	}
}

bool checkDiagnal(char pos_array[3][3]) {
	if(pos_array[0][0] != '\0' &&  pos_array[1][1] != '\0' && pos_array[2][2] != '\0') {
		if(pos_array[0][0] == pos_array[1][1] && pos_array[1][1] == pos_array[2][2])
			return true;
	} else if (pos_array[0][2] != '\0' &&  pos_array[1][1] != '\0' && pos_array[2][0] != '\0') {
		if(pos_array[0][2] == pos_array[1][1] && pos_array[1][1] == pos_array[2][0])
			return true;
	} else {
		return false;
	}
}
