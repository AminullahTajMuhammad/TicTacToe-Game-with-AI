#include<iostream>
#include<cstdlib>
using namespace std;
class TreeNode {
public:
	int position;
	int score;
	char gameBox[3][3];
	TreeNode *child[9];
	TreeNode *parent;

	TreeNode() {
		position = -1;
		score = -1;
		initGameBox();
	}

	TreeNode(int s, int p) {
		position = p;
		score = s;
	}

	TreeNode(int s, int p, char box[3][3]) {
		position = p;
		score = s;
		copyGameBox(gameBox, box);
	}

	void initGameBox() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				gameBox[i][j] = ' ';
			}
		}
	}

	void copyGameBox(char original[3][3], char copyed[3][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				original[i][j] = copyed[i][j];
			}
		}
	}
};
