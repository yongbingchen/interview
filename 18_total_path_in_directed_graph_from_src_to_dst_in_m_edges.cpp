#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge {
	int src;
	int dst;
};

struct node {
	int vertex;
	int dist;
	vector <int> path;
	node(int x, int y, vector <int> &z) : vertex(x), dist(y), path(z)
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
		int bfs(int start, int end, int m, vector <vector <int>> &paths)
		{
			queue <node> q;
			vector <int> tmp(1, start);
			q.push(node(start, 0, tmp));
			int num = 0;

			while(!q.empty()) {
				node v = q.front();
				q.pop();

				if (v.dist == m && v.vertex == end) {
					num++;
					paths.push_back(v.path);
				}

				if (v.dist > m)
					break;

				for (auto &e :  adjacent[v.vertex]) {
					vector <int> curr_path = v.path;
					curr_path.push_back(e.dst);
					q.push(node(e.dst, v.dist + 1, curr_path));
				}
			}
			return num;
		}

	private:
		vector <vector <edge>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{0, 6}, {0, 1}, {1, 6}, {1, 5}, {1, 2}, {2, 3}, {3, 4},
		{5, 2}, {5, 3}, {5, 4}, {6, 5}, {7, 6}, {7, 1}
	};
	int vertices = 8;
	graph g(edges, vertices);
	vector <vector <int>> paths;
	int ret = g.bfs(0, 3, 4, paths);
	cout << "total path from 0 to 3 in 4 steps is " << ret << endl;
	for (auto &i : paths) {
		for (auto &j : i)
			cout << j << ",";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
