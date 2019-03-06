#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	void n_queen(vector <vector <char>> &matrix, vector <vector <vector <char>>> &result)
	{
		int n = matrix.size();
		for (int i = 0; i < n; i++)
			dfs(matrix, 0, i, result); //CAUTION!, backtracking is always dfs, NO bfs solution for backtracking!
	}

private:
	void dfs(vector <vector <char>> &matrix, int row, int col, vector <vector <vector <char>>> &result)
	{
		int n = matrix.size();
		matrix[row][col] = 'Q';
		if (row == n - 1) {
			result.push_back(matrix);
			matrix[row][col] = '-'; //! DO NOT FORGET BACKTRACK HERE TOO!
			return;
		}

		vector <int> next;
		find_all_dirs(matrix, row, col, next);
		for (auto &i : next)
			dfs(matrix, i / n, i % n, result);
		matrix[row][col] = '-';
	}

	void find_all_dirs(vector <vector <char>> &curr, int i, int j, vector <int> &all_dirs)
	{
		int col = curr[0].size();
		for (int k = 0; k < col; k++) {
			if (is_safe(curr, i + 1, k))
				all_dirs.push_back((i + 1) * col + k);
		}
	}

	bool is_safe(vector <vector <char>> &curr, int i, int j)
	{
		for (int k = 0; k < i; k++) { //same column (same row is excluded by caller)
			if (curr[k][j] == 'Q')
				return false;
		}

		for (int k = i, l = j; k >= 0 && l >= 0; k--, l--) { //135 degree
			if (curr[k][l] == 'Q')
				return false;
		}

		for (int k = i, l = j; k >= 0 && l < curr[0].size(); k--, l++) { //45 degree
			if (curr[k][l] == 'Q')
				return false;
		}

		return true;
	}
};


int main(int argc, char **argv)
{
	int n = 8;
	vector <vector <char>> matrix(n, vector <char>(n, '-'));

	solution s;
	vector <vector <vector <char>>> result;
	s.n_queen(matrix, result);
	for (auto &i : result) {
		cout << "here's one solution:" << endl;
		for (auto &j : i) {
			for (auto &k : j)
				cout << k << " ";
			cout << endl;
		}
	}
	cout << "total n queen solutions: " << result.size() << endl;
	exit(EXIT_SUCCESS);
}
