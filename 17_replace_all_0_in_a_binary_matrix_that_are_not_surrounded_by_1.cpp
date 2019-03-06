#include <iostream>
#include <vector>

using namespace std;

class solution {
	public:
		void replace(vector <vector <int>> &matrix, int i, int j)
		{
			if (i < 0 || j < 0)
				return;
			if (i > matrix.size() - 1 || j > matrix[0].size() - 1)
				return;

			if (matrix[i][j] == 0) {
				matrix[i][j] = 1;
				vector <pair <int, int>> all_dirs;
				get_all_dirs(i, j, all_dirs);
				for (auto &k : all_dirs)
					replace(matrix, k.first, k.second);
			}
		}

		void replace_all(vector <vector <int>> &matrix)
		{
			//start form four edges, which is for sure need to be replaced
			//do a dfs to replace every zero can be reached by these dfs.
			for (int i = 0; i < matrix[0].size(); i++)
				replace(matrix, 0, i);
			for (int i = 0; i < matrix[0].size(); i++)
				replace(matrix, matrix.size() - 1, i);
			for (int i = 0; i < matrix.size(); i++)
				replace(matrix, i, 0);
			for (int i = 0; i < matrix.size(); i++)
				replace(matrix, i, matrix[0].size() - 1);
		}
	private:
		void get_all_dirs(int i, int j, vector <pair <int, int>> &all_dirs)
		{
			//this is the full definition of "surrounding"
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
	vector <vector <int>> matrix = {
		{1, 1, 1, 1, 0, 0, 1, 1, 0, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 1, 1, 0, 1},
		{1, 1, 1, 1, 0, 0, 0, 1, 0, 1},
		{1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
		{1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 0, 0, 1, 0, 1},
		{1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1, 1, 1}
	};

	solution s;
	s.replace_all(matrix);
	for (auto &i : matrix) {
		for (auto &j : i)
			cout << j << ", ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
