#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		int largest_square_sub_matrix(vector <vector <int>> &matrix, pair <int, int> &max_idx)
		{
			vector <vector <int>> subm(matrix.size(), vector <int>(matrix[0].size(), 0));
			for (int i = 0; i < matrix[0].size(); i++) {
				if (matrix[0][i] == 1)
					subm[0][i] = 1;
			}

			for (int i = 0; i < matrix.size(); i++) {
				if (matrix[i][0] == 1)
					subm[i][0] = 1;
			}

			max_idx = pair <int, int>(0, 0);
			for (int i = 1; i < matrix.size(); i++) {
				for (int j = 1; j < matrix[0].size(); j++) {
					if (matrix[i][j] == 1) {
						subm[i][j] = min(subm[i - 1][j], min(subm[i - 1][j - 1], subm[i][j - 1])) + 1;
						if (subm[i][j] > subm[max_idx.first][max_idx.second])
							max_idx = pair <int, int>(i, j);
					}
				}
			}

			return subm[max_idx.first][max_idx.second];
		}

		//a problem in this definition, the real result is returned by max_sqr, but not the return val, need refine.
		int largest_square_sub_matrix_top_down(vector <vector <int>> &matrix, int row, int col, int &max_sqr)
		{
			if (row == 0 || col == 0)
				return matrix[row][col] == 1 ? 1 : 0;

			int left = largest_square_sub_matrix_top_down(matrix, row, col - 1, max_sqr);
			int right = largest_square_sub_matrix_top_down(matrix, row - 1, col, max_sqr);
			int top_left = largest_square_sub_matrix_top_down(matrix, row - 1, col - 1, max_sqr);

			int size = 0;
			if (matrix[row][col] == 1) {
			//this is a geometry problem here, this node belongs to a larger square only when min of
			//left, top, top_left is not zero.
			//see the web page for reference.
				size = min(min(left, right), top_left) + 1;
			}
			max_sqr = max(max_sqr, size);
			return size;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <vector <int>> matrix = {
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1 }
	};

	pair <int, int> coordinate;
	int size = s.largest_square_sub_matrix(matrix, coordinate);
	cout << "max sub matrix size " << size << ", coordinate (" << coordinate.first << ", " << coordinate.second << ")" << endl;
	s.largest_square_sub_matrix_top_down(matrix, matrix.size() - 1, matrix[0].size() - 1, size);
	cout << size << endl;

	exit(EXIT_SUCCESS);
}
