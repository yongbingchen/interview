#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory>

using namespace std;

struct edge {
	int src;
	int dst;
	edge(int x, int y) : src(x), dst(y)
	{}
};

class graph {
	public:
		graph(vector <edge> &edges, int vertices)
		{
			adjacent.resize(vertices);
			for (auto &e : edges)
				adjacent[e.src].push_back(e.dst);
		}

		int shortest_path(int start, int stop, vector <int> &path)
		{
			queue <int> q;
			vector <bool> discovered(adjacent.size(), false);
			vector <int> pred(adjacent.size(), -1);
			vector <int> dist(adjacent.size(), INT_MAX);

			q.push(start);
			discovered[start] = true;
			dist[start] = 0;
			while(!q.empty()) {
				int v = q.front();
				q.pop();

				for (auto &u : adjacent[v]) {
					if (!discovered[u]) {
						discovered[u] = true;
						pred[u] = v;
						dist[u] = dist[v] + 1;
						q.push(u);
						if (u == stop) {
							int shortest_path = dist[u];
							path.push_back(u);
							while(pred[u] != -1) {
								path.push_back(pred[u]);
								u = pred[u];
							}
							return shortest_path;
						}
					}
				}
			}

			return INT_MAX;
		}

	private:
		vector <vector <int>> adjacent;
};

class solution {
	public:
		void build_graph()
		{
			vector <edge> edges;
			int vertices = 64;

			for (int i = 0; i < 8;  i++) {
				for (int j = 0; j < 8; j++) {
					int src = i * 8 + j;
					vector <int> dst = get_all_dst(i, j);
					for (auto &k : dst)
						edges.push_back(edge(src, k));
				}
			}

			g = make_unique <graph> (edges, vertices);
		}

		int shortest_path(vector <int> &path)
		{

			return g->shortest_path(0, 63, path);
		}
	private:
		unique_ptr <graph> g;

		vector <int> get_all_dst(int i, int j)
		{
			vector <int> result;
			if (is_within_range(i - 2, j - 1))
				result.push_back((i - 2) * 8 + j - 1);
			if (is_within_range(i - 2, j + 1))
				result.push_back((i - 2) * 8 + j + 1);
			if (is_within_range(i - 1, j - 2))
				result.push_back((i - 1) * 8 + j - 2);
			if (is_within_range(i - 1, j + 2))
				result.push_back((i - 1) * 8 + j + 2);
			if (is_within_range(i + 1, j - 2))
				result.push_back((i + 1) * 8 + j - 2);
			if (is_within_range(i + 1, j + 2))
				result.push_back((i + 1) * 8 + j + 2);
			if (is_within_range(i + 2, j - 1))
				result.push_back((i + 2) * 8 + j - 1);
			if (is_within_range(i + 2, j + 1))
				result.push_back((i + 2) * 8 + j + 1);

			return result;
		}

		bool is_within_range(int i, int j)
		{
			if (i < 0 || j < 0)
				return false;
			if (i > 7 || j > 7)
				return false;

			return true;
		}

};

int main(int argc, char **argv)
{
	solution s;

	s.build_graph();
	vector <int> path;
	int ret = s.shortest_path(path);
	cout << "shortest path is " << ret <<endl;
	for (auto &i : path)
		cout << "(row " << i / 8 << ", col " << i % 8 << "), " << endl;
	cout << endl;

	exit(EXIT_SUCCESS);
}
