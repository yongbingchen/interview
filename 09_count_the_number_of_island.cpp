#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class solution {
	public:
		bool bfs(vector <vector <int>> &matrix, int x, int y, int target, vector <bool> &visited)
		{
			if (matrix[x][y] != target)
				return false;
			int row = matrix[0].size();
			if (visited[x * row + y])
				return false;

			queue <int> q;
			q.push(x * row + y);
			while(!q.empty()) {
				int v = q.front();
				q.pop();
				visited[v] = true;
				vector <int> all_dirs;
				get_all_dirs(matrix, v / row, v % row, all_dirs);
				for (auto &i : all_dirs) {
					if (matrix[i / row][i % row] == target && !visited[i])
						q.push(i);
				}
			}

			return true;
		}

	private:
		bool is_in_matrix(vector <vector <int>> &matrix, int i, int j)
		{
			if (i < 0 || j < 0)
				return false;
			if (i > matrix.size() - 1 || j > matrix[0].size() - 1)
				return false;
			return true;
		}

		void get_all_dirs(vector <vector <int>> &matrix, int i, int j, vector <int> &result)
		{
			int row = matrix[0].size();
			if (is_in_matrix(matrix, i + 1, j))
				result.push_back((i + 1) * row + j);
			if (is_in_matrix(matrix, i + 1, j + 1))
				result.push_back((i + 1) * row + j + 1);
			if (is_in_matrix(matrix, i + 1, j - 1))
				result.push_back((i + 1) * row + j - 1);

			if (is_in_matrix(matrix, i, j + 1))
				result.push_back(i * row + j + 1);
			if (is_in_matrix(matrix, i, j - 1))
				result.push_back(i * row + j - 1);

			if (is_in_matrix(matrix, i - 1, j))
				result.push_back((i - 1) * row + j);
			if (is_in_matrix(matrix, i - 1, j + 1))
				result.push_back((i - 1) * row + j + 1);
			if (is_in_matrix(matrix, i - 1, j - 1))
				result.push_back((i - 1) * row + j - 1);
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> matrix = {
		{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
	};

	solution s;
	vector <bool> visited(matrix.size() * matrix[0].size(), false);
	int num_of_islands = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (s.bfs(matrix, i, j, 1, visited))
				num_of_islands++;
		}
	}

	cout << "num of islands in the matrix " << num_of_islands << endl;
	exit(EXIT_SUCCESS);
}
