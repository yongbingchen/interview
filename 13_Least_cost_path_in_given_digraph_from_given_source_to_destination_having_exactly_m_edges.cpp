#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge {
	int src;
	int dst;
	int weight;
	edge(int x, int y, int z) : src(x), dst(y), weight(z)
	{}
};

struct node {
	int vertex;
	int cost;
	int steps;
	node(int x, int y, int z) : vertex(x), cost(y), steps(z)
	{}
};

class graph {
public:
	graph(vector <edge> &edges, int vertices)
	{
		adjacent.resize(vertices);
		for (auto &e : edges)
			adjacent[e.src].push_back(e);
	}

	int revised_bfs(int start, int end, int m)
	{
		queue <node> q;
		q.push(node(start, 0, 0));
		int min_cost = INT_MAX;

		while(!q.empty()) {
			node v = q.front();
			q.pop();

			//bfs guarantee that all nodes at same level/steps will be visited before below break condition.
			if (v.vertex == end && v.steps == m)
				min_cost= min(v.cost, min_cost);

			if (v.steps > m) //this will break any cycle in the graph, so do not need to care about that case.
				break;

			for (auto &e : adjacent[v.vertex]) {
				q.push(node(e.dst, v.cost + e.weight, v.steps + 1)); //correct way to keep track of steps for individual vertex, do not try to use some flag in the loop.
			}
		}

		return min_cost;
	}

private:
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
	int ret = g.revised_bfs(src, dest, m);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
