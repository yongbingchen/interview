#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void delete_zero(vector <vector <int>> &matrix)
		{
			int n = matrix.size();
			int m = matrix[0].size();
			vector <bool> rows_have_zero(n, false);
			vector <bool> cols_have_zero(m, false);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (matrix[i][j] == 0) {
						rows_have_zero[i] = true;
						cols_have_zero[j] = true;
					}
				}
			}

			for (int i = 0; i < n; i++) {
				if (rows_have_zero[i]) {
					for (int j = 0; j < m; j++)
						matrix[i][j] = 0;
				}
			}

			for (int j = 0; j < m; j++) {
				if (cols_have_zero[j]) {
					for (int i = 0; i < n; i++)
						matrix[i][j] = 0;
				}
			}
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <vector <int>> matrix = {
		{1, 2, 3, 4, 5, 6, 7},
		{1, 0, 3, 4, 5, 6, 7},
		{1, 2, 3, 0, 5, 6, 7},
		{1, 2, 3, 4, 5, 6, 7},
	};

	s.delete_zero(matrix);

	for (int i = 0; i < matrix.size(); i++) {
		for (auto &a : matrix[i])
			cout << a << ", ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
