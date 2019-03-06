#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solution {
	public:
		bool is_valid_sudoku(vector <vector <int>> matrix)
		{
			for (int i = 0; i < matrix.size(); i++) {
				if (!is_row_valid(matrix[i]))
					return false;
			}

			for (int i = 0; i < matrix[0].size(); i++) {
				if (!is_column_valid(matrix, i))
					return false;
			}

			for (int i = 0; i < matrix.size() / 3; i++) {
				for (int j = 0; j < matrix[0].size(); j++) {
					if (!is_subset_valid(matrix, i, j))
						return false;
				}
			}
			return true;
		}
	private:
		bool is_row_valid(vector <int> row)
		{
			unordered_map <int, bool> used;
			for (int i = 0; i < 9; i++)
				used[i] = false;

			for (auto &i : row) {
				if (i != '.') {
					if (used[i] == true)
						return false;
					used[i] = true;
				}
			}

			return true;
		}
		bool is_column_valid(vector <vector <int>> matrix, int col)
		{
			unordered_map <int, bool> used;
			for (int i = 0; i < 9; i++)
				used[i] = false;

			for (int i = 0;  i < matrix.size(); i++) {
				if (matrix[i][col] != '.') {
					if (used[matrix[i][col]] == true)
						return false;
					used[matrix[i][col]] = true;
				}
			}

			return true;
		}

		bool is_subset_valid(vector <vector <int>> matrix, int row, int col)
		{
			unordered_map <int, bool> used;
			for (int i = 0; i < 9; i++)
				used[i] = false;

			for (int i = row; i < row + 3; i++) {
				for (int j = col; j < col + 3; j++) {
					if (matrix[i][j] != '.') {
						if (used[matrix[i][j]] == true)
							return false;
					}
				}
			}
			return true;
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> matrix = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	};

	solution s;

	bool ret = s.is_valid_sudoku(matrix);
	cout << "is valid " << ret << endl;
	exit(EXIT_SUCCESS);
}
