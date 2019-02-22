#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<Windows.h>
#include "TicTacToeTree.h"
using namespace std;

//---------- X,Y Co-Ordinates Function ---------------//
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class TicTacToeGame {
public:

	char currentPlayer = 'O';
	bool isGame = false;
	char gameBox[3][3];

	void initBox(char box[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				box[i][j] = ' ';
			}
		}
	}

	void printBoard(char box[3][3]) {
		cout << endl;
		gotoxy(10, 2);
		cout << setw(4) << box[0][0] << "\t|" << setw(4) << box[0][1] << "\t|" << setw(4) << box[0][2];
		gotoxy(6, 3);
		cout << " ----------------------------";
		gotoxy(10, 4);
		cout << setw(4) << box[1][0] << "\t|" << setw(4) << box[1][1] << "\t|" << setw(4) << box[1][2];
		gotoxy(6, 5);
		cout << " ----------------------------";
		gotoxy(10, 6);
		cout << setw(4) << box[2][0] << "\t|" << setw(4) << box[2][1] << "\t|" << setw(4) << box[2][2];
	}
	void getInput(char box[3][3]);
	
	bool checkWin(char box[3][3], char player) {
		if (
			(box[0][0] == player && box[0][1] == player && box[0][2] == player) ||
			(box[1][0] == player && box[1][1] == player && box[1][2] == player) ||
			(box[2][0] == player && box[2][1] == player && box[2][2] == player) ||
			(box[0][0] == player && box[1][0] == player && box[2][0] == player) ||
			(box[0][1] == player && box[1][1] == player && box[2][1] == player) ||
			(box[0][2] == player && box[1][2] == player && box[2][2] == player) ||
			(box[0][0] == player && box[1][1] == player && box[2][2] == player) ||
			(box[0][2] == player && box[1][1] == player && box[2][0] == player)) {
			return true;
		}

		return false;
	}
	
	
	bool checkDraw(char arr[3][3], char player) {
		if (arr[0][0] != ' ' && arr[0][1] != ' ' && arr[0][2] != ' ' &&
			arr[1][0] != ' ' && arr[1][1] != ' ' && arr[1][2] != ' ' &&
			arr[2][0] != ' ' && arr[2][1] != ' ' && arr[2][2] != ' ' && checkWin(arr, player) == false) {

			return true;
		}
		return false;
	}
	

	int getPositionFromXY(int i, int j) {
		int position;
		
		if (i == 0 && j == 0) { position = 1; }
		else if (i == 0 && j == 1) { position = 2; }
		else if (i == 0 && j == 2) { position = 3; }
		else if (i == 1 && j == 0) { position = 4; }
		else if (i == 1 && j == 1) { position = 5; }
		else if (i == 1 && j == 2) { position = 6; }
		else if (i == 2 && j == 0) { position = 7; }
		else if (i == 2 && j == 1) { position = 8; }
		else if (i == 2 && j == 2) { position = 9; }

		return position;
	}

	void getXYfromPosition(int &i, int &j, int position ) {
		if (position == 1) {	i = 0;		j = 0;	}
		if (position == 2) {	i = 0;		j = 1;	}
		if (position == 3) {	i = 0;		j = 2;	}
		if (position == 4) {	i = 1;		j = 0;	}
		if (position == 5) {	i = 1;		j = 1;	}
		if (position == 6) {	i = 1;		j = 2;	}
		if (position == 7) {	i = 2;		j = 0;	}
		if (position == 8) {	i = 2;		j = 1;	}
		if (position == 9) {	i = 2;		j = 2;	}
	}
	
	void startGame() {
		isGame = true;
		initBox(gameBox);

		while (isGame) {
			int pos = -1;
			
			printBoard(gameBox); 
			
			if (currentPlayer == 'X') {
				cout << endl << endl << "Enter Position (1-9): ";
				cin >> pos;
			}
			else {
				cout << endl << endl << "Enter Position (1-9): ";
				cin >> pos;
			}

			if (pos != -1) {
				if (pos < 0 || pos > 9) {
					cout << "Invalid Position, Enter new position (1-9)";
					continue;
				}
			}


			int x ;
			int y ;

			getXYfromPosition(x, y, pos);
			if ((x != -1) && (y != -1) && (gameBox[x][y] = ' ')) {
				gameBox[x][y] = currentPlayer;

				if (checkWin(gameBox, currentPlayer)) {
					cout << currentPlayer << "Wins!";

					printBoard(gameBox);
					isGame = false;
					break;
				}
				else if(checkDraw(gameBox, currentPlayer)) {
					cout <<"Match is Draw";
					printBoard(gameBox);
					isGame = false;
					break;
				} 
			}
			else {
				cout << "This place is filled" << endl;
			}

			currentPlayer = changeInput(currentPlayer);
		
		}
	}

	char changeInput(char move) {
		if (move == 'X') {
			move = 'O';
		}
		else {
			move = 'X';
		}

		return move;
	}
};
