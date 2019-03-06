#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge {
	int src;
	int dst;
};

struct node {
	int vertex;
	int dist;
	node(int x, int y) : vertex(x), dist(y)
	{}
};

class graph {
public:
	graph(vector <edge> &edges, int v)
	{
		vertices = v;
		adjacent.resize(v);
		for (auto &e : edges)
			adjacent[e.src].push_back(e.dst);
	}

	int bfs_revised(int src, int dst, int steps)
	{
		queue <node> q;
		int total_path = 0;
		vector <bool> visited(vertices, false);

		q.push(node(src, 0));
		while(!q.empty()) {
			node u = q.front();
			q.pop();
			//remove this from standard bfs, because we are
			//looking for 'all' path, a vertex can appear in different path.
			//visited[u.vertex] = true;
			//modify bfs by use total step to break graph cycle
			//usually this is the 'visited''s function.
			if (u.dist > steps)
				break;

			for (auto &v : adjacent[u.vertex]) {
				//if (!visited[v])
				q.push(node(v, u.dist + 1));
				if (v == dst && u.dist + 1 == steps)
					total_path++;
			}
		}

		return total_path;
	}
#if 0
	//compare to question 13, shortest path from src to dst in m steps._ 
	int bfs_shortest_dist(int src, int dst, int m)
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
#endif

	int bfs_failed(int src, int dst, int steps)
	{
		queue <int> q;
		int total_path = 0;
		vector <bool> visited(vertices, false);
		vector <int> dist(vertices, INT_MAX);

		dist[src] = 0;
		q.push(src);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			//visited[u] = true;

			for (auto &v : adjacent[u]) {
				if (!visited[v]) {
					dist[v] = dist[u] + 1;
					//WRONG! a vertex may be discovered (not visited) severalseveral times in a bfs,
					//so use vector [vertex] to track path is not feasible.
					//THIS is why need use a 'node' queue, instead of only 'int' queue to hold path.
					if (v == dst && dist[v] == steps) {
						total_path++;
					}
					q.push(v);
				}
			}
		}

		return total_path;
	}

private:
	int vertices;
	vector <vector <int>> adjacent;
};


int main(int argc, char **argv)
{
	vector <edge> edges = {
		{0, 6}, {0, 1}, {1, 6}, {1, 5}, {1, 2}, {2, 3}, {3, 4},
		{5, 2}, {5, 3}, {5, 4}, {6, 5}, {7, 6}, {7, 1}
	};
	int vertices = 8;
	graph g(edges, vertices);
	int ret = g.bfs_revised(0, 3, 4);
	cout << "total path from 0 to 3 in 4 steps is " << ret << endl;

	exit(EXIT_SUCCESS);
}
