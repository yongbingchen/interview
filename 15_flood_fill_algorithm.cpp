#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void flood_fill(vector <vector <char>> &matrix, pair <int, int> start, char target, char replacement)
		{
			if (is_out_of_matrix(matrix, start))
				return;

			int i = start.first, j = start.second;
			if (matrix[i][j] != target)
				return;

			matrix[i][j] = replacement;

			vector <pair <int, int>> all_dirs;
			get_all_dirs(i, j, all_dirs);
			for (auto &i : all_dirs)
				flood_fill(matrix, i, target, replacement);
		}

	private:
		bool is_out_of_matrix(vector <vector <char>> &matrix, pair <int, int> start)
		{
			if (start.first < 0 || start.second < 0)
				return true;

			if (start.first > matrix.size() - 1 || start.second > matrix[0].size() - 1)
				return true;

			return false;
		}

		void get_all_dirs(int i, int j, vector <pair <int, int>> &all_dirs)
		{
			all_dirs.push_back(pair <int, int>(i, j + 1));
			all_dirs.push_back(pair <int, int>(i, j - 1));
			all_dirs.push_back(pair <int, int>(i + 1, j + 1));
			all_dirs.push_back(pair <int, int>(i + 1, j));
			all_dirs.push_back(pair <int, int>(i + 1, j - 1));
			all_dirs.push_back(pair <int, int>(i - 1, j + 1));
			all_dirs.push_back(pair <int, int>(i - 1, j));
			all_dirs.push_back(pair <int, int>(i - 1, j - 1));

		}
};

int main(int argc, char **argv)
{
	vector <vector <char>> matrix = {
		{ 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G' },
		{ 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X' },
		{ 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X' },
		{ 'X', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X' },
		{ 'X', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X' },
		{ 'X', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X' },
		{ 'X', 'X', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X' },
		{ 'X', 'X', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X' },
		{ 'X', 'X', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X' },
		{ 'X', 'X', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
	};
	cout << "before flood fill from (3, 9)" << endl;
	for (auto &i : matrix) {
		for (auto &j : i)
			cout << j << ",";
		cout << endl;
	}


	solution s;
	s.flood_fill(matrix, pair <int, int> (3, 9), 'X', 'C');

	cout << "after flood fill from (3, 9)" << endl;
	for (auto &i : matrix) {
		for (auto &j : i)
			cout << j << ",";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
