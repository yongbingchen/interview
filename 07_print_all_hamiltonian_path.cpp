#include <iostream>
#include <vector>

using namespace std;

struct edge {
	int src;
	int dst;
	edge(int x, int y) : src(x), dst(y)
	{}
};

class graph {
	public:
		graph(vector <edge> edges, int vertices)
		{
			adjacent.resize(vertices);
			for (auto &e : edges) {
				adjacent[e.src].push_back(e.dst);
				adjacent[e.dst].push_back(e.src);
			}
		}

		void dfs_backtracking(int start, vector <int> &path, vector <bool> &visited)
		{
			//cout << "visiting node " << start << endl;
			visited[start] = true;
			path.push_back(start);
			if (path.size() == adjacent.size()) {
				cout << "got one hamiltonian path:" << endl;
				for (auto &i : path)
					cout << i << ", ";
				cout << endl;
				path.pop_back();
				visited[start] = false;
				//cout << "backtracking from " << start << endl;
				return;
			}

			for (auto &i : adjacent[start]) {
				if (!visited[i])
					dfs_backtracking(i, path, visited);
			}

			path.pop_back();
			visited[start] = false;
			//cout << "backtracking from " << start << endl;
		}

	private:
		vector <vector <int>> adjacent;

};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		edge(0, 1),
		edge(0, 2),
		edge(0, 3),
		edge(1, 2),
		edge(1, 3),
		edge(2, 3),
	};

	int vertices = 4;
	graph g(edges, vertices);
	vector <int>path;
	vector <bool>visited(vertices, false);
	g.dfs_backtracking(0, path, visited);

	exit(EXIT_SUCCESS);
}
