#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct node {
	int x;
	int y;
	int dist;
	node (int a, int b, int c) : x(a), y(b), dist(c)
	{}
};

class mycompare {
	public:
		bool operator () (node &a, node &b)
		{
			return a.dist > b.dist;
		}

};

class solution_dijkstra {
public:
	int min_cost(vector <vector <int>> &matrix)
	{
		vector <vector <int>> cost(matrix.size(), vector <int>(matrix[0].size(), INT_MAX));
		int min_cst = INT_MAX;
		cost[0][0] = matrix[0][0];
		min_cst = dijkstra(matrix, 0, 0, cost);

		return min_cst;
	}

private:
	int dijkstra(vector <vector <int>> &matrix, int row,  int col, vector <vector <int>> &cost)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		priority_queue <node, vector <node>, mycompare> q;
		vector <vector <bool>> done(matrix.size(), vector <bool>(matrix[0].size(), false));

		q.push(node(row, col, matrix[row][col]));

		while(!q.empty()) {
			node v = q.top();
			q.pop();

			if (v.x == m - 1 && v.y == n - 1) {
				return v.dist;
			}

			if (v.x + 1 < m && !done[v.x + 1][v.y]) {
				if (v.dist + matrix[v.x + 1][v.y] < cost[v.x + 1][v.y]) {
					cost[v.x + 1][v.y] = v.dist + matrix[v.x + 1][v.y];
					q.push(node(v.x + 1, v.y, cost[v.x + 1][v.y]));
				}
			}

			if (v.y + 1 < n && !done[v.x][v.y + 1]) {
				if (v.dist + matrix[v.x][v.y + 1] < cost[v.x][v.y + 1]) {
					cost[v.x][v.y + 1] = v.dist + matrix[v.x][v.y + 1];
					q.push(node(v.x, v.y + 1, cost[v.x][v.y + 1]));
				}
			}

			done[v.x][v.y] = true;
		}
	}
};


class solution {
public:
	int min_cost(vector <vector <int>> &matrix, int m, int n)
	{
		//stop condition! return INT_MAX instead of 0, because we are
		//looking for min.
		if (m == 0 || n == 0)
			return INT_MAX;

		//start condiiton, can not use recursive on this one.
		if (m == 1 && n == 1)
			return matrix[0][0];

		return min(min_cost(matrix, m - 1, n), min_cost(matrix, m, n - 1)) + matrix[m - 1][n - 1];
	}

	int min_cost_bottom_up(vector <vector <int>> &matrix)
	{
		vector <vector <int>> cost(matrix.size(), vector <int>(matrix[0].size(), 0));

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (i - 1 >= 0 && j - 1 >= 0)
					cost[i][j] = min(cost[i - 1][j], cost[i][j - 1]);
				else if (i - 1 >= 0)
					cost[i][j] = cost[i - 1][j];
				else if (j - 1 >= 0)
					cost[i][j] = cost[i][j - 1];

				cost[i][j] += matrix[i][j];
			}
		}

		return cost[matrix.size() - 1][matrix[0].size() - 1];
	}
};


int main(int argc, char **argv)
{
	solution s;
	vector <vector <int>> matrix = {
		{4, 7, 8, 6, 4},
		{6, 7, 3, 9, 2},
		{3, 8, 1, 2, 4},
		{7, 1, 7, 3, 7},
		{2, 9, 8, 9, 3},
	};

	int cost = s.min_cost(matrix, matrix.size(), matrix[0].size());
	cout << cost << endl;
	cost = s.min_cost_bottom_up(matrix);
	cout << cost << endl;

	solution_dijkstra dijk;
	cost = dijk.min_cost(matrix);
	cout << "dijkstra solution result is " << cost << endl;

	exit(EXIT_SUCCESS);
}
