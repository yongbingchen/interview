#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

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
	vector <int> path;
	node(int x, int y, vector <int> &z) : vertex(x), cost(y), path(z)
	{}
};

class graph {
public:
	graph(vector <edge> &edges, int vertices)
	{
		adjacent.resize(vertices);
		for (auto &e : edges) {
			adjacent[e.src].push_back(e);
			adjacent[e.dst].push_back(edge(e.dst, e.src, e.weight));
			//adjacent[e.dst].push_back(e);//for undirected graph, this can not add backward connections.
		}
	}

	int revised_bfs(int start, int threshold, vector <int> &path)
	{
		queue <node> q;
		vector <int> curr_path = {start};
		q.push(node(start, 0, curr_path));
		int max_cost = INT_MIN;

		while(!q.empty()) {
			node v = q.front();
			q.pop();

			if (v.cost > threshold) {
				if (v.cost > max_cost) {
					path = v.path;
					max_cost = v.cost;
				}
			}

			for (auto &e : adjacent[v.vertex]) {
				//only go ahead if neighbor e.src is not in current path (a cycle)
				//removed visited[e.dst] condition as in normal bfs, to iterate over all potential path without cycle.
				if (find(v.path.begin(), v.path.end(), e.dst) == v.path.end()) {
					vector <int> tmp = v.path;
					tmp.push_back(e.dst);
					q.push(node(e.dst, v.cost + e.weight, tmp));
					cout << "add neighbor " << e.dst << " to curr_path, update path cost through this vertex to " << v.cost + e.weight << endl;
				}
			}
		}

		return max_cost;
	}

private:
	vector <vector <edge>> adjacent;
};

int main(int argc, char **argv)
{
	vector<edge> edges =
	{
		{0, 6, 11}, {0, 1, 5}, {1, 6, 3}, {1, 5, 5}, {1, 2, 7},
		{2, 3, -8}, {3, 4, 10}, {5, 2, -1}, {5, 3, 9}, {5, 4, 1},
		{6, 5, 2}, {7, 6, 9}, {7, 1, 6}
	};

	int vertices = 8;

	graph g(edges, vertices);
	vector <int> path;
	int ret = g.revised_bfs(0, 40, path);
	cout << "maximum path cost is " << ret << endl;
	for (auto &i : path)
		cout << i << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}

