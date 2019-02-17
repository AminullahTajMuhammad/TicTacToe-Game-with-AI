#include<iostream>
#include<cstdlib>
#include"TreeNode.h"
using namespace std;
class TicTacToeTree {
public:
	TreeNode *root;
	int childCount = 0;
	
	TicTacToeTree() {
		root = NULL;
		childCount = -1;
	}
	
	void addNodes(char box[][3]) {
		TreeNode *temp = new TreeNode();
	}

	void addChildInRoot(TreeNode *child) {
		TreeNode *temp = new TreeNode();
		if (root == NULL) {
			return;
		}

		child->addChild(root);
	}
	
	void addChild(TreeNode *parent, TreeNode *child) {

	}

	void removeChild() {

	}

	void  removeLeafChild() {

	}
};
