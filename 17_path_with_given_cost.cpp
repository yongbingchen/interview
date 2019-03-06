#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void get_path(vector <vector <int>> &matrix, int i, int j, int cost, vector <int> &path)
		{
			if (cost <= 0)
				return;

			if (i == 0 && j == 0) {
				if (cost == matrix[0][0])
					path.push_back(matrix[0][0]);
				return;
			}
			if (i > 0) {
				get_path(matrix, i - 1, j, cost - matrix[i][j], path);
				if (!path.empty()) {
					path.push_back(matrix[i][j]);
					return;
				}
			}
			if (j > 0) {
				get_path(matrix, i, j - 1, cost - matrix[i][j], path);
				if (!path.empty()) {
					path.push_back(matrix[i][j]);
					return;
				}
			}
		}
		int get_path_count(vector <vector <int>> &matrix, int i, int j, int cost)
		{
			if (cost <= 0)
				return 0;
			if (i == 0 && j == 0) {
				if (cost == matrix[0][0])
					return 1;
				return 0;
			}

			int total_path = 0;
			if (i > 0)
				total_path = get_path_count(matrix, i - 1, j, cost - matrix[i][j]);

			if (j > 0)
				total_path += get_path_count(matrix, i, j - 1, cost - matrix[i][j]);

			return total_path;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <vector <int>> matrix = {
		{4, 7, 1, 6},
		{5, 7, 3, 9},
		{3, 2, 1, 2},
		{7, 1, 6, 3},
	};

	int cost = 25;
	vector <int> path;
	s.get_path(matrix, matrix.size() - 1, matrix[0].size() - 1, cost, path);
	cout << "total pathes with cost " << cost << " are " << s.get_path_count(matrix, matrix.size() - 1, matrix[0].size() - 1, cost) << endl;
	cout << "get one path (not all): ";
	for (auto &i : path)
		cout << i << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
