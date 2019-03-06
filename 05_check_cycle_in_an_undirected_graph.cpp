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

		bool detect_cycle_bfs(void)
		{
			vector <bool> visited(vertices, false);

			for (int i = 0; i < vertices; i++) {
				if (!visited[i])
					if (bfs(i, visited))
						return true;
			}

			return false;
		}

		bool detect_cycle_dfs(void)
		{

			vector <bool> visited(vertices, false);
			for (int i = 0; i < vertices; i++) {
				if (!visited[i]) {
					vector <bool> dfs_stack(vertices, false);
					if (dfs(i, visited, dfs_stack, -1))
						return true;
				}
			}

			return false;
		}
	private:
		int vertices;
		vector <vector <int>> adjacent;

		bool bfs(int start, vector <bool> &visited)
		{
			queue <int> q;
			q.push(start);

			vector <int> pred(vertices, -1);
			while(!q.empty()) {
				int u = q.front();
				q.pop();
				visited[u] = true;

				for (auto &v : adjacent[u]) {
					if (!visited[v]) {
						q.push(v);
						pred[v] = u;
					}
					else {
						if (pred[u] != v)
							return true;
					}
				}
			}
			return false;
		}

		//dfs solution is way more tricky than bfs solution.
		bool dfs(int start, vector <bool> &visited, vector <bool> &dfs_stack, int parent)
		{
			visited[start] = true;
			dfs_stack[start] = true;
			for (auto &v : adjacent[start]) {
				if (!visited[v]) {
					if (dfs(v, visited, dfs_stack, start))
						return true;
				}
				else {
					if (dfs_stack[v] && parent != v)
						return true;
				}
			}
			dfs_stack[start] = false; //backtracking

			return false;
		}



};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		//{3, 5}, {9, 8}, {8, 12}, {9, 10}, {11, 9}, {12, 11}
		{3, 5}, {9, 8}, {8, 12}, {9, 10}, {11, 9}
	};

	int vertices = 13;
	graph g(edges, vertices);

	cout << "does graph have a cycle bfs ? " << g.detect_cycle_bfs() << endl;
	cout << "does graph have a cycle dfs ? " << g.detect_cycle_dfs() << endl;

	exit(EXIT_SUCCESS);
}
