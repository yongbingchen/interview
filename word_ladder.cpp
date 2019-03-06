#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge {
	int src;
	int dst;
	edge(int x, int y) : src(x), dst(y)
	{}
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

	void bfs(int src, int dst, vector <int> &pred)
	{
		vector <bool> visited(vertices, false);
		queue <int> q;

		q.push(src);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			visited[u] = true;

			for (auto &v : adjacent[u]) {
				if (!visited[v]) {
					pred[v] = u;
					if (v == dst)
						return;
					q.push(v);
				}
			}
		}
	}

private:
	int vertices;
	vector <vector <int>> adjacent;
};

class solution {
public:
	void shortest_path(vector <string> &dict, int src, int dst, vector <string> &path)
	{
		vector <edge> edges;
		find_all_edges(dict, edges);
		graph g(edges, dict.size());
		vector <int> pred(dict.size(), -1);
		g.bfs(src, dst, pred);
		int i = dst;
		while(pred[i] != -1) {
			path.push_back(dict[i]);
			i = pred[i];
		}
		path.push_back(dict[src]);
		reverse(path.begin(), path.end());
	}

private:
	void find_all_edges(vector <string> &dict, vector <edge> &edges)
	{
		int n = dict.size();

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (is_adjacent(dict[i], dict[j]))
					edges.push_back(edge(i, j));
			}
		}
	}

	bool is_adjacent(string a, string b)
	{
		int diff = a.size() - b.size();
		int num_diff = abs(diff);
		//int num_diff = abs(a.size() - b.size()); this can not pass compile
		int m = min(a.size(), b.size());

		for (int i = 0; i < m; i++) {
			if (a[i] != b[i])
				num_diff++;

			if (num_diff > 1)
				return false;
		}

		return true;
	}
};

int main(int argc, char **argv)
{
	vector <string> dict = {
		"hit", "hot", "dot", "dog", "lot", "log", "cog", //put src, dst in dict for code clean
	};

	int src = 0;
	int dst = 6;
	solution s;
	vector <string> path;
	s.shortest_path(dict, src, dst, path);
	cout << "shortest path is ";
	for (auto &s : path)
		cout << s << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
