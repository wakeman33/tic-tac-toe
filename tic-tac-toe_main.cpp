#include <iostream>
#include <string>
#include "checkBoard.h"
#include "tools.h"

using namespace std;

int setup();
void quit();



int main() {
	int null_int;
	char pos_array[3][3] = {{'\0', '\0', '\0'}, {'\0', '\0', '\0'},{'\0', '\0', '\0'}};
	srand(time(NULL));

    setup();

	cout << "Please press enter to start!" << endl;
    cin.ignore(10, '\n');
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
			int block_array[3][2] = {{-1, -1}, {-1, -1}, {-1, -1}};
			checkToBlock(pos_array, block_array);
			bool block = false;
			if(block_array[0][0] != -1) {
				int block_count = 0;
				int index = 0;
				for(int i = 0; i < 3; i++) {
					if(block_array[i][0] != -1 && block_array[i][1] != -1) 
						block_count++;
					else
						break;
				}
				while(index < block_count) {
					if(checkCoords(block_array[index][0],block_array[index][1], pos_array)) {
						cout << "Blocking at " << block_array[index][0] << ", " << block_array[index][1] << endl;
						pos_array[block_array[index][1]][block_array[index][0]] = 'O';
						block = true;
						break;
					}
					index++;
				}
			}
			while (!block) {
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

void quit() {
    cout << string(190, '\n');
    cout << "Thanks for playing Kegan's Tic-Tac-Toe." << endl;
    cout << "See you soon." << endl;
    exit(0);
}

int setup() {
    printWelcome(); 
    cout << "Welcome Kegan\'s tic-tac-toe.\n\n" << endl;
	cout << "You may enter \'q\' or \'Q\' at any time to quit." << endl;
    cout << "Please select a game mode:" << endl;
    cout << "1) Two Player." << endl;
    cout << "2) One Player." << endl;
    cout << "\n-->  ";
    char mode = 0;
    while(1) {
        cin >> mode;
        if (mode == 'q' || mode == 'Q') {
            quit();
        } else if (mode == '1') {
            // Setup for two player mode
            break;
        } else if (mode == '2') {
            // Setup for one player mode
            break;
        } else {
            cout << "Entered value is invalid." << endl;
            cout << "Please re-enter the value" << endl;
            cout << "\n-->  ";
        }
    }

    // Set difficulty
    if (mode == '1') {
        // Set names for players.
        return (1);
    }

    cout << "\n\n\n";
    cout << "Please enter a difficulty level:" << endl;
    cout << "1) Easy" << endl;
    cout << "2) Normal" << endl;
    cout << "3) Hard" << endl;
    cout << "\n-->  ";

    char difficulty;
    while (1) {
        cin >> difficulty;
        if (difficulty == 'q' || difficulty == 'Q') {
            quit();
        } else if(difficulty == '1') {
            // Set the difficulty level
            break;
        } else if (difficulty == '2') {
            // Set the difficulty level
            break;
        } else if (difficulty == '3') {
            // Set the difficulty level
            break;
        } else {
            cout << "Entered value is invalid." << endl;
            cout << "Please re-enter the value" << endl;
            cout << "\n-->  ";
        }
    }
    return (2);
}
