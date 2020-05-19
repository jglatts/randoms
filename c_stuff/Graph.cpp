#include <time.h> 
#include <stdio.h>
#include <queue>
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

bool Graph::hasEdge(int from, int to) {
	for (int i = 0; i < adj[from].size(); ++i) {
		if (adj[from].at(i) == to) {
			printf("There is a direct edge from %d to %d", from, to);
			return true;
		}
	}
	printf("There is no direct edge from %d to %d", from, to);
	return false;
}

int Graph::findShortestPath(int from, int to) {
	queue<int> queue;
	bool marked[100] = { 0 }; 
	int distTo[100] = { -1 };
	marked[from] = true;
	distTo[from] = 0;
	queue.push(from);
	while (!queue.empty()) {
		int v = queue.front();
		queue.pop();
		for (int i = 0; i < adj[v].size(); ++i) {
			int u = adj[v].at(i);
			if (!marked[u]) {
				// add something to backtrack the nodes
				distTo[u] = distTo[v] + 1;
				marked[u] = true;
				queue.push(u);
			}
		}
	}
	return distTo[to];
}

void Graph::testGraph(int count) {
	Graph graph(count);
	int edges = 0;
	while (edges != (count*2)) {
		int nodeOne = (rand() % count) + 1;
		int nodeTwo = (rand() % count) + 1;
		graph.addEdge(nodeOne, nodeTwo);
		edges++;
	}
	graph.printGraph();
	graph.hasEdge(1, count);
	printf("\nShortest Path from 1 to %d is %d", count, graph.findShortestPath(1, count));
}


