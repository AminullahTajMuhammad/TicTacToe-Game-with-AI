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

	void addChildInRoot(TreeNode *child) {
		TreeNode *temp = new TreeNode();
		if (root == NULL) {
			return;
		}

		child->addChild(root);
	}
	
	void addChild(TreeNode *parent, TreeNode *child) {
		if (parent == NULL) {
			return;
		}
		if (child == NULL) {
			return;
		}

		child->parent = parent;
		
	}
};
