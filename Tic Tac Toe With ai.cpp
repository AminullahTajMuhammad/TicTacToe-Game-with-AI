#include<iostream>
using namespace std;
class TicTacToe {
	private:
		char box[3][3] = { 
							{' ', ' ', ' '}, 
							{' ', ' ', ' '}, 
							{' ', ' ', ' '}
						};
		bool isGame = true;
		
	public:
		TicTacToe() : isGame(true) {}
};
int main() {
	
}
