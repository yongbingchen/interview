#include <iostream>
#include <vector>

using namespace std;

struct edge {
	int src;
	int dst;
};

class graph {
	public:
		graph(vector <edge> edges, int vertices)
		{
			adjacent.resize(vertices);

			for (auto &i : edges) {
				adjacent[i.src].push_back(i.dst);
			}
		}

		bool dfs(int start, vector <bool> &visited, vector <bool> &recur_stack)
		{
			visited[start] = true;

			recur_stack[start] = true;
			for (auto &i : adjacent[start]) {
				if (!visited[i]) {
					if (dfs(i, visited, recur_stack))
						return true;
				}
				else {
					if (recur_stack[i]) {
						cout << "node " << i << " already in recursive stack while visiting node " << start << endl;
						return true;
					}
				}
			}
			recur_stack[start] = false;

			return false;
		}

		bool detect_cycle(int vertices)
		{
			vector <bool> visited(vertices, false);
			vector <bool> recurs_stack(vertices, false);
			for (int i = 0; i < vertices; i++) {
				if (!visited[i] && dfs(i, visited, recurs_stack))
					return true;
			}
			return false;
		}

	private:
		vector <vector <int>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		{3, 5}, {9, 8}, {8, 12}, {9, 10}, {11, 9}, {12, 11}
	//	{3, 5}, {9, 8}, {8, 12}, {9, 10}, {11, 9}
	};

	int vertices = 13;

	graph g(edges, vertices);
	cout << "does graph have a cycle? " << g.detect_cycle(vertices) << endl;

	exit(EXIT_SUCCESS);
}
