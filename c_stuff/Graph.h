#include <vector>
using namespace std;

class Graph {
public:
	Graph(int v);
	Graph() { };
	void addEdge(int, int);
	void printGraph();
	void testGraph(int);
private:
	vector<int> adj[100];
	int size;
};
	