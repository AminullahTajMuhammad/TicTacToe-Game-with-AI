// ToDo Before this game
// Implement remove function in tree node
// Pass Array to all function to calculate the values

#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<iomanip>				// for setw() function
#include<Windows.h>				// for coloring and x,y coordinates for consol

#define MAX_MOVES 9
#define WIN 1000
#define LOSE -1000
#define DRAW 0

#define USER 'X'
#define COMPUTER 'O'
#define SPACE ' '

using namespace std;

HANDLE hConsole;


// Global Variables
bool isGame = true;
int movesScore[MAX_MOVES];
int positionForUser;
int positionForComputer;

int nextMaxScore = -1;
int nextMovePosition = -1;

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
	int score = 0;
	int position;
	GameNode *subNode[9];
};
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //


class TicTacToe {
private:
	string Player1, Player2;
	GameNode *root = NULL;
public:
	static char box[3][3];
	bool searchNode();
	void removeNode();			//this is temporary working on it soon

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

	void giveinput(char box[3][3]) {
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
		printBoard(box);
	}

	void updateInputIntoZero(int pos) {
	AGAIN:
		//gotoxy(1, 12);
		//cout << "O player turn: ";
		//gotoxy(1, 13);
		//cout << "Enter Position in numbers: ";
		//cin >> positionForUser;

		if (pos == 1) {
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
		else if (pos == 2) {
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
		else if (pos == 3) {
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
		else if (pos == 4) {
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
		else if (pos == 5) {
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
		else if (pos == 6) {
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
		else if (pos == 7) {
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
		else if (pos == 8) {
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
		else if (pos == 9) {
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
		printBoard(box);
	}

	bool checkWin(char box[3][3]) {
		// Check For X wins
		if (box[0][0] == 'X' && box[0][1] == 'X' && box[0][2] == 'X' || box[1][0] == 'X' && box[1][1] == 'X' && box[1][2] == 'X' ||
			box[2][0] == 'X' && box[2][1] == 'X' && box[2][2] == 'X' || box[0][0] == 'X' && box[1][0] == 'X' && box[2][0] == 'X' ||
			box[0][1] == 'X' && box[1][1] == 'X' && box[2][1] == 'X' || box[0][2] == 'X' && box[1][2] == 'X' && box[2][2] == 'X' ||
			box[0][0] == 'X' && box[1][1] == 'X' && box[2][2] == 'X' || box[0][2] == 'X' && box[1][1] == 'X' && box[2][0] == 'X') {


			//gotoxy(1, 20);
			//cout << "X player Wins: " << endl;
			return true;

		}

		// Check For O wins
		if (box[0][0] == 'O' && box[0][1] == 'O' && box[0][2] == 'O' || box[1][0] == 'O' && box[1][1] == 'O' && box[1][2] == 'O' ||
			box[2][0] == 'O' && box[2][1] == 'O' && box[2][2] == 'O' || box[0][0] == 'O' && box[1][0] == 'O' && box[2][0] == 'O' ||
			box[0][1] == 'O' && box[1][1] == 'O' && box[2][1] == 'O' || box[0][2] == 'O' && box[1][2] == 'O' && box[2][2] == 'O' ||
			box[0][0] == 'O' && box[1][1] == 'O' && box[2][2] == 'O' || box[0][2] == 'O' && box[1][1] == 'O' && box[2][0] == 'O') {

			//gotoxy(1, 20);
			//cout << "O player Wins: " << endl;
			return true;

		}

		return false;
	}

	bool isDraw(char arr[3][3]) {
		if (arr[0][0] != ' ' && arr[0][1] != ' ' && arr[0][2] != ' ' &&
			arr[1][0] != ' ' && arr[1][1] != ' ' && arr[1][2] != ' ' &&
			arr[2][0] != ' ' && arr[2][1] != ' ' && arr[2][2] != ' ' && checkWin(arr) == false) {

			return true;
		}
		return false;
	}


	int calculatePossibleMoveForComputer();
	int makeNodes(GameNode *node);
	int getPosition(int i, int j);
	int getScoreForPossibleMove(char arr[3][3]);

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

	GameNode* createNodeWithNewPosition(char arr[][3], int position) {
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
			for (int j = 0; j>3; j++) {
				inCopy[i][j] = toCopy[i][j];
			}
		}
	}
};
char TicTacToe::box[3][3] = {
	{ ' ', ' ', ' ' },
	{ ' ', ' ', ' ' },
	{ ' ', ' ', ' ' }
};
int main() {
	TicTacToe tictactoe;
	GameNode *node = tictactoe.createNode(tictactoe.box);

	while (isGame == true) {

		tictactoe.printBoard(tictactoe.box);
		tictactoe.giveinput(tictactoe.box);

		// return a value to check that the match who wins
		// check win for X player
		if (tictactoe.checkWin(tictactoe.box)) {
			break;
		}
		if (tictactoe.isDraw(tictactoe.box)) {
			gotoxy(1, 20);
			cout << "Match is Draw " << endl;
			break;
		}

		int position = tictactoe.calculatePossibleMoveForComputer();
		tictactoe.updateInputIntoZero(position);

		// return a value to check that the match who wins
		// check win for O player
		if (tictactoe.checkWin(tictactoe.box)) {
			break;
		}
		if (tictactoe.isDraw(tictactoe.box)) {
			gotoxy(1, 20);
			cout << "Match is Draw " << endl;
			break;
		}
	}

	system("pause");
}

int TicTacToe::calculatePossibleMoveForComputer() {
	int position;
	GameNode *current = createNode(box);
	position = makeNodes(current);

	return position;
}

int TicTacToe::makeNodes(GameNode *node) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (node->nodeBox[i][j] == ' ') {
				
				// get Position of empty space
				positionForComputer = getPosition(i, j);
				
				// create node on empty space  
				node->subNode[positionForComputer - 1] = createNode(box);
				
				// put value on empty space node
				node->subNode[positionForComputer-1]->nodeBox[i][j] = 'O';

				// get score of empty space node
				node->subNode[positionForComputer - 1]->score = getScoreForPossibleMove(node->subNode[positionForComputer-1]->nodeBox);

				/*
				int nodeScore = node->subNode[positionForComputer - 1]->score;
				int nodePosition = positionForComputer;
				if (nodeScore > nextMaxScore)
				{
					nextMaxScore = nodeScore;
					nextMovePosition = nodePosition;
				}
				*/

			}
		}
	}

	/*
	int maxScore = -1;
	int maxIndex = -1;
	for (int i = 0; i < 9; i++)
	{
		GameNode *tempNode = node->subNode[i];
		if (tempNode != NULL)
		{
			int nodeScore = tempNode->score;
			int nodePosition = tempNode->position;
			if (nodeScore >= maxScore)
			{
				maxScore = nodeScore;
				maxIndex = nodePosition;
			}
		}
	}
	*/
	

	//int position = nextMovePosition;
	//nextMaxScore = -1;
	//nextMovePosition = -1;
	
	return maxIndex;		// this is for returning score and put the
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

int TicTacToe::getScoreForPossibleMove(char arr[3][3]) {
	int score = 0;
	if (TicTacToe::checkWin(arr)) {
		score = 10;
	}
	else if (TicTacToe::isDraw(arr)) {
		score = 10;
	}
	else {
		score = 0;
	}
	return score;
}
