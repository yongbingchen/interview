#include <iostream>
#include <vector>
/*
2-edge connected graph means the graph is always connected if we remove any edge of that graph.

In DFS tree an edge (u->v) is bridge if there does not exist any other alternative to reach u or an ancestor of u from subtree rooted with v.
*/

using namespace std;

struct edge {
	int src;
	int dst;
};

class graph {
	public:
		graph(vector <edge> &edges, int vertices)
		{
			adjacent.resize(vertices);
			for (auto &i : edges) {
				adjacent[i.src].push_back(i.dst);
				adjacent[i.dst].push_back(i.src);
			}
		}

		int dfs(int start, vector <bool> &visited, int &discover_order, vector <int> &vertex_discover_order, int parent)
		{
			visited[start] = true;
			discover_order++;

			vertex_discover_order[start] = discover_order;
			cout << "vertex " << start << " visit order is " << discover_order << endl;
			int highest_subtree_order = discover_order; //less visit order number means the node is higher at dfs subtree, earlier to be discovered.
			for (auto &i : adjacent[start]) {
				if (!visited[i]) {
					int tmp = dfs(i, visited, discover_order, vertex_discover_order, start);
					if (tmp > vertex_discover_order[start]) {
						cout << "found dfs subtree rooted from vertex " << i << ", does not has any edge connected to any ancestor of its parent vertex " << start << endl;
						cout << "because the highest discover order in this subtree is " << tmp << ", which is later than its parent node visit order " <<  vertex_discover_order[start] << endl;
						cout << "so edge (" << start << ", " << i << ") is a bridge, means the graph does not have 2-edge connectivity" << endl;
					}
					highest_subtree_order = min(highest_subtree_order, tmp);
				}
				else if (i != parent){ //for undirected graph only.
					//we found one cycle here.
					//cout << "vertext " << i << " is vertex " << start << "'s child, while also its ancestor: a cycle" << endl;
					//this is the key of 2-edge connectivity, without this cycle, there must be some bridges in the graph.
					//cout << "in cycle cond, parent order " << vertex_discover_order[start] << ", child order " << vertex_discover_order[i] << endl;
					//THIS sentence reflect the fact that we can reach the subtree at earlier discover time.
					highest_subtree_order = min(vertex_discover_order[start], vertex_discover_order[i]);
				}

			}

			cout << "dfs subtree rooted from vertex " << start << ", its highest visit order is " << highest_subtree_order << endl;
			return highest_subtree_order;
		}


	private:
		vector <vector <int>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {5, 6}, {6, 7}
	};

	int vertices = 10;
	graph g(edges, vertices);
	int discover_order = 0;
	vector <bool> visited(vertices, false);
	vector <int> vertex_discover_order(vertices, -1);

	//since the graph is connected, so a dfs start from one vertex can travel through all.
	g.dfs(0, visited, discover_order, vertex_discover_order, -1);

	exit(EXIT_SUCCESS);
}
