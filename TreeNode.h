#include<iostream>
#include<cstdlib>
using namespace std;
class TreeNode {
public:
	
	// Data of treeNode
	int position;
	int score;
	int childSize = 0;
	char gameBox[3][3];
	
	// References
	TreeNode *children[9];
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
	
	void addChild(TreeNode *child) {
		if(childSize < 0 || childSize > 8) {
			return;
		}
		if(child == NULL) {
			return;
		}
		
		
		children->parent = this;
		children[childSize++] = child;
		childSize++;
		
	}
	
	void removeChild(TreeNode *child) {
		if (child == NULL) {
			return;
		}

		children[childSize] = NULL;
		childSize--;
	}
};
