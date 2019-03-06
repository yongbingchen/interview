#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//DAG: directed acyclic graph,
//If a vertex can reach itself via a nontrivial path (a path with one or more edges), then that path is a cycle, so another way to define directed acyclic graphs is that they are the graphs in which no vertex can reach itself via a nontrivial path.
//Topological sorting:
//a linear ordering of a graph's vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.  A topological ordering is possible if and only if the graph has no directed cycles, that is, if it is a directed acyclic graph (DAG).
//Any DAG has at least one topological ordering.
//The canonical application of topological sorting is in scheduling a sequence of jobs or tasks based on their dependencies, generating function call graph.


/*why use dfs to perform topological sort*/
/*
1. dfs travel through a DAG graph, let f(x) be vertex x's departure time (first enter, last out).
2. if there's a edge u->v in DAG, then f(u) must greater than f(v).
3. so reverse the set of f(x), then we get one of the topological sort of the DAG.
*/
struct edge {
	int src;
	int dst;
};

class graph {
	public:
		graph(vector <edge> &edges, int vertices)
		{
			adjacent.resize(vertices);
			for (auto &e : edges) {
				adjacent[e.src].push_back(e.dst);
			}
		}

		void dfs(int start, vector <bool> &visited, vector <int> &departure, int &departure_time)
		{
			visited[start] = true;
			for (auto &neighbor : adjacent[start]) {
				if (!visited[neighbor]) {
					dfs(neighbor, visited, departure, departure_time);
				}
			}
			//first these two line can not move above the subtree dfs call
			//second their sequence can not be reversed.
			departure[departure_time] = start;
			departure_time++;
		}

		void topological_sort(int vertices, vector <int> &departure)
		{
			vector <bool> visited(vertices, false);
			int departure_time = 0;

			//DAG is not guaranteed a connected graph, so need to travel from each vertex.
			for (int i = 0; i < vertices; i++) {
				if (!visited[i])
					dfs(i, visited, departure, departure_time);
			}
		}

	private:
		vector <vector <int>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0}, {3, 4},
		{5, 1}, {7, 0}, {7, 1}
	};

	int vertices = 8;
	graph g(edges, vertices);
	vector <int> departure(vertices, -1);

	g.topological_sort(vertices, departure);
	for (auto it = departure.rbegin(); it != departure.rend(); it++) {
		cout << *it << ", ";
	}
	cout << endl;

	exit(EXIT_SUCCESS);
}


/*
Why DFS complexity is O(V+E).

Say, you have a connected graph with V nodes and E edges.

In DFS, you traverse each node exactly once. Therefore, the time complexity of DFS is at least O(V).

Now, any additional complexity comes from how you discover all the outgoing paths or edges for each node which, in turn, is dependent on the way your graph is implemented. If an edge leads you to a node that has already been traversed, you skip it and check the next. Typical DFS implementations use a hash table to maintain the list of traversed nodes so that you could find out if a node has been encountered before in O(1) time (constant time).

If your graph is implemented as an adjacency matrix (a V x V array), then, for each node, you have to traverse an entire row of length V in the matrix to discover all its outgoing edges. Please note that each row in an adjacency matrix corresponds to a node in the graph, and the said row stores information about edges stemming from the node. So, the complexity of DFS is O(V * V) = O(V^2).

If your graph is implemented using adjacency lists, wherein each node maintains a list of all its adjacent edges, then, for each node, you could discover all its neighbors by traversing its adjacency list just once in linear time. For a directed graph, the sum of the sizes of the adjacency lists of all the nodes is E (total number of edges). So, the complexity of DFS is O(V) + O(E) = O(V + E).

For an undirected graph, each edge will appear twice. Once in the adjacency list of either end of the edge. So, the overall complexity will be O(V) + O (2E) ~ O(V + E).
There are different other ways to implement a graph. You can reason the complexity accordingly.
I hope, the above explanation makes sense.
*/
