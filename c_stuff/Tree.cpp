#include <stdio.h>
#include "Tree.h"

Tree::Tree() { }

void Tree::add(int v) {
	TreeNode* node = new TreeNode;
	node->data = v;

	if (root == NULL) {
		root = node;
		node->left = NULL;
		node->right = NULL;
	}

	else {
		TreeNode* current = root;
		while (current != null) {
			if (current->left == NULL) {
				current->left = node;
				current->right = NULL;
			}
			else if (current->right == NULL) {
				current->left = NULL;
				current->right = node;
			}
			else current = current->left;
		}
	}

}
	
