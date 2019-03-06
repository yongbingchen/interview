#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
//compared with the question "snake and ladder", when src->dst relation can be expressed by a simple math equation, no need to build the graph before take the bfs.
class solution {
	public:
		int bfs(vector <vector <int>> &matrix, vector <int> &path)
		{
			queue <int> q;
			int row = matrix.size();
			int col = matrix[0].size();
			vector <bool> visited(row * col, false);
			vector <int> dist(row * col, INT_MAX);
			vector <int> pred(row * col, -1);

			q.push(0);
			visited[0] = true;
			dist[0] = 0;

			while(!q.empty()) {
				int v = q.front();
				q.pop();

				vector <int> all_dirs;
				get_all_dirs(matrix, v, all_dirs);
				for (auto &u : all_dirs) {
					if (!visited[u]) {
						visited[u] = true;
						q.push(u);
						dist[u] = dist[v] + 1;
						pred[u] = v;
						if (u == row * col - 1) {
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
		bool is_in_matrix(int row, int col, int i, int j)
		{
			if (i < 0 || j < 0)
				return false;
			if (i > row - 1 || j > col - 1)
				return false;
			return true;
		}

		void get_all_dirs(vector <vector <int>> &matrix, int v, vector <int> &all_dirs)
		{
			int row = matrix.size();
			int col = matrix[0].size();
			int i = v / row;
			int j = v % row;
			if (is_in_matrix(row, col, i + matrix[i][j], j))
				all_dirs.push_back((i + matrix[i][j]) * row + j);
			if (is_in_matrix(row, col, i - matrix[i][j], j))
				all_dirs.push_back((i - matrix[i][j]) * row + j);
			if (is_in_matrix(row, col, i, j + matrix[i][j]))
				all_dirs.push_back(i * row + j + matrix[i][j]);
			if (is_in_matrix(row, col, i, j - matrix[i][j]))
				all_dirs.push_back(i * row + j - matrix[i][j]);
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> matrix = {
		{ 7, 1, 3, 5, 3, 6, 1, 1, 7, 5 },
		{ 2, 3, 6, 1, 1, 6, 6, 6, 1, 2 },
		{ 6, 1, 7, 2, 1, 4, 7, 6, 6, 2 },
		{ 6, 6, 7, 1, 3, 3, 5, 1, 3, 4 },
		{ 5, 5, 6, 1, 5, 4, 6, 1, 7, 4 },
		{ 3, 5, 5, 2, 7, 5, 3, 4, 3, 6 },
		{ 4, 1, 4, 3, 6, 4, 5, 3, 2, 6 },
		{ 4, 4, 1, 7, 4, 3, 3, 1, 4, 2 },
		{ 4, 4, 5, 1, 5, 2, 3, 5, 3, 5 },
		{ 3, 6, 3, 5, 2, 2, 6, 4, 2, 1 }
	};
	solution s;
	vector <int> path;
	int ret = s.bfs(matrix, path);
	cout << "shortest path is " << ret << endl;
	for (auto &i : path)
		cout << "(" << i / matrix.size() << ", " << i % matrix.size() << "), ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
