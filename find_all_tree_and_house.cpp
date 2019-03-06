#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct space {
	string val;
	space *left;
	space *right;
	space *up;
	space *down;
	space(string x) : val(x), left(nullptr), right(nullptr), up(nullptr),down(nullptr)
	{}
};

class grid {
	public:
		void find_all(int i, int j, vector <vector <space>> &matrix, vector <vector <bool>> &visited, vector <pair <int, int>> &result)
		{ //do not try to use start = i * n + j, easy for bug.
			if (visited[i][j])
				return;

			queue <pair <int, int>> q;
			q.push(pair <int, int>(i ,j ));

			while(!q.empty()) {
				pair <int, int> v = q.front();
				q.pop();
				result.push_back(v);
				visited[v.first][v.second] = true;

				vector <pair <int, int>> neighbors;
				get_neighbors(v, matrix, neighbors);
				for (auto &u : neighbors)
					if (!visited[u.first][u.second])
						q.push(u);
			}
		}

	private:
		void get_neighbors(pair <int, int> &v, vector <vector <space>> &matrix, vector <pair <int, int>> &neighbors)
		{
			int m = matrix.size();
			int n = matrix[0].size();
			int i = v.first;
			int j = v.second;
			vector <pair <int, int>> next = {pair<int, int>(i - 1, j), pair<int, int>(i + 1, j), pair<int, int>(i, j -1), pair<int, int>(i, j + 1)};
			for (auto &k : next)
				if (is_in_matrix(k.first, k.second, m, n)) {
					if (matrix[k.first][k.second].val != "")
						neighbors.push_back(k);
				}
		}

		bool is_in_matrix(int i, int j, int m, int n)
		{
			if (i < 0 || j < 0 || i > m - 1 || j > n - 1)
				return false;
			return true;
		}
};

int main(int argc, char **argv)
{
	vector <vector <space>> matrix = {
		{space("T"), space(""), space(""), space("H"), space("")},
		{space(""), space(""), space(""), space(""), space("")},
		{space("H"), space("H"), space("T"), space("H"), space("")},
	};
	vector <vector <bool>> visited(matrix.size(), vector <bool>(matrix[0].size(), false));
	vector <pair <int, int>> result;
	grid g;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (!visited[i][j] && matrix[i][j].val != "")
				g.find_all(i ,j, matrix, visited, result);
		}
	}

	for (auto &i : result)
		cout << i.first << "," << i.second << endl;
}
