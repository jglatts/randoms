typedef struct  TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode* set_random_root(int);
TreeNode* set_nodes_random(int, int);
TreeNode* set_children_nodes(int, int);
void print_nodes(TreeNode*);


