#include<iostream>
#include<conio.h>
#include<cstring>
#include<iomanip>				// for setw() function
#include<Windows.h>				// for coloring and x,y coordinates for consol
using namespace std;
HANDLE hConsole;
bool isGame = true;
//---------- X,Y Co-Ordinates Function ---------------//
void gotoxy(int x, int y) { 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class TicTacToe {
	private:
		char box[3][3] = { 
							{' ', ' ', ' '}, 
							{' ', ' ', ' '}, 
							{' ', ' ', ' '}
						};
		int positionForUser;
		string Player1, Player2;
		
	public:
		
		void printBoard() {
			cout << endl;
			gotoxy(10,2);
			cout << setw(4) << box[0][0] << "\t|" << setw(4) << box[0][1] << "\t|" << setw(4) << box[0][2];
			gotoxy(6,3);
			cout << " ----------------------------";
			gotoxy(10,4);
			cout << setw(4) << box[1][0] << "\t|" << setw(4) << box[1][1] << "\t|" << setw(4) << box[1][2];
			gotoxy(6,5);
			cout << " ----------------------------";
			gotoxy(10,6);
			cout << setw(4) << box[2][0] << "\t|" << setw(4) << box[2][1] << "\t|" << setw(4) << box[2][2];
		}
		
		void giveinput() {
			xyz:
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			gotoxy(1,8);
			cout << "X player turn:";
			gotoxy(1,9);
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
	abc:
		gotoxy(1,12);
		cout << "O player turn: ";
		gotoxy(1,13);
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
				goto abc;
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
				goto abc;
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
				goto abc;
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
				goto abc;
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
				goto abc;
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
				goto abc;
			}
		}
		else if (positionForUser == 7) {
			if (box[2][0] == ' ') {
				SetConsoleTextAttribute(hConsole, 10);
				box[2][0] = 'O';		}
			else {
				gotoxy(1, 18);
				SetConsoleTextAttribute(hConsole, 13);
				cout << "This position is filled enter empty position: \n\n";
				SetConsoleTextAttribute(hConsole, 15);
				goto abc;
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
				goto abc;
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
				goto abc;
			}
		}
		SetConsoleTextAttribute(hConsole, 7);
		printBoard();
	}
	
	void checkWin() {
		if (box[0][0] == 'X' && box[0][1] == 'X' && box[0][2] == 'X' || box[1][0] == 'X' && box[1][1] == 'X' && box[1][2] == 'X' ||
			box[2][0] == 'X' && box[2][1] == 'X' && box[2][2] == 'X' || box[0][0] == 'X' && box[1][0] == 'X' && box[2][0] == 'X' ||
			box[0][1] == 'X' && box[1][1] == 'X' && box[2][1] == 'X' || box[0][2] == 'X' && box[1][2] == 'X' && box[2][2] == 'X' ||
			box[0][0] == 'X' && box[1][1] == 'X' && box[2][2] == 'X' || box[0][2] == 'X' && box[1][1] == 'X' && box[2][0] == 'X') {
			
			gotoxy(1, 20);
			cout << "X player Wins Means " << Player1 << " Wins: " << endl;
			isGame = false;
		}

		if (box[0][0] == 'O' && box[0][1] == 'O' && box[0][2] == 'O' || box[1][0] == 'O' && box[1][1] == 'O' && box[1][2] == 'O' ||
			box[2][0] == 'O' && box[2][1] == 'X' && box[2][2] == 'O' || box[0][0] == 'O' && box[1][0] == 'O' && box[2][0] == 'O' ||
			box[0][1] == 'O' && box[1][1] == 'X' && box[2][1] == 'O' || box[0][2] == 'O' && box[1][2] == 'O' && box[2][2] == 'O' ||
			box[0][0] == 'O' && box[1][1] == 'X' && box[2][2] == 'O' || box[0][2] == 'O' && box[1][1] == 'O' && box[2][0] == 'O') {
			
			gotoxy(1, 20);
			cout << "O player Wins Means " << Player2 << " Wins: " << endl;
			isGame = false;
		}
	}
};
int main() {
	TicTacToe tictactoe;
	while(isGame) {
		tictactoe.printBoard();
		tictactoe.giveinput();
		tictactoe.updateInputIntoZero();
		tictactoe.checkWin();
		
	}
	
}
