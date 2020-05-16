#ifndef TREE_H
#define TREE_H

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};

class Tree {
public:
		Tree();
		void add(int);
		void print();
		void testTree(int);
	
private:
		void add(int, TreeNode*);
		void print(TreeNode*);
		TreeNode* setNewNode(int);
		TreeNode* root;
		int height;
		int size;

};
#endif 
