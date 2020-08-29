#include "Graph.h"

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
	//test();
	read_new_graph_file("txtgraph.txt");
}