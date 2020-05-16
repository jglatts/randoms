#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

Tree::Tree() { 
	root = NULL;
}

void Tree::add(int val) {
	if (root == NULL) {
		root = new TreeNode;
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	}
	else add(val, root);
}

void Tree::add(int val, TreeNode* leaf) {
	if (leaf->left == NULL)       leaf->left  = setNewNode(val);
	else if (leaf->right == NULL) leaf->right = setNewNode(val);
	else add(val, leaf->left);
}

TreeNode* Tree::setNewNode(int val) {
	TreeNode* node = new TreeNode;
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void Tree::testTree(int size) {
	Tree tree;
	tree.add(69);
	tree.add(420);
	tree.add(26);
	tree.add(15);
	tree.add(180);
	tree.add(2);
	tree.print(tree.root);
}

void Tree::print(TreeNode* leaf) {
	if (leaf == NULL) return;
	printf("%d ", leaf->data);
	print(leaf->left);
	print(leaf->right);
}

void Tree::print() {
	print(this->root);
}
