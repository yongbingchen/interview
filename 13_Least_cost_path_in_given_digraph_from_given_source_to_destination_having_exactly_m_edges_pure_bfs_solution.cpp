#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge {
	int src;
	int dst;
	int weight;
};

class graph {
public:
	graph(vector <edge> &edges, int v)
	{
		vertices = v;
		adjacent.resize(v);
		for (auto &e : edges)
			adjacent[e.src].push_back(e);
	}

	int bfs(int src, int dst, int m)
	{
		queue <int> q;
		q.push(src);
		int min_dist = INT_MAX;

		vector <bool> visited(vertices, false);
		vector <int> cost(vertices, INT_MAX);
		vector <int> dist(vertices, 0);
		cost[src] = 0;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			visited[u] = true;

			for (auto &e : adjacent[u]) {
				if (!visited[e.dst]) {
					q.push(e.dst);
					//cost[e.dst] = cost[e.src] + e.weight;
					//WRONG!, a vertex may be visited multiple time in a bfs, from diffrent predecessor
					cost[e.dst] = min(cost[e.dst], cost[e.src] + e.weight);
					dist[e.dst] = dist[e.src] + 1;
					if (e.dst == dst && dist[e.dst] == m)
						min_dist = min(min_dist, cost[e.dst]);
				}
			}
		}

		return min_dist;
	}
private:
	int vertices;
	vector <vector <edge>> adjacent;
};


int main(int argc, char **argv)
{
	vector<edge> edges = {
		{0, 6, -1}, {0, 1, 5}, {1, 6, 3}, {1, 5, 5}, {1, 2, 7},
		{2, 3, 8}, {3, 4, 10}, {5, 2, -1}, {5, 3, 9}, {5, 4, 1},
		{6, 5, 2}, {7, 6, 9}, {7, 1, 6}
	};
	int vertices = 8;
	graph g(edges, vertices);

	int src = 0, dest = 3, m = 4;
	int ret = g.bfs(src, dest, m);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
