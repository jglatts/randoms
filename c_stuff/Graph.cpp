#include <time.h> 
#include <stdio.h>
#include "Graph.h"

Graph::Graph(int v) {
	srand(time(0));
	size = v;
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::printGraph() {
	printf("\n---------------Printing Graph---------------\n");
	for (int i = 0; i < size; ++i) {
		int x = i + 1;
		printf("%d -> ", x);
		for (int j = 0; j < adj[x].size(); ++j) {
			printf("%d ", adj[x].at(j));
		}
		printf("\n");
	}
}

void Graph::testGraph(int count) {
	Graph graph(count);
	int edges = 0;
	while (edges != (count * 2)) {
		int nodeOne = (rand() % count) + 1;
		int nodeTwo = (rand() % count) + 1;
		graph.addEdge(nodeOne, nodeTwo);
		edges++;
	}
	graph.printGraph();
}

