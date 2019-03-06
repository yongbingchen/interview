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
		graph(vector <edge> &edges, int v)
		{
			vertices = v;
			adjacent.resize(v);
			for (auto &e : edges) {
				adjacent[e.src].push_back(e.dst);
				adjacent[e.dst].push_back(e.src);
			}
		}

		bool dfs(int start, vector <bool> &visited, vector <bool> &color)
		{
			if (visited[start])
				return true;

			visited[start] = true;
			for (auto &i : adjacent[start]) {
				if (!visited[i]) {
					color[i] = !color[start];
					if (!dfs(i, visited, color))
						return false;
				}
				else if (color[i] == color[start]) {
					return false;
				}
			}

			return true;
		}


		bool bfs(int start, vector <bool> &visited, vector <bool> &color)
		{
			queue <int> q;
			q.push(start);

			while(!q.empty()) {
				int u = q.front();
				visited[u] = true;
				q.pop();

				for (auto &v : adjacent[u]) {
					if (!visited[v]) {
						color[v] = !color[u];
						q.push(v);
					}
					else {
						if (color[v] == color[u])
							return false;
					}
				}
			}

			return true;
		}

	private:
		int vertices;
		vector <vector <int>> adjacent;


};


int main(int argc, char **argv)
{
	vector <edge> edges = {
		//{1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7}, {5, 9}, {8, 9}, {2, 4}
		{1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7}, {5, 9}, {8, 9}
	};



	int vertices = 10; //not edges.size(), it's the maximum vertex number + 1;
	graph g(edges, vertices);

	vector <bool> visited(vertices, false);
	vector <bool> color(vertices);
	color[1] = true;
	bool ret = g.bfs(1, visited, color);
	cout << "graph is bipartite " << ret << endl;

	exit(EXIT_SUCCESS);
}
