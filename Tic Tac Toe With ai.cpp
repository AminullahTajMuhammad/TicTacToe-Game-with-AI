// ToDo Before this game
// Implement remove function in tree node

#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<array>
#include<cstring>
#include<iomanip>				// for setw() function
#include<Windows.h>				// for coloring and x,y coordinates for consol
#define MAX_MOVES 9
using namespace std;
HANDLE hConsole;
// Global Variables
bool isGame = true;
int movesScore[MAX_MOVES];
//---------------//

//---------- X,Y Co-Ordinates Function ---------------//
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct GameNode {
	char nodeBox[3][3];
	int score;
	GameNode *node;
};

class A;

class TicTacToe {
private:
	A a;
	char box[3][3] = {
		{ 'O', ' ', 'X' },
		{ 'X', ' ', ' ' },
		{ 'X', 'O', 'O' }
	};
	int positionForUser;
	string Player1, Player2;

public:
	int calculatePossibleMoveForComputer();
	void makeNodes(GameNode *node);
	TicTacToe() {
		a = A();
	}
	GameNode* createNode(char arr[3][3]) {
		GameNode *temp = new GameNode;
		copyArrayValues(temp->nodeBox, arr);
		temp->node = NULL;
	}
	void printBoard() {
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

	void giveinput() {
	xyz:
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		gotoxy(1, 8);
		cout << "X player turn:";
		gotoxy(1, 9);
		cout << "Enter Position in numbers: ";
		cin >> positionForUser;
		if (positionForUser == 1) {
			if (box[0][0] == ' ') {
				box[0][0] = 'X';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 8);
				cout << "This position is filled enter empty positionForUser: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto xyz;
			}
		}
		else if (positionForUser == 2) {
			if (box[0][1] == ' ') {
				box[0][1] = 'X';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 7);
				cout << "This position is filled enter empty positionForUser: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto xyz;
			}
		}
		else if (positionForUser == 3) {
			if (box[0][2] == ' ') {
				box[0][2] = 'X';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 9);
				cout << "This position is filled enter empty positionForUser: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto xyz;
			}
		}
		if (positionForUser == 4) {
			if (box[1][0] == ' ') {
				box[1][0] = 'X';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 10);
				cout << "This position is filled enter empty positionForUser: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto xyz;
			}
		}
		if (positionForUser == 5) {
			if (box[1][1] == ' ') {
				box[1][1] = 'X';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 11);
				cout << "This position is filled enter empty positionForUser: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto xyz;
			}
		}
		if (positionForUser == 6) {
			if (box[1][2] == ' ') {
				box[1][2] = 'X';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 12);
				cout << "This position is filled enter empty positionForUser: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto xyz;
			}
		}
		if (positionForUser == 7) {
			if (box[2][0] == ' ') {
				box[2][0] = 'X';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 13);
				cout << "This position is filled enter empty positionForUser: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto xyz;
			}
		}
		if (positionForUser == 8) {
			if (box[2][1] == ' ') {
				box[2][1] = 'X';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 14);
				cout << "This position is filled enter empty positionForUser: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto xyz;
			}
		}
		if (positionForUser == 9) {
			if (box[2][2] == ' ') {
				box[2][2] = 'X';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 15);
				cout << "This position is filled enter empty positionForUser: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto xyz;
			}
		}
		printBoard();
	}

	void updateInputIntoZero() {
	AGAIN:
		gotoxy(1, 12);
		cout << "O player turn: ";
		gotoxy(1, 13);
		cout << "Enter Position in numbers: ";
		cin >> positionForUser;
		if (positionForUser == 1) {
			if (box[0][0] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[0][0] = 'O';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 7);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto AGAIN;
			}
		}
		else if (positionForUser == 2) {
			if (box[0][1] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[0][1] = 'O';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 8);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto AGAIN;
			}
		}
		else if (positionForUser == 3) {
			if (box[0][2] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[0][2] = 'O';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 9);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto AGAIN;
			}
		}
		else if (positionForUser == 4) {
			if (box[1][0] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[1][0] = 'O';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 10);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto AGAIN;
			}
		}
		else if (positionForUser == 5) {
			if (box[1][1] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[1][1] = 'O';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 11);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto AGAIN;
			}
		}
		else if (positionForUser == 6) {
			if (box[1][2] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[1][2] = 'O';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 12);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto AGAIN;
			}
		}
		else if (positionForUser == 7) {
			if (box[2][0] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[2][0] = 'O';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 13);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto AGAIN;
			}
		}
		else if (positionForUser == 8) {
			if (box[2][1] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[2][1] = 'O';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 14);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto AGAIN;
			}
		}
		else if (positionForUser == 9) {
			if (box[2][2] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[2][2] = 'O';
			}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 15);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto AGAIN;
			}
		}
		SetConsoleTextAttribute(hConsole, 7);
		printBoard();
	}

	bool checkWin() {
		// Check For X wins
		if (box[0][0] == 'X' && box[0][1] == 'X' && box[0][2] == 'X' || box[1][0] == 'X' && box[1][1] == 'X' && box[1][2] == 'X' ||
			box[2][0] == 'X' && box[2][1] == 'X' && box[2][2] == 'X' || box[0][0] == 'X' && box[1][0] == 'X' && box[2][0] == 'X' ||
			box[0][1] == 'X' && box[1][1] == 'X' && box[2][1] == 'X' || box[0][2] == 'X' && box[1][2] == 'X' && box[2][2] == 'X' ||
			box[0][0] == 'X' && box[1][1] == 'X' && box[2][2] == 'X' || box[0][2] == 'X' && box[1][1] == 'X' && box[2][0] == 'X') {


			gotoxy(1, 20);
			cout << "X player Wins: " << endl;
			return true;

		}

		// Check For O wins
		if (box[0][0] == 'O' && box[0][1] == 'O' && box[0][2] == 'O' || box[1][0] == 'O' && box[1][1] == 'O' && box[1][2] == 'O' ||
			box[2][0] == 'O' && box[2][1] == 'O' && box[2][2] == 'O' || box[0][0] == 'O' && box[1][0] == 'O' && box[2][0] == 'O' ||
			box[0][1] == 'O' && box[1][1] == 'O' && box[2][1] == 'O' || box[0][2] == 'O' && box[1][2] == 'O' && box[2][2] == 'O' ||
			box[0][0] == 'O' && box[1][1] == 'O' && box[2][2] == 'O' || box[0][2] == 'O' && box[1][1] == 'O' && box[2][0] == 'O') {

			gotoxy(1, 20);
			cout << "O player Wins: " << endl;
			return true;

		}

		return false;
	}

	bool isDraw() {
		if (box[0][0] != ' ' && box[0][1] != ' ' && box[0][2] != ' ' &&
			box[1][0] != ' ' && box[1][1] != ' ' && box[1][2] != ' ' &&
			box[2][0] != ' ' && box[2][1] != ' ' && box[2][2] != ' ' && checkWin() == false) {

			return true;
		}
		return false;
	}
	
	void copyArrayValues(char inCopy[3][3], char toCopy[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j>3; j++) {
				inCopy[i][j] = toCopy[i][j];
			}
		}
	}
};

class A {
	private:
	TicTacToe toe;
	
	A() {
	}
};


int main() {
	TicTacToe tictactoe;
	while (isGame == true) {
		bool isCheckForWinner;
		bool isDraw;

		tictactoe.printBoard();
		tictactoe.giveinput();

		// return a value to check that the match who wins
		// check win for X player
		if (tictactoe.checkWin()) {
			break;
		}
		if (tictactoe.isDraw()) {
			gotoxy(1, 20);
			cout << "Match is Draw " << endl;
		}
		int value = tictactoe.calculatePossibleMoveForComputer();
		tictactoe.updateInputIntoZero();

		// return a value to check that the match who wins
		// check win for O player
		if (tictactoe.checkWin()) {
			break;
		}
		if (tictactoe.isDraw()) {
			gotoxy(1, 20);
			cout << "Match is Draw " << endl;
		}
	}
	

	_getch();
}

int TicTacToe::calculatePossibleMoveForComputer() {
	if (TicTacToe::checkWin() || TicTacToe::isDraw()) {
		return 10;
	}
	else {
		
		GameNode *current = NULL;
		makeNodes(current);

	}
	return 0;
}

void TicTacToe::makeNodes(GameNode *node) {
	node = createNode(box);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (node->nodeBox[i][j] == ' ') {
				node->subNode[i][j] = createNode(box);
		}
	}
}
int TicTacToe::getPosition(GameNode *node) {
	char* arr[9];
	*arr[0] = node->nodeBox[0][0];
	*arr[1] = node->nodeBox[0][1];
	*arr[2] = node->nodeBox[0][2];
	*arr[3] = node->nodeBox[1][0];
	*arr[4] = node->nodeBox[1][1];
	*arr[5] = node->nodeBox[1][2];
	*arr[6] = node->nodeBox[2][0];
	*arr[7] = node->nodeBox[2][1];
	*arr[8] = node->nodeBox[2][2];
	
	int position = 0;
	for (int i = 0; i < 9; i++) {
		switch (i) {
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;

			default:
				break;
		}
	}
	return position;
}
