#pragma once
#include <iostream>
#include <limits.h>
#include <time.h> 
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>

class WeightedGraph {
public:
	WeightedGraph(int);
	WeightedGraph();
	void addEdge(int, int, int);
	void printGraph();
	static void testGraph();
	bool hasEdge(int, int);
	int findShortestPath(int, int);
	void checkNeighbors(int);
private:
	std::vector<int> adj[100];
	std::vector<int> cost[100];
	std::set<int> marked[100];
	std::queue<int> queue;
	int dist[100];
	int size;
};

