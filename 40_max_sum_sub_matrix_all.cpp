#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int sub_matrix_sum(int top_i, int top_j, int bottom_i, int bottom_j)
		{
			return get_sum(bottom_i, bottom_j) - get_sum(bottom_i, top_j - 1) - get_sum(top_i - 1, bottom_j) + get_sum(top_i - 1, top_j - 1);
		}


		void build_sub_matrix_sum_table(vector <vector <int>> &matrix, int row, int col)
		{
			for (int i = 0; i < row; i++) {
				vector <int> curr(col, 0);
				sum.push_back(curr);
			}

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					sum[i][j] = get_sum(i, j - 1) + get_sum(i - 1, j) + matrix[i][j] - get_sum(i - 1, j - 1);
					cout << i << ", " << j << ", sum is " << sum[i][j] << endl;
				}
			}
		}
	private:
		vector <vector <int>> sum;
		//use a function to avoid the case of outside of the matrix boundary
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
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			for (int m = i; m < matrix.size(); m++) {
				for (int n = j; n < matrix[0].size(); n++) {
					int ret = s.sub_matrix_sum(i, j, m, n);
					cout << "sub matrix (" << i << ", " << j << "):(" << m << ", " << n << ")'s sum is " << ret << endl;
				}
			}
		}
	}

	exit(EXIT_SUCCESS);
}
