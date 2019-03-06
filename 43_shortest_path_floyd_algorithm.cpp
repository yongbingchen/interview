#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct edge {
	int src;
	int dst;
	int weight;
};

class graph {
	public:
		graph(vector <edge> &edges, int vertices)
		{
			adjacent.resize(vertices);
			for (auto &e : edges) {
				adjacent[e.src].push_back(e);
			}
		}

		void shortest_path(vector <vector <int>> &cost)
		{
			int vertices = adjacent.size();
			for (auto &i : adjacent) {
				for (auto &j : i) {
					cost[j.src][j.dst] = j.weight;
				}
			}

			for (int i = 0; i < vertices; i++)
				cost[i][i] = 0;

			for (int k = 0; k < vertices; k++) {
				for (int i = 0; i < vertices; i++) {
					for (int j = 0; j < vertices; j++) {
						if (cost[i][k] != INT_MAX && cost[k][j] != INT_MAX)
							if (cost[i][k] + cost[k][j] < cost[i][j]) {
								cost[i][j] = cost[i][k] + cost[k][j];
							}
					}
				}
				if (cost[k][k] < 0) {
					cout << "loop in graph!" << endl;
					break;
				}
			}
		}

	private:
		vector <vector <edge>> adjacent;
};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{0, 6, 2}, {1, 2, -4}, {1, 4, 1}, {1, 6, 8}, {3, 0, 3}, {3, 4, 5},
		{5, 1, 2}, {7, 0, 6}, {7, 1, -1}, {7, 3, 4}, {7, 5, -4}
	};

	int vertices = 8;
	graph g(edges, vertices);
	vector <vector <int>> cost(vertices, vector <int>(vertices, INT_MAX));
	g.shortest_path(cost);
	for (auto &j : cost[7])
		cout << j << ", ";
	cout << endl;

	exit(EXIT_SUCCESS);
}
