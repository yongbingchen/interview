#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <climits>

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
			for (auto &e : edges) {
				adjacent[e.src].push_back(e.dst);
				cout << "one edge in graph: (" << e.src << ", " << e.dst << ")" <<endl;
			}
		}

		int shortest_path(int start, int stop, vector <int> &path)
		{
			vector <bool> discovered(adjacent.size(), false);
			vector <int> pred(adjacent.size(), -1);
			vector <int> dist(adjacent.size(), INT_MAX);
			queue <int> q;

			q.push(start);
			dist[start] = 0;
			discovered[start] = true;

			while(!q.empty()) {
				int v = q.front();
				q.pop();
				for (auto &u : adjacent[v]) {
					if (!discovered[u]) {
						discovered[u] = true;
						dist[u] = dist[v] + 1;
						pred[u] = v;
						q.push(u);
						if (u == stop) {
							int shortest = dist[u];
							path.push_back(u);
							while(pred[u] != -1) {
								path.push_back(pred[u]);
								u = pred[u];
							}
							return shortest;
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
		void build_graph(vector <vector <int>> &matrix)
		{
			vector <edge> edges;
			int vertices = matrix.size() * matrix[0].size();

			for (int i = 0; i < matrix.size(); i++) {
				for (int j = 0; j < matrix[0].size(); j++) {
					if (matrix[i][j] == 1) {
						int src = i * matrix[0].size() + j;
						vector <int> dst = get_all_dst(matrix, i, j);
						for (auto &k : dst)
							edges.push_back(edge(src, k));
					}
				}
			}

			g = make_unique <graph> (edges, vertices);

		}

		int shortest_path(int start, int stop, vector <int> &path)
		{
			return g->shortest_path(start, stop, path);
		}

	private:
		unique_ptr <graph> g;
		vector <int> get_all_dst(vector <vector <int>> &matrix, int i, int j)
		{
			vector <int> result;
			int row = matrix[0].size();
			if (is_within_matrix(matrix, i - 1, j) && matrix[i - 1][j] == 1)
				result.push_back((i - 1) * row + j);
			if (is_within_matrix(matrix, i + 1, j) && matrix[i + 1][j] == 1)
				result.push_back((i + 1) * row + j);
			if (is_within_matrix(matrix, i, j - 1) && matrix[i][j - 1] == 1)
				result.push_back(i * row + j - 1);
			if (is_within_matrix(matrix, i, j + 1) && matrix[i][j + 1] == 1)
				result.push_back(i * row + j + 1);

			return result;
		}

		bool is_within_matrix(vector <vector <int>> &matrix, int i, int j)
		{
			if (i < 0 || j < 0)
				return false;
			if (i > matrix.size() - 1 || j > matrix[0].size() - 1)
				return false;

			return true;
		}

};

int main(int argc, char **argv)
{
	vector <vector <int>> matrix = {
		{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
		{0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
		{0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
		{0, 0, 1, 0, 0, 1, 1, 0, 0, 1},
	};

	solution s;
	s.build_graph(matrix);
	vector <int> path;
	int ret = s.shortest_path(0, 7 * matrix[0].size() + 5, path);
	cout << "shortest path" << ret << endl;
	for (auto &i : path)
		cout << "(" << i / matrix[0].size() << ", " << i % matrix[0].size() << ") " << endl;

	exit(EXIT_SUCCESS);
}
