#include <iostream>
#include <vector>

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
			}
		}

		void get_transitive_closure(vector <vector <bool>> &connected)
		{
			for (int root = 0; root < vertices; root++) {
				dfs(root, root, connected);
			}
		}

	private:
		int vertices;
		vector <vector <int>> adjacent;

		void dfs(int root, int start, vector <vector <bool>> &connected)
		{
			if (connected[root][start]) //use connected as visited in normal dfs routine
				return;

			connected[root][start] = true;
			for (auto &v : adjacent[start]) {
				connected[root][v] = true;
				dfs(root, v, connected);
			}
		}
};

int main(int argc, char **argv)
{
	vector <edge> edges = {{0, 2}, {1, 0}, {3, 1}};
	int vertices = 4;

	graph g(edges, vertices);
	vector <vector <bool>> connected(vertices, vector <bool>(vertices, false));
	g.get_transitive_closure(connected);
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++)
			cout << connected[i][j] << ", ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
