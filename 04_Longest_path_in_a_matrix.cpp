#include <iostream>
#include <vector>
#include <climits>

using namespace std;
/*
difference between bactracking and bfs/dfs
https://stackoverflow.com/questions/2709030/explain-bfs-and-dfs-in-terms-of-backtracking
Picture driving into a neighborhood, always taking the first turn you see (let's assume there are no loops) until you hit a dead end, at which point you drive back to the intersection of the next unvisited street. This the "first" kind of backtracking, and it's roughly equivalent to colloquial usage of the word.

The more specific usage refers to a problem-solving strategy that is similar to depth-first search but backtracks when it realizes that it's not worth continuing down some subtree (branch pruning).

Put another way -- a naive DFS blindly visits each node until it reaches the goal. Yes, it "backtracks" on leaf nodes. But a backtracker also backtracks on useless branches. One example is searching a Boggle board for words. Each tile is surrounded by 8 others, so the tree is huge, and naive DFS can take too long. But when we see a combination like "ZZQ," we can safely stop searching from this point, since adding more letters won't make that a word.

I love these lectures by Prof. Julie Zelenski. She solves 8 queens, a sudoku puzzle, and a number substitution puzzle using backtracking, and everything is nicely animated. Programming Abstractions, Lecture 10 Programming Abstractions, Lecture 11
*/

class solution {
	public:
		int longest_path(vector <vector <int>> &matrix, pair <int, int> &start, pair <int, int> &dst)
		{
			vector <vector <bool>> visited(matrix.size(), vector <bool>(matrix[0].size(), false));

			return longest_path(matrix, start, dst, visited);
		}

	private:
		int longest_path(vector <vector <int>> &matrix, pair <int, int> &start, pair <int, int> &dst, vector <vector <bool>> visited)
		{
			if (start.first == dst.first && start.second == dst.second)
				return 0;

			visited[start.first][start.second] = true;

			int max_len = INT_MIN;
			vector <pair <int, int>> all_dirs;
			get_all_dirs(matrix, start, all_dirs, visited);
			for (auto &i : all_dirs)
				max_len = max(longest_path(matrix, i, dst, visited) + 1, max_len);

			visited[start.first][start.second] = false;

			return max_len;
		}

		void get_all_dirs(vector <vector <int>> &matrix, pair <int, int> &start, vector <pair <int, int>> &all_dirs, vector <vector <bool>> visited)
		{
			vector <pair <int, int>> dirs = {
				pair <int, int>(0, 1),
				pair <int, int>(0, -1),
				pair <int, int>(1, 0),
				pair <int, int>(-1, 0),
			};

			for (auto &i : dirs) {
				if (is_in_matrix(matrix, start.first + i.first, start.second + i.second) &&
						!visited[start.first + i.first][start.second + i.second] &&
						matrix[start.first + i.first][start.second + i.second] == 1)
					all_dirs.push_back(pair<int, int>(start.first + i.first, start.second + i.second));
			}
		}

		bool is_in_matrix(vector <vector <int>> &matrix, int i, int j)
		{
			if (i < 0 || j < 0 || i > matrix.size() - 1 || j > matrix[0].size() - 1)
				return false;
			return true;
		}
};

int main(int argc, char **argv)
{
	vector <vector <int>> matrix = {
		{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
		{1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
		{1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
		{1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
	};

	solution s;
	pair <int, int> start(0, 0);
	pair <int, int> dst(5, 7);
	int ret = s.longest_path(matrix, start, dst);
	cout << "longest path from start (0, 0) to (5, 7) in matrix is " << ret << endl;

	exit(EXIT_SUCCESS);
}
