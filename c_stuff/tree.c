#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct  TreeNode {
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
} TreeNode;

TreeNode* set_random_root(int);
TreeNode* set_nodes_random(int, int);
TreeNode* set_children_nodes(int, int);
TreeNode* val_ptr;
void print_nodes(TreeNode*, int);
int val_found;

int main(int argc, char* argv[]) {
        int n, k;
        srand(time(0));
        printf("------------JDG GRAPH------------\n");
        printf("How Many Nodes In The Graph? -> ");
        scanf("%d", &n);
        printf("Value To Search For? -> ");
        scanf("%d", &k);
        print_nodes(set_nodes_random(5, n), k);
        if (val_found){
                 printf("Your Value %d Was Found!\n", k);
                 printf("At Node %p!\n", val_ptr); // prolly can use the int's addrss
        }
        else printf("Your Value %d Was Not Found :(\n", k);
        return 0;
}

TreeNode* set_nodes_random(int val, int size) {
        // make this a BST
        TreeNode* root = set_random_root(val);
        TreeNode* current = root;
        int i;
        for (i = 1; i < size - 1; ++i) {
                TreeNode* left = (TreeNode*)malloc(sizeof(TreeNode));
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

void print_nodes(TreeNode* node, int k) {
        if (node == NULL) return;
        if (node->data == k) {
                val_found = 1;
                val_ptr = node;
        }
        print_nodes(node->left, k);
        printf("Node Value = %d\nAddress %p\n\n", node->data, node);
        print_nodes(node->right, k);
}
