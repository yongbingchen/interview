#include <iostream>
#include <vector>

using namespace std;

struct edge {
	int src;
	int dst;
	//int weight;
};

class graph {
	public:
		graph(vector <edge> &edges, int vertices)
		{
			adjacent.resize(vertices); //no better way to init a matrix with specific size, since the content remains will be overwrote bellow.
			for (auto &e : edges) {
				adjacent[e.src].push_back(e.dst);
				adjacent[e.dst].push_back(e.src); //undirected graph
			}
		}
		void dfs(int start, vector <bool> &visited, vector <int> &path)
		{
			visited[start] = true;
			path.push_back(start);

			for (auto &neighbor : adjacent[start]) {
				if (!visited[neighbor])
					dfs(neighbor, visited, path);
			}
		}

	private:
		vector <vector <int>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
	};

	int vertices = 13; //not edges.size(), it's the maximum vertex number + 1;
	graph g(edges, vertices);

	vector <int> path;
	for (int i = 1; i < vertices; i++) {
		path.clear();
		vector <bool> visited(vertices, false);
		g.dfs(i, visited, path);
		cout << "start from vertex " << i << endl;
		for (auto &j : path)
			cout << j << "->";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
