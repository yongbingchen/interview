#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void longest_adjacent_num_seq(vector <vector <int>> &matrix, int m, int n, vector <int> &path)
		{
			path.push_back(matrix[m][n]);
			if (m + 1 < matrix.size() && matrix[m + 1][n] == matrix[m][n] + 1) {
				longest_adjacent_num_seq(matrix, m + 1, n, path);
			} //all elements are have distinctive value, that's why only one direction to go, and that's why only one dfs path (not a tree) from each elem
			//so this question has very limited general usage.
			else if (n + 1 < matrix[0].size() && matrix[m][n + 1] == matrix[m][n] + 1) {
				longest_adjacent_num_seq(matrix, m, n + 1, path);
			}
			else if (m - 1 > 0 && matrix[m - 1][n] == matrix[m][n] + 1) {
				longest_adjacent_num_seq(matrix, m - 1, n, path);
			}
			else if (n - 1 > 0 && matrix[m][n - 1] == matrix[m][n] + 1) {
				longest_adjacent_num_seq(matrix, m, n - 1, path);
			}
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <vector <int>> matrix = {
		{10, 13, 14, 21, 23},
		{11, 9, 22, 2, 3},
		{12, 8, 1, 5, 4},
		{15, 24, 7, 6, 20},
		{16, 17, 18, 19, 25},
	};

	vector <int> path;

	for (int i = 1; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[0].size(); j++) {
			path.clear();
			s.longest_adjacent_num_seq(matrix, i, j, path);

			cout << "for sub matrix " << i + 1 << "x" << j + 1 << " node " << matrix[i][j] << ", the longest_adjacent_num_seq is ";
			for (auto &k : path)
				cout << k << ", ";
			cout << endl;
		}
	}

	exit(EXIT_SUCCESS);
}
