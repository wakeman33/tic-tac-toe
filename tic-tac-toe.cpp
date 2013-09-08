#include <iostream>
#include <string>
using namespace std;

void printGrid(char array[3][3]);
bool checkCoords(int, int);
bool checkBoard(char array[3][3]);
bool checkHorizontal(char array[3][3]);
bool checkVirtical(char array[3][3]);
bool checkDiagnal(char array[3][3]);

int main() {
	
	char pos_array[3][3] = {{'\0', '\0', '\0'}, {'\0', '\0', '\0'},{'\0', '\0', '\0'}};
	cout << string(50, '\n');
	cout << "Welcome to two player tic-tac-toe.\n\n" << endl;
	cout << "Player 1 is X's." << endl;
	cout << "Player 2 is O's." << endl;
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
		cout << "It is Player " << player << "\'s turn." << endl;
		cout << "Please enter the X coordinate for your turn:  ";
		cin >> x_pos;
		x_pos -= 1;
		cout << "Please enter the Y coordinate for your turn;  ";
		cin >> y_pos;
		y_pos -= 1;
		if(checkCoords(y_pos, x_pos)) {
			if(pos_array[y_pos][x_pos] != '\0') {
				cout << "This position is already taken." << endl;
				cout << "Please try again." << endl;
				cout << "Press enter to continue." << endl;
				cin.ignore(10, '\n');
				cin.ignore(10, '\n');
			} else{
				if(player == 1) {
					pos_array[y_pos][x_pos] = 'X';
					player = 2;
				} else {
					pos_array[y_pos][x_pos] = 'y';
					player = 1;
				}
			}
		} else {
			cout << "Coordinates entered are invalid. Please re-enter coordinates." << endl;
			cout << "Press enter to continue." << endl;
			cin.ignore(10, '\n');
			cin.ignore(10, '\n');
		}

		if(checkBoard(pos_array)) {
			cout << string(50, '\n');
			cout << "Player " << player << " has won!!!\n" << endl;
			printGrid(pos_array);
			break;
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
