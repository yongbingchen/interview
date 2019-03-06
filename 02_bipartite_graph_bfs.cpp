#include <iostream>
#include <vector>
#include <queue>

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

		bool bfs(int v, vector <bool> &visited)
		{
			queue <int> q;
			vector <bool> color(adjacent.size(), false);

			q.push(v);
			color[v] = true;

			while(!q.empty()) {
				v = q.front();
				q.pop();
				visited[v] = true;

				for (auto &u : adjacent[v]) {
					if (!visited[u]) {
						q.push(u);
						color[u] = !color[v];
					}
					else {
						if (color[u] == color[v]) //criteria #1
							return false;
					}
				}
			}
			return true;
		}

	private:
		vector <vector <int>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
		{5, 9}, {8, 9}
		//{5, 9}, {8, 9}, {2, 4} // if we add 2->4 edge, graph is becomes non-Bipartite
	};

	int vertices = 11; //node 0, 10 is single, does not affect final result.
	graph g(edges, vertices);

	vector <bool> visited(vertices, false);
	for (int i = 0; i < vertices; i++) {
		if (!visited[i]) {
			bool ret = g.bfs(i, visited);
			if (!ret) {
				cout << "the graph is not bipartite" << endl;
				exit(EXIT_FAILURE);
			}
		}
	}

	cout << "the graph is bipartite" << endl;
	exit(EXIT_SUCCESS);
}
