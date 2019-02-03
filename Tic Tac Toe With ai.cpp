// ToDo Before this game
// Implement remove function in tree node

#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<iomanip>				// for setw() function
#include<Windows.h>				// for coloring and x,y coordinates for consol

#define MAX_MOVES 9
#deifne COMPUTER 'O'

using namespace std;

HANDLE hConsole;


// Global Variables
bool isGame = true;
int movesScore[MAX_MOVES];
int positionForUser;

//---------- X,Y Co-Ordinates Function ---------------//
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// - - - - - - - - Game Node for calculate AI of tic tac toe - - - - - - - -// 
struct GameNode {
	char nodeBox[3][3];
	int score;
	GameNode *subNode[9];
};
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //


class TicTacToe {
private:
	static char box[3][3];
	string Player1, Player2;
	GameNode *root = NULL;
public:

	bool searchNode();
	void removeNode();			//this is temporary working on it soon

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

	int calculatePossibleMoveForComputer();

	int makeNodes(GameNode *node);

	int getPosition(int i, int j);

	GameNode* createNode(char arr[3][3]) {
		GameNode *temp = new GameNode;
		//copyArrayValues(temp->nodeBox, arr);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp->nodeBox[i][j] = arr[i][j];
			}
		}
		return temp;
	}

	void copyArrayValues(char inCopy[3][3], char toCopy[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j>3; j++) {+
				inCopy[i][j] = toCopy[i][j];
			}
		}
	}
};
char TicTacToe::box[3][3] = {
	{ 'O', ' ', 'X' },
	{ 'X', ' ', ' ' },
	{ 'X', 'O', 'O' }
};
int main() {
	TicTacToe tictactoe;

	while (isGame == true) {

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

	system("pause");
}

int TicTacToe::calculatePossibleMoveForComputer() {
	if (TicTacToe::checkWin() || TicTacToe::isDraw()) {
		return 10;
	}
	else {
		/*
		1==> Search Empty Position and creat node on it with new position.
		2==> Check new position score
		*/
		GameNode *current = NULL;
		makeNodes(current);

	}
	return 0;
}

int TicTacToe::makeNodes(GameNode *node) {
	node = createNode(box);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (node->nodeBox[i][j] == ' ') {
				positionForUser = getPosition(i, j);
				node->subNode[positionForUser-1] = createNode(box);
				node->nodeBox[i][j] = 'O';
			}
		}
	}

	return 0;		// this is for returning score and put the
}

int TicTacToe::getPosition(int i, int j) {
	int position = 0;
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
