#include <iostream>
#include <string>
using namespace std;

void printGrid(char array[3][3]);
bool checkCoords(int, int, char array[3][3]);
bool checkBoard(char array[3][3]);
bool checkHorizontal(char array[3][3]);
bool checkVirtical(char array[3][3]);
bool checkDiagnal(char array[3][3]);

int main() {
	
	char pos_array[3][3] = {{'\0', '\0', '\0'}, {'\0', '\0', '\0'},{'\0', '\0', '\0'}};
	srand(time(NULL));
	cout << string(50, '\n');
	cout << "Welcome to one player tic-tac-toe.\n\n" << endl;
	cout << "Player 1 is X's." << endl;
	cout << "Computer is O's." << endl;
	cout << endl;

	cout << "Please press enter to start!" << endl;
	cin.ignore(10, '\n');

	int player = 1;
	int x_pos;
	int y_pos;
	char temp;
	while (1) {
		cout << string(50, '\n');
		printGrid(pos_array);

		if(player == 1) {
			cout << "It is Player " << player << "\'s turn." << endl;
			cout << "Please enter the X coordinate for your turn:  ";
			cin >> x_pos;
			x_pos -= 1;
			cout << "Please enter the Y coordinate for your turn;  ";
			cin >> y_pos;
			y_pos -= 1;

			if(checkCoords(x_pos, y_pos, pos_array)) {
				pos_array[y_pos][x_pos] = 'X';
				if(checkBoard(pos_array)) {
					cout << string(50, '\n');
					cout << "Player 1 has won the game!!!\n" << endl;
					printGrid(pos_array);
					break;
				} else {
					player = 2;
				}
			} else {
				cin.ignore(10, '\n');
				cin.ignore(10, '\n');
			}
		} else {
			cout << "It is the Computers\'s turn." << endl;
			while (1) {
				x_pos = rand() % 3;
				y_pos = rand() % 3;
				if(checkCoords(x_pos, y_pos, pos_array)) {
					pos_array[y_pos][x_pos] = 'O';
					break;
				}
			}
			sleep(5);
			
			if(checkBoard(pos_array)) {
				cout << string(50, '\n');
				cout << "The computer has won this game!!!\n" << endl;
				printGrid(pos_array);
				break;
			} else {
				player = 1;
			}
		}
	}
}

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
