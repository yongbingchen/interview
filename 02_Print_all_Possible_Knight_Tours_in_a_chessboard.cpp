#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	void knight_tour(int n, vector <vector <int>> &paths)
	{
		vector <int> curr_path;
		vector <vector <bool>> visited(n, vector <bool>(n, false));
		backtracking(n, 0, 0, curr_path, paths, visited);//only start from (0, 0) for demo, other start point should call the same function.
	}

private:
	void backtracking(int n, int i, int j,
			vector <int> &curr_path,
			vector <vector <int>> &paths,
			vector <vector <bool>> &visited)
	{
		visited[i][j] = true;
		curr_path.push_back(i * n + j);

		if (curr_path.size() == n * n) {
			paths.push_back(curr_path);
			curr_path.pop_back(); //do not forget do backtracking here too!
			visited[i][j] = false;
			return;
		}

		vector <int> all_dirs;
		get_all_dirs(visited, i, j, all_dirs);
		for (auto &k : all_dirs)
			backtracking(n, k / n, k % n, curr_path, paths, visited);

		curr_path.pop_back();
		visited[i][j] = false;
	}

	void get_all_dirs(vector <vector <bool>> &visited, int i, int j, vector <int> &all_dirs)
	{
		vector <pair <int, int>> eight_next = {
			pair <int, int>(i - 2, j - 1),
			pair <int, int>(i - 2, j + 1),
			pair <int, int>(i - 1, j - 2),
			pair <int, int>(i - 1, j + 2),
			pair <int, int>(i + 1, j - 2),
			pair <int, int>(i + 1, j + 2),
			pair <int, int>(i + 2, j - 1),
			pair <int, int>(i + 2, j + 1),
		};

		int n = visited.size();
		for (auto &k : eight_next) {
			if (is_in_board(k.first, k.second, n) &&
					!visited[k.first][k.second]) {
				all_dirs.push_back(k.first * n + k.second);
			}
		}
	}

	bool is_in_board(int i, int j, int n)
	{
		if (i < 0 || j < 0 || i > n - 1 || j > n - 1)
			return false;

		return true;
	}
};

int main(int argc, char **argv)
{
	solution s;

	int n = 5;
	vector <vector <int>> paths;
	s.knight_tour(n, paths);

	cout << "in a " << n << "X" << n << " chessboard, there're " << paths.size() << " total paths" << endl;
	for (auto &i : paths) {
		for (auto &j : i)
			cout << j << ", ";
		cout << endl;
	}
}
