#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct node {
	int vertex;
	int dist;
	node(int x, int y) : vertex(x), dist(y)
	{}
};

class solution {
	public:
		void get_all_distance(vector <vector <char>> &matrix, vector <vector <int>> &result)
		{
			queue <node> q;
			int col = matrix[0].size();
			for (int i = 0; i < matrix.size(); i++) {
				for (int j = 0; j < matrix[0].size(); j++) {
					if (matrix[i][j] == 'M')
						q.push(node(i * col + j, 0)); //put all 'M' node in queue at same time, they all belong to layer 0.
				}
			}

			vector <bool> visited(matrix.size() * col, false); //undirected graph must need this for the iterate to terminate.
			while(!q.empty()) {
				node v = q.front();
				q.pop();
				if (!visited[v.vertex]) {
					visited[v.vertex] = true;
					//result[v.vertex / col][v.vertex % col] = min(result[v.vertex / col][v.vertex % col] , v.dist);
					result[v.vertex / col][v.vertex % col] =  v.dist;
					//above revise lays out the essence of bfs, when start from layer 0, all node at layer 0 (the 'M' node) will be finished first,
					//before any other node can be visited.
					//then layer 1 node (the direct neighbor of layer 0 nodes) will be visited at same time too (means they will all be visited before next layer node)
					//this bfs property used for searching for shortest path, in here used like flood fill.

					//use 'visited' to avoid access same node twice, because a node only need to be accessed once in bfs to decide its closest distance to a layer 0 node (as explained above).
					vector <int> all_dirs;
					get_all_dirs(matrix, v.vertex / col, v.vertex % col, all_dirs);
					for (auto &i : all_dirs)
						q.push(node(i, v.dist + 1));
				}
			}
		}

		bool is_valid(int row, int col, int i, int j)
		{
			if (i < 0 || j < 0 || i > row - 1 || j > col - 1)
				return false;
			return true;
		}

		void get_all_dirs(vector <vector <char>> &matrix, int i, int j, vector <int> &all_dirs)
		{
			int row = matrix.size();
			int col = matrix[0].size();

			if (is_valid(row, col, i + 1, j)) {
				if (matrix[i + 1][j] != 'X' && matrix[i + 1][j] != 'M')
					all_dirs.push_back((i + 1) * col + j);
			}
			if (is_valid(row, col, i - 1, j)) {
				if (matrix[i - 1][j] != 'X' && matrix[i - 1][j] != 'M')
					all_dirs.push_back((i - 1) * col + j);
			}
			if (is_valid(row, col, i, j + 1)) {
				if (matrix[i][j + 1] != 'X' && matrix[i][j + 1] != 'M')
					all_dirs.push_back(i * col + j + 1);
			}
			if (is_valid(row, col, i, j - 1)) {
				if (matrix[i][j - 1] != 'X' && matrix[i][j - 1] != 'M')
					all_dirs.push_back(i * col + j - 1);
			}
		}
};

int main(int argc, char **argv)
{
	vector <vector <char>> matrix = {
		{'O', 'M', 'O', 'O', 'X'},
		{'O', 'X', 'X', 'O', 'M'},
		{'O', 'O', 'O', 'O', 'O'},
		{'O', 'X', 'X', 'X', 'O'},
		{'O', 'O', 'M', 'O', 'O'},
		{'O', 'X', 'X', 'M', 'O'}
	};
	vector <vector <int>> result(matrix.size(), vector <int>(matrix[0].size(), -1));
	solution s;

	s.get_all_distance(matrix, result);
	for (auto &i : result) {
		for (auto &j : i)
			cout << j << ",";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
