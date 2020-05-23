#include "WeightedGraph.h"

WeightedGraph::WeightedGraph(int s) {
	size = s;
}

WeightedGraph::WeightedGraph() {
	size = 0;
}

void WeightedGraph::addEdge(int u, int v, int w) {
	adj[u].push_back(v);
	cost[u].push_back(w);
}

void WeightedGraph::printGraph() {
	printf("\n---------------Printing Graph---------------\n");
	printf("Nodes = %d\n", size);
	for (int i = 0; i < size; ++i) {
		int x = i + 1;
		for (int j = 0; j < adj[x].size(); ++j) {
			printf("%d -> %d with cost of %d\n", x, adj[x].at(j), cost[x].at(j));
		}
	}
}

bool WeightedGraph::hasEdge(int source, int dest) {
	for (int i = 0; i < adj[source].size(); ++i) {
		if (adj[source].at(i) == dest) {
			printf("\nThere is a direct edge from %d to %d", source, dest);
			return true;
		}
	}
	printf("\nThere is no direct edge from %d to %d", source, dest);
	return false;
}

int WeightedGraph::findShortestPath(int source, int dest) {
	for (int i = 0; i < size; ++i) {
		dist[i] = INT_MAX;
	}
	queue.push(source); 
	dist[source] = 0;
	while (size != 0 && marked->size() != size - 1) {
		if (!queue.empty()) {
			int v = queue.front();
			queue.pop();
			marked->insert(v);  
			checkNeighbors(v);
		}
		else return -1;
	}
	return dist[dest];
}

void WeightedGraph::checkNeighbors(int v) {
	for (int i = 0; i < adj[v].size(); ++i) {
		int x = adj[v].at(i);
		int edgeDist = cost[v].at(i);
		int newDist = dist[v] + edgeDist;
		if (newDist < dist[x]) dist[x] = newDist;
		queue.push(x);
	}
}

void WeightedGraph::testGraph() {
	WeightedGraph wg(7);
	wg.addEdge(1, 2, 12);
	wg.addEdge(1, 3, 4);
	wg.addEdge(1, 4, 2);
	wg.addEdge(1, 6, 8);
	wg.addEdge(4, 5, 3);
	wg.addEdge(5, 2, 4);
	wg.addEdge(6, 7, 2);
	wg.printGraph();
	printf("Shortest Path From 1 -> 2 is %d\n", wg.findShortestPath(1, 2));
}


