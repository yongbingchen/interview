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

		void bfs(queue <int> &q, vector <bool> &visited, vector <int> &result)
		{
			if (q.empty())
				return;

			int v = q.front();
			q.pop();
			visited[v] = true;
			result.push_back(v);
			for (auto &u : adjacent[v]) {
				if (!visited[u])
					q.push(u);
			}
			bfs(q, visited, result);
		}
	private:
		vector <vector <int>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
		// vertex 0, 13 and 14 are single nodes
	};
	int vertices = 15;

	graph g(edges, vertices);
	queue<int> q;
	vector <bool> visited(vertices, false);
	vector <int> result;
	for (int i = 0; i < vertices; i++) {
		if (!visited[i])
			q.push(i);
		g.bfs(q, visited, result);
	}
	for (auto &i : result)
		cout << i << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
