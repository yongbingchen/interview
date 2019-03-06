#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class solution {
	public:
		void flood_fill(vector <vector <char>> &matrix, int x, int y, char replacement)
		{
			queue <int> q;
			int target_color = matrix[x][y];
			int row = matrix[0].size();

			q.push(x * row + y);
			while(!q.empty()) {
				int i = q.front() / row;
				int j = q.front() % row;
				q.pop();

				if (matrix[i][j] == target_color) {
					matrix[i][j] = replacement;

					vector <int> all_dirs;
					get_all_dirs(matrix, i, j, all_dirs);
					for (auto &u : all_dirs)
						q.push(u);
				}
			}
		}

	private:
		bool is_in_matrix(vector <vector <char>> &matrix, int i, int j)
		{
			if (i < 0 || j < 0)
				return false;
			if (i > matrix.size() - 1 || j > matrix[0].size() - 1)
				return false;
			return true;
		}

		void get_all_dirs(vector <vector <char>> &matrix, int i, int j, vector <int> &result)
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
	solution s;
	vector <vector <char>> matrix = {
		{ 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G' },
		{ 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X' },
		{ 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X' },
		{ 'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X' },
		{ 'W', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X' },
		{ 'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X' },
		{ 'W', 'B', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X' },
		{ 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X' },
		{ 'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X' },
		{ 'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
	};

	int x = 3, y = 9;	// target color = "X"
	char replacement = 'C';

	s.flood_fill(matrix, x, y, replacement);
	for (auto &i : matrix) {
		for (auto &j : i)
			cout << j << ", ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
