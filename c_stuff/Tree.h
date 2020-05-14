#ifndef TREE_H
#define TREE_H

class Tree {

	struct TreeNode {
		int data;
		TreeNode* left;
		TreeNode* right;
	};

	public:
		Tree();
		void add(int);
		void print();
	
	private:
		TreeNode* root;
		int height;
		int size;

};

#endif 
