#include <iostream>
#include <vector>

using namespace std;

struct coordinate {
	int row;
	int col;
	coordinate(int x, int y) : row(x), col(y)
	{}
};

class solution {
	public:
		bool find_path(vector <vector <int>> &matrix, coordinate start, vector <coordinate> &path, vector <vector <bool>> &visited)
		{
			if (visited[start.row][start.col])
				return false;
			visited[start.row][start.col] = true;
			path.push_back(start);

			int m = matrix.size();
			int n = matrix[0].size();
			if (start.row == m - 1 && start.col == n - 1)
				return true;

			vector <coordinate> adjacent;
			find_adjacent(m, n, matrix[start.row][start.col], start, adjacent);
			for (auto &i : adjacent) {
				if (find_path(matrix, i, path, visited))
					return true;
			}

			path.pop_back(); //backtracking
			//visited[start.row][start.col] = false; ALL path through this node is going to fail.
			return false;
		}

	private:
		void find_adjacent(int m, int n, int val, coordinate &start, vector <coordinate> &adjacent)
		{
			if (is_valid(m, n, start.row - val, start.col))
				adjacent.push_back(coordinate(start.row - val, start.col));
			if (is_valid(m, n, start.row + val, start.col))
				adjacent.push_back(coordinate(start.row + val, start.col));
			if (is_valid(m, n, start.row, start.col - val))
				adjacent.push_back(coordinate(start.row, start.col - val));
			if (is_valid(m, n, start.row, start.col + val))
				adjacent.push_back(coordinate(start.row, start.col + val));
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
	vector <vector <int>> matrix = {
		{ 7, 1, 3, 5, 3, 6, 1, 1, 7, 5 },
		{ 2, 3, 6, 1, 1, 6, 6, 6, 1, 2 },
		{ 6, 1, 7, 2, 1, 4, 7, 6, 6, 2 },
		{ 6, 6, 7, 1, 3, 3, 5, 1, 3, 4 },
		{ 5, 5, 6, 1, 5, 4, 6, 1, 7, 4 },
		{ 3, 5, 5, 2, 7, 5, 3, 4, 3, 6 },
		{ 4, 1, 4, 3, 6, 4, 5, 3, 2, 6 },
		{ 4, 4, 1, 7, 4, 3, 3, 1, 4, 2 },
		{ 4, 4, 5, 1, 5, 2, 3, 5, 3, 5 },
		{ 3, 6, 3, 5, 2, 2, 6, 4, 2, 1 }
	};

	solution s;
	vector <coordinate> path;
	vector <vector <bool>> visited(matrix.size(), vector <bool>(matrix[0].size(), false));
	if (s.find_path(matrix, coordinate(0, 0), path, visited)) {
		cout << "found a path for (0, 0) to (9, 9):" << endl;
		for (auto &i : path)
			cout << "(" << i.row << ", " << i.col << ") ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
