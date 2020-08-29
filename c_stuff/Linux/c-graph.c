#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Graph Nodes */
typedef struct Node {
	int data;
	int edge_count;
	struct Node* edge_to[10];	// max of 10 edges for now
} Node;

/* Pointer To Array Of Nodes In Graph */
struct Node* all_nodes[50];
int _count;

/* Function Prototypes */
Node* create_new_node(int);
Node* get_node_handle(int);
int has_edge(Node*, Node*);
int graph_contains_node(int);
void add_new_edge(Node*, int);
void read_new_graph_file(char[80]);
void print_edge_info(Node*);
void print_all_nodes();

Node* create_new_node(int d) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = d;
	n->edge_count = 0;
	return n;
}

int has_edge(Node* src, Node* dest) {
	int i;
	for (i = 0; i < src->edge_count; ++i) {
		// try to do a check with mem. as well
		if (src->edge_to[i]->data == dest->data)
			return 1;
	}
	return 0;
}

void add_new_edge(Node* n, int new_data) {
	n->edge_to[n->edge_count++] = create_new_node(new_data);
}

/*
void read_new_graph_file(char file_name[80]) {
	FILE* fp;
	int err;
	int num_nodes, num_edges;
	int nodes_arr[20];

	if ((err = fopen(&fp, file_name, "r")) == 0) {
		fscanf(fp, "%d %d", &num_nodes, &num_edges);
		printf("Number of Nodes From File = %d\n", num_nodes);
		printf("Number of Edges From File = %d\n", num_edges);
		while (!feof(fp)) {
			int src, dest;
			fscanf(fp, "%d %d", &src, &dest);
			if (!graph_contains_node(src)) {
				Node* n = create_new_node(src);
				add_new_edge(n, dest);
				all_nodes[_count++] = n;
			}
			else {
				Node* n = get_node_handle(src);
				add_new_edge(n, dest);
			}
		}
	}
	else
		printf("Could not open file");
}
*/

int graph_contains_node(int d) {
	int i;
	for (i = 0; i < _count; ++i) {
		if (all_nodes[i]->data == d) {
			return 1;
		}
	}
	return 0;
}

Node* get_node_handle(int d) {
	int i;
	for (i = 0; i < _count; ++i) {
		Node* n = all_nodes[i];
		if (n->data == d) {
			return n;
		}
	}
	return NULL;
}


void print_edge_info(Node* n) {
	if (n->edge_count > 0) {
		printf("Edges From %d: ", n->data);
		for (int i = 0; i < n->edge_count; ++i) {
			printf("%d ", n->edge_to[i]->data);
		}
		printf("\n");
	}
	else
		printf("No Edges From %d\n", n->data);
}

void print_all_nodes() {
	int i, x;
	for (i = 0; i < _count; ++i) {
		Node* n = all_nodes[i];
		printf("Edges from %d: ", n->data);
		for (x = 0; x < n->edge_count; ++x) {
			printf("%d ", n->edge_to[x]->data);
		}
		printf("\n");
	}
}

void test() {
	Node* n = create_new_node(5);
	Node* n2 = create_new_node(1200);
	add_new_edge(n, 69);
	add_new_edge(n, 420);
	add_new_edge(n, 100);
	add_new_edge(n, 85);
	add_new_edge(n, 32);
	add_new_edge(n->edge_to[3], 26);
	add_new_edge(n->edge_to[3], 58);
	add_new_edge(n->edge_to[3], 11);
	print_edge_info(n);
	print_edge_info(n->edge_to[2]);
	print_edge_info(n->edge_to[3]);
	if (has_edge(n, n2)) printf("Edge Found");
	else                 printf("Edge Not Found Between %d and %d", n->data, n2->data);
}

void main() {
	test();
	//read_new_graph_file("txtgraph.txt");
	//print_all_nodes();
}
