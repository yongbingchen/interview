#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
struct node {
	int vertex;
	int dist;
	vector <int> path;
	node(int x, int y, vector <int> &z) : vertex(x), dist(y), path(z)
	{}
};

class solution {
	public:
		int max_len(vector <vector <int>> &matrix)
		{
			int max_len = INT_MIN;
			vector <vector <int>> len(matrix.size(), vector <int>(matrix[0].size(), 1)); //len[i][j] represents the len of sequence ended with matrix[i][j]

			for (int i = 0; i < matrix.size(); i++) {
				for (int j = 0; j < matrix[0].size(); j++) {
					if (j - 1 > 0 && abs(matrix[i][j] - matrix[i][j - 1]) == 1)
						len[i][j] = len[i][j - 1] + 1;
					if (i - 1 > 0 && abs(matrix[i][j] - matrix[i - 1][j]) == 1)
						len[i][j] = max(len[i - 1][j] + 1, len[i][j]);
					max_len = max(max_len, len[i][j]);
				}
			}

			return max_len;
		}

		int bfs(vector <vector <int>> &matrix, int start, vector <bool> &visited, vector <int> &path)
		{
			if (visited[start])
				return INT_MIN;

			queue <node> q;
			vector <int> tmp(1, start);
			q.push(node(start, 1, tmp));

			int dist;
			while(!q.empty()) {
				node v = q.front();
				q.pop();
				visited[v.vertex] = true;
				dist = v.dist;
				path = v.path;
				vector <int> curr_path = v.path;
				int i = v.vertex / matrix[0].size();
				int j = v.vertex % matrix[0].size();
				cout << "visiting (" << i << ", " << j << "), dist " << dist << endl;
				if (j + 1 <= matrix[0].size() - 1 && abs(matrix[i][j] - matrix[i][j + 1]) == 1) {
					curr_path.push_back(i * matrix[0].size() + j + 1);
					q.push(node(i * matrix[0].size() + j + 1, v.dist + 1, curr_path));
				}
				if (i + 1 <= matrix.size() - 1 && abs(matrix[i][j] - matrix[i + 1][j]) == 1) {
					curr_path = v.path;
					curr_path.push_back((i + 1) * matrix[0].size() + j);
					q.push(node((i + 1) * matrix[0].size() + j, v.dist + 1, curr_path));
				}
			}

			return dist;
		}

		int longest_path(vector <vector <int>> &matrix, vector <int> &path)
		{
			int result = INT_MIN;
			vector <int> curr_path;
			vector <bool> visited(matrix.size() * matrix[0].size(), false);
			for (int i = 0; i < matrix.size(); i++) {
				for (int j = 0; j < matrix[0].size(); j++) {
					int ret = bfs(matrix, i * matrix[0].size() + j, visited, curr_path);
					if (ret > result) {
						result = ret;
						path = curr_path;
					}
				}
			}
			return result;
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> matrix = {
		{ 7, 5, 2, 3, 1 },
		{ 3, 4, 1, 4, 4 },
		{ 1, 5, 6, 7, 8 },
		{ 3, 4, 5, 8, 9 },
		{ 3, 2, 2, 7, 6 }
	};
	solution s;
	int ret = s.max_len(matrix);
	cout << ret << endl;

	vector <int> path;
	ret = s.longest_path(matrix, path);
	cout << ret << endl;
	for (auto &i : path)
		cout << "(" << i / matrix[0].size() << ", " << i % matrix[0].size() << "), ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
