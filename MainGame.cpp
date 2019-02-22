#include<iostream>
#include<cstdlib>
#include "TicTacToeGame.h"
using namespace std;

int main() {

	TicTacToeGame tictactoe;
	tictactoe.startGame();

	gotoxy(0, 20);
	system("pause");
	return 0;
}
