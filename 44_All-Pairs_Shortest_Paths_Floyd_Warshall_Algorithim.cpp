#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class solution {
	public:
		void floyd(vector <vector <int>> &adjacent, vector <vector <int>> &cost, vector <vector <int>> &cross)
		{
			int vertices = adjacent.size();
			for (int i = 0; i < vertices; i++)
				for (int j = 0; j < vertices; j++)
					if (adjacent[i][j] != INT_MAX)
						cross[i][j] = j;

			//for every edge [i][j] in the graph, iterate over all vertex k, to see a path though k can shorten the cost.
			for (int k = 0; k < vertices; k++) {
				for (int i = 0; i < vertices; i++) {
					for (int j = 0; j < vertices; j++) {
						if (cost[i][k] != INT_MAX && cost[k][j] != INT_MAX &&
								cost[i][j] > cost[i][k] + cost[k][j]) {
							cost[i][j] = cost[i][k] + cost[k][j];
							//this actually telling the essense of this algorithm, it only provide ONE shortest intermediate vertex between two vertices.
							//on the other hand, the result is a recursive one, i, k, j is the shortest path between i and j, while i, k', k is the shortest path between i and k...
							cross[i][j] = k;
						}
					}
					if (cost[i][i] < 0) {
						cout << "Negative Weight Cycle Found!!" << endl;
					}
				}
			}
		}
};

static void print_path(vector <vector <int>> &cross, int start, int end)
{
	//use recursive to print, from start vertex to end vertex,
	//if there's a vertex k other than end vertex make it shorter,
	//it must first cross the intermediate vertex k.
	//now if between the start and k, there's another node k' make it shorter,
	//we need to print the k' before k, thus the recursive.
	//the recurse stops when there's no k* vertex, means cross[i][j] == j
	if (cross[start][end] == end)
		return;
	print_path(cross, start, cross[start][end]);
	cout << cross[start][end] << ", ";
}

int main(int argc, char **argv)
{
	vector <vector <int>> adjacent = {
		{0, INT_MAX, -2, INT_MAX},
		{4, 0, 3, INT_MAX},
		{INT_MAX, INT_MAX, 0, 2},
		{INT_MAX, -1, INT_MAX, 0}
	};
	int vertices = adjacent.size();
	vector <vector <int>> cost = adjacent;
	vector <vector <int>> cross(vertices, vector <int>(vertices, -1));
	solution s;
	s.floyd(adjacent, cost, cross);

	cout << "after floyd algorithm" << endl;
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			cout << "distance from vertex " << i << " to " << j << " is " << cost[i][j] << endl;
			if (i != j && cross[i][j] != -1) { //there's a path from i to j
				cout << "shortest path from " << i << ", ";
				print_path(cross, i, j);
				cout <<  j << endl;
			}
		}
	}

	exit(EXIT_SUCCESS);
}
