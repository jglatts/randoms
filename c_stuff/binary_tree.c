#include <stdio.h>
#include <time.h>
#include "binary_tree.h"

int main(int argc, char* argv[]) {
	srand(time(0));
	print_nodes(set_nodes_random(5, 5));
	return 0;
}

TreeNode* set_nodes_random(int val, int size) {
	// make this a BST
	TreeNode* root = set_random_root(val);
	TreeNode* current = root;
	for (int i = 1; i < size-1; ++i) {
		TreeNode* left =  (TreeNode*)malloc(sizeof(TreeNode));
		TreeNode* right = (TreeNode*)malloc(sizeof(TreeNode));
		left->data = (rand() % size) + 1;
		right->data = (rand() % size) + 1;
		current->left = left;
		current->right = right;
		if (i % 2 == 0) {
			current = left;
			right->left = NULL;
			right->right = NULL;
		}
		else {
			current = right;
			left->left = NULL;
			left->right = NULL;
		}
		current = (i % 2 == 0) ? left : right;
	}
	current->left = NULL;
	current->right = NULL;
	return root;
}

TreeNode* set_random_root(int val) {
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = val;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void print_nodes(TreeNode* node) {
	if (node == NULL) return;
	print_nodes(node->left);
	printf("%d (: ", node->data);
	print_nodes(node->right);
}