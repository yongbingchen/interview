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

class graph {
public:
	graph(vector <edge> &edges, int vertices)
	{
		adjacent.resize(vertices);
		for (auto &e : edges)
			adjacent[e.src].push_back(e);
	}

	int max_flow(int start, int end)
	{
		bool ret;
		int max_flow = 0;
		do {
			vector <bool>visited(adjacent.size(), false);
			vector <int>pred(adjacent.size(), -1);
			int path_flow = INT_MAX;
			ret = bfs(start, end, pred, path_flow, visited);
			if (ret) {
				cout << "get path_flow " << path_flow << endl;
				max_flow += path_flow;
				update_graph(start, end, pred, path_flow);
			}
		} while (ret);

		return max_flow;
	}

private:
	vector <vector <edge>> adjacent;

	bool bfs(int start, int end, vector <int> &pred, int &path_flow, vector <bool> &visited)
	{
		queue <int> q;

		q.push(start);

		while(!q.empty()) {
			int v = q.front();
			q.pop();
			visited[start] = true;

			for (auto &u : adjacent[v]) {
				if (!visited[u.dst] && u.weight > 0) {
					path_flow = min(path_flow, u.weight);
					//u.weight--; failed try, do not modify graph itself during bfs, will affect the un-selected path.
					//backtracking only apply to dfs, can not restore the change made during bfs.
					pred[u.dst] = v;
					if (u.dst == end)
						return true;
					visited[u.dst] = true;
					q.push(u.dst);
				}
			}
		}

		return false;
	}

	void get_path(int start, int end, vector <int> &pred, vector <int> &path)
	{
		if (start == end) {
			return;
		}
		get_path(start, pred[end], pred, path);
		path.push_back(end);
	}

	void update_graph(int start, int end, vector <int> &pred, int path_flow)
	{
		vector <int> path;
		path.push_back(start);
		get_path(start, end, pred, path);

		cout << "curr path: ";
		for (auto &i : path) {
			cout << i << ", ";
		}
		cout << endl;

		for (int i = 0; i < path.size() - 1; i++) {
			for (auto &e : adjacent[path[i]]) {
				if (e.dst == path[i + 1])
					e.weight -= path_flow;
			}
		}
	}
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		edge(0, 1, 16),
		edge(0, 2, 13),
		edge(1, 2, 10),
		edge(1, 3, 12),
		edge(2, 1, 4),
		edge(2, 4, 14),
		edge(3, 2, 9),
		edge(3, 5, 20),
		edge(4, 3, 7),
		edge(4, 5, 4),
	};

	int vertices = 6;

	graph g(edges, vertices);
	int ret = g.max_flow(0, 5);
	cout << "maximum flow of the graph from vertex 0 to 5 is " << ret << endl;

	exit(EXIT_SUCCESS);
}
