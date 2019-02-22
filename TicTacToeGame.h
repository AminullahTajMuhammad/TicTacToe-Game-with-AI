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
	
	bool checkWin(char box[3][3], char player);
	
	
	bool checkDraw(char box[3][3], char player);
	
	
	void startGame() {

	}


};
