#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	int max_point(vector <vector <int>> &matrix, int row, int col)
	{
		if (row > matrix.size() - 1 || col > matrix.size() - 1)
			return 0;

		if (matrix[row][col] == -1)
			return 0;

		int points = matrix[row][col];

		if (row % 2 == 0) {
			int right = max_point(matrix, row, col + 1);
			int down = max_point(matrix, row + 1, col);
			points += max(right, down);
		}
		else {
			int left = max_point(matrix, row, col - 1);
			int down = max_point(matrix, row + 1, col);
			points += max(left, down);
		}

		return points;
	}
};

int main(int argc, char **argv)
{
	solution s;
	vector <vector <int>> matrix = {
		{1, 1, -1, 1, 1},
		{1, 0, 0, -1, 1},
		{1, 1, 1, 1, -1},
		{-1, -1, 1, 1, 1},
		{1, 1, -1, -1, 1},
	};

	int ret = s.max_point(matrix, 0, 0);
	cout << ret << endl;

	exit(EXIT_SUCCESS);
}
