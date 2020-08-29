#pragma once

/* Graph Nodes */
typedef struct Node {
	int data;
	int edge_count;
	struct Node* edge_to[10];	// max of 10 edges for now
} Node;	

/* Function Prototypes */
Node* create_new_node(int);
int has_edge(Node*, Node*);
void add_new_edge(Node*, int);
void read_new_graph_file(char[80]);
void print_edge_info(Node*);
	