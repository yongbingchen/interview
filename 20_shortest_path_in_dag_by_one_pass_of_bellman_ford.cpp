#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct edge {
	int src;
	int dst;
	int weight;
};

class graph {
	public:
		graph(vector <edge> &edges, int v)
		{
			vertices = v;
			adjacent.resize(v);
			for (auto &e : edges)
				adjacent[e.src].push_back(e);
		}

		void shortest_path(vector <int> &cost, int start)
		{
			int dept = 0;
			vector <int> departure(vertices, -1);
			vector <bool> visited(vertices, false);
			topological_sort(start, dept, departure, visited);

			cost[start] = 0;
			for (auto it = departure.rbegin(); it != departure.rend() && *it != -1; it++) {
				for (auto &e : adjacent[*it]) {
					if (cost[*it] + e.weight < cost[e.dst])
						cost[e.dst] = cost[*it] + e.weight;
				}
			}
		}

	private:
		int vertices;
		vector <vector <edge>> adjacent;
		void topological_sort(int start, int &dept, vector <int> &departure, vector <bool> &visited)
		{
			visited[start] = true; //key to topological sort, one vertex only need one apperance in result.
			for (auto &e : adjacent[start]) {
				if (!visited[e.dst])
					topological_sort(e.dst, dept, departure, visited);
			}

			departure[dept] = start;
			dept++;
		}

};

int main(int argc, char **argv)
{
	vector <edge> edges = {
		{0, 6, 2}, {1, 2, -4}, {1, 4, 1}, {1, 6, 8}, {3, 0, 3}, {3, 4, 5},
		{5, 1, 2}, {7, 0, 6}, {7, 1, -1}, {7, 3, 4}, {7, 5, -4}
	};

	int vertices = 8;
	graph g(edges, vertices);
	for (int start = 7; start >= 0; start--) {
		vector <int> cost(vertices, INT_MAX);
		g.shortest_path(cost, start);
		cout << "when start from " << start << endl;
		for (auto &i : cost)
			cout << i << ", ";
		cout << endl;
	}

	exit(EXIT_SUCCESS);
}
