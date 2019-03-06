#include <iostream>
#include <vector>

using namespace std;

struct edge {
	int src;
	int dst;
};

class graph {
	public:
		graph(vector <edge> &edges, int vert)
		{
			vertices = vert;
			adjacent.resize(vertices);
			reverse_adj.resize(vertices);
			for (auto &i : edges) {
				adjacent[i.src].push_back(i.dst);
				reverse_adj[i.dst].push_back(i.src);
			}
		}

		void dfs(int start, vector <bool> &visited, vector <int> &path, bool reverse)
		{
			visited[start] = true;

			path.push_back(start);
			for(auto &i: reverse ? reverse_adj[start] : adjacent[start]) {
				if (!visited[i])
					dfs(i, visited, path, reverse);
			}
		}
		bool is_strongly_connected(void)
		{
			vector <int> path;
			vector <bool> visited(vertices, false);
			dfs(0, visited, path, false);
			if (path.size() != vertices) {
				cout << "can not reach every node when dfs from vertex 0" << endl;
				return false;
			}

			path.clear();
			vector <bool> visited_reverse(vertices, false);
			dfs(0, visited_reverse, path, true);
			if (path.size() != vertices) {
				cout << "can not reach every node when reverse dfs from vertex 0" << endl;
				return false;
			}

			return true;
		}

	private:
		int vertices;
		vector <vector <int>> adjacent;
		vector <vector <int>> reverse_adj;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		//{0, 4}, {1, 3}, {1, 2}, {2, 1}, {2, 4}, {3, 1}, {3, 2}, {4, 3} //not
		{0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4}, {3, 1}, {3, 2}, {4, 3}
	};

	int vertices = 5;
	graph g(edges, vertices);
	cout << "is graph strongly connected? " << g.is_strongly_connected() << endl;

	exit(EXIT_SUCCESS);
}
