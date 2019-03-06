#include <iostream>
#include <vector>

using namespace std;
/*
find all paths is a NP-hard problem.
a graph with loop has infinite paths.
with 'unique' restrcit, we can use dfs wth backtracking to achieve this, dfs will try all possible next from curr node, while backtring prohibit revisiting the node already in curr dfs tree,
and release this node for further consideration if curr dfs path hit dst or dead end, dfs tree "back" to higher lever of this visited node.
*/

/*
this problem can also be solved by DP, because it has optimal substructure and overlapping subproblems
https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/
Optimal Substructure: A given problems has Optimal Substructure Property if optimal solution of the given problem can be obtained by using optimal solutions of its subproblems.

For example, the Shortest Path problem has following optimal substructure property:
If a node x lies in the shortest path from a source node u to destination node v then the shortest path from u to v is combination of shortest path from u to x and shortest path from x to v. The standard All Pair Shortest Path algorithms like Floyd–Warshall and Bellman–Ford are typical examples of Dynamic Programming.

On the other hand, the Longest Path problem doesn’t have the Optimal Substructure property. Here by Longest Path we mean longest simple path (path without cycle) between two nodes. Consider the following unweighted graph given in the CLRS book. There are two longest paths from q to t: q→r→t and q→s→t. Unlike shortest paths, these longest paths do not have the optimal substructure property. For example, the longest path q→r→t is not a combination of longest path from q to r and longest path from r to t, because the longest path from q to r is q→s→t→r and the longest path from r to t is r→q→s→t.

1) Overlapping Subproblems:
Like Divide and Conquer, Dynamic Programming combines solutions to sub-problems. Dynamic Programming is mainly used when solutions of same subproblems are needed again and again. In dynamic programming, computed solutions to subproblems are stored in a table so that these don’t have to be recomputed. So Dynamic Programming is not useful when there are no common (overlapping) subproblems because there is no point storing the solutions if they are not needed again. For example, Binary Search doesn’t have common subproblems. If we take an example of following recursive program for Fibonacci Numbers, there are many subproblems which are solved again and again.
*/
class solution {
	public:
		int total_path(vector <vector <int>> &matrix, pair <int, int> &start, pair <int, int> &dst)
		{
			vector <vector <bool>> visited(matrix.size(), vector <bool>(matrix[0].size(), false));
			int total = 0;

			total_path(matrix, start, dst, total, visited);

			return total;
		}

	private:
		void total_path(vector <vector <int>> &matrix, pair <int, int> &start, pair <int, int> &dst, int &total, vector <vector <bool>> visited)
		{
			if (start.first == dst.first && start.second == dst.second) {
				total++;
				return;
			}

			visited[start.first][start.second] = true;

			vector <pair <int, int>> all_dirs;
			get_all_dirs(matrix, start, all_dirs, visited);
			for (auto &i : all_dirs)
				total_path(matrix, i, dst, total, visited);

			visited[start.first][start.second] = false;
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
	int ret = s.total_path(matrix, start, dst);
	cout << "total unique path from start (0, 0) to (5, 7) in matrix is " << ret << endl;

	exit(EXIT_SUCCESS);
}
