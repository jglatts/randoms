typedef struct  Node {
	int data;
	struct Node* next;
} Node;

int get_input();
int check_list(Node*, int);
Node* set_nodes(int);
void print_nodes(Node*);
void test_linked_list();
