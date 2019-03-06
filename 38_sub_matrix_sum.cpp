#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void build_sub_matrix_sum_table(vector <vector <int>> &matrix, int m, int n)
		{
			sum.assign(m, vector <int>(n, 0));
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					sum[i][j] = get_sum(i, j - 1) + get_sum(i - 1, j) - get_sum(i - 1, j - 1) + matrix[i][j];
				}
			}

		}

		int sub_matrix_sum(int i, int j, int p, int q)
		{
			return sum[p][q] - get_sum(p, j - 1) - get_sum(i - 1, q) + get_sum(i - 1, j - 1);

		}
	private:
		vector <vector <int>> sum;
		int get_sum(int i, int j)
		{
			if (i < 0 || j < 0 || i > sum.size() - 1 || j > sum[0].size() - 1)
				return 0;
			return sum[i][j];
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <vector <int>> matrix = {
		{0, 2, 5, 4, 1},
		{4, 8, 2, 3, 7},
		{6, 3, 4, 6, 2},
		{7, 3, 1, 8, 3},
		{1, 5, 7, 9, 4},
	};

	s.build_sub_matrix_sum_table(matrix, matrix.size(), matrix[0].size());
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			int ret = s.sub_matrix_sum(1, 1, i, j);
			cout << "sub matrix (1, 1):(" << i << ", " << j << ")'s sum is " << ret << endl;
		}
	}

	exit(EXIT_SUCCESS);
}
