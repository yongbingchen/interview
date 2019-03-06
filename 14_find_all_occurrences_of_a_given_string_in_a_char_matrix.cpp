#include <iostream>
#include <vector>

using namespace std;

struct coordinate {
	int x;
	int y;
	coordinate(int row, int col) : x(row), y(col)
	{}
};

class solution {
	public:
		void find_all_path(vector <vector <char>> &matrix, string t, vector <vector <coordinate>> &result)
		{
			for (int i = 0; i < matrix.size(); i++) {
				for (int j = 0; j < matrix[0].size(); j++) {
					if (matrix[i][j] == t[0]) {
						vector <coordinate> path;
						dfs(matrix, coordinate(i, j), t, path, result);
					}
				}
			}
		}

	private:
		void dfs(vector <vector <char>> &matrix, coordinate start, string t, vector <coordinate> &path, vector <vector <coordinate>> &result)
		{
			path.push_back(start);
			if (t.size() == 1 && t[0] == matrix[start.x][start.y]) {
				result.push_back(path);
				path.pop_back(); //backtracking here too, for searching other branches.
				return;
			}

			vector <coordinate> adjacent;
			find_adjacent(matrix, start, t[1], adjacent);
			for (auto &i : adjacent) {
				dfs(matrix, i, t.substr(1), path, result);
			}

			path.pop_back();
			return;
		}

		void find_adjacent(vector <vector <char>> &matrix, coordinate start, char val, vector <coordinate> &adjacent)
		{
			int m = matrix.size();
			int n = matrix[0].size();
			vector <coordinate> all_dirs = {
				coordinate(start.x - 1, start.y - 1),
				coordinate(start.x - 1, start.y),
				coordinate(start.x - 1, start.y + 1),
				coordinate(start.x, start.y - 1),
				coordinate(start.x, start.y + 1),
				coordinate(start.x + 1, start.y - 1),
				coordinate(start.x + 1, start.y),
				coordinate(start.x + 1, start.y + 1),
			};

			for (auto &i : all_dirs) {
				if (is_valid(m, n, i.x, i.y)) {
					if (matrix[i.x][i.y] == val)
						adjacent.push_back(i);
				}
			}
		}

		bool is_valid(int m, int n, int x, int y)
		{
			if (x < 0 || y < 0 || x > m - 1 || y > n - 1)
				return false;
			return true;
		}

};

int main(int argc, char **argv)
{
	solution s;
	vector <vector <char>> matrix = {
		{ 'D', 'E', 'M', 'X', 'B' },
		{ 'A', 'O', 'E', 'P', 'E' },
		{ 'D', 'D', 'C', 'O', 'D' },
		{ 'E', 'B', 'E', 'D', 'S' },
		{ 'C', 'P', 'Y', 'E', 'N' }
	};

	string target  = "CODE";
	vector <vector <coordinate>> result;
	s.find_all_path(matrix, target, result);

	for (auto &i : result) {
		cout << "find one path in matrix matching " << target << endl;
		for (auto &j : i) {
			cout << "(" << j.x << ", " << j.y<< ") ";
		}
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
