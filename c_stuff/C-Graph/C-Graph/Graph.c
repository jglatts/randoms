#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

Node* create_new_node(int d) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = d;
	n->edge_count = 0;
	return n;
}

int has_edge(Node* src, Node* dest) {
	for (int i = 0; i < src->edge_count; ++i) {
		// try to do a check with mem. as well
		if (src->edge_to[i]->data == dest->data) 
			return 1;
	}
	return 0;
}

void add_new_edge(Node* n, int new_data) {
	n->edge_to[n->edge_count++] = create_new_node(new_data);
}

void read_new_graph_file(char file_name[80]) {
	FILE* fp;
	errno_t err;
	int num_nodes, num_edges;

	if ((err = fopen_s(&fp, file_name, "r")) == 0) {
		fscanf_s(fp, "%d %d", &num_nodes, &num_edges);
		printf("Number of Nodes From File = %d\n", num_nodes);
		printf("Number of Edges From File = %d\n", num_edges);
		/*
		Come back and tweak this guy
		while (!feof(fp)) {
			int d1, d2;
			fscanf_s(fp, "%d %d", , &d1, &d2);
		}
		*/
	}
	else 
		printf("Could not open file");
	
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
