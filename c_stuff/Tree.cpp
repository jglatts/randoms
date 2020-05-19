#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tree.h"
using namespace std;

Tree::Tree() { 
	srand(time(0));
	root = NULL;
}

void Tree::add(int val) {
	if (root == NULL) root = setNewNode(val);
	else add(val, root);
}

void Tree::add(int val, TreeNode* leaf) {
	if (val <= leaf->data) {
		if (leaf->left == NULL) leaf->left = setNewNode(val);
		else add(val, leaf->left);
	}
	else {
		if (leaf->right == NULL) leaf->right = setNewNode(val);
		else add(val, leaf->right);
	}
}

TreeNode* Tree::setNewNode(int val) {
	TreeNode* node = new TreeNode;
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bool Tree::contains(int val) {
	return contains(val, this->root);
}

bool Tree::contains(int val, TreeNode* leaf) {
	if      (leaf == NULL)     return false;
	else if (val > leaf->data) return contains(val, leaf->right);
	else if (val < leaf->data) return contains(val, leaf->left);
	else                       return true;
}

void Tree::print(TreeNode* leaf) {
	// pre-order print
	if (leaf == NULL) return;
	printf("%d\n", leaf->data);
	print(leaf->left);
	print(leaf->right);
}

void Tree::print() {
	print(this->root);
}

void Tree::testTree(int size) {
	Tree tree;
	for (int i = 0; i < size; ++i)
		tree.add((rand() % size) + 1);
	tree.print();
	// add a test for the contains
}
